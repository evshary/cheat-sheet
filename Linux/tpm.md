# TPM (Trusted Platform Module)

TPM is the chip which has interface TCTI defined by TCG(Trusted Computing Group).

Goal:
* Key generation/storage: much safer because key doesn't exist in memory (encryption/decryption are done in TPM)
* Random number generation: Much more random
* Secure boot: Ensure the integrity of boot process. Refer to detail [here](https://www.twblogs.net/a/5e5518f4bd9eee2116847267).

If your application support PCKS #11, which is the API to communicate with hardware password, then you can use TPM.

If you want to know more about TPM software (tpm2-tools), refer to [tpm2-software community](https://tpm2-software.github.io/)

The tools can has several functions:

* NV tools: store data in NV
* Attestation tools: prove software identity
* Key management tools: manage key
* Encryption/Decryption tools: encrypt / decrypt
* Signing tools: sign the data
* utilities: create random number, hash...

**NOTE: tpm2-tools is always changin its commands and argument, so the data might be out-dated after few years ago.....**

# TPM architecture
![image](https://user-images.githubusercontent.com/456210/145745734-59d77c5e-baa8-4559-aee7-1c2486331ee2.png)
[image source](https://blog.fpmurphy.com/2016/02/accessing-tpm-functionality-from-uefi-shell-part-1.html)

# Install packages

* Check whether tpm exist in your host
```bash
ls /dev/tpm*
```
* Check the TPM's version
```bash
dmesg | grep -i tpm
# Another way
cat /sys/class/tpm/tpm0/device/firmware_node/description
```
* Run TPM in docker (optional)
  - Since some TPM tool needs Ubuntu 21.04, you need to use docker to run
```bash
docker run --rm -it -v /dev:/dev -v /sys:/sys -v /var/run/dbus/system_bus_socket:/var/run/dbus/system_bus_socket --privileged ubuntu:21.04
```
* Install TPM packages
  - The following packages only work in Ubuntu 21.04
  - If you don't have /dev/tpmrm0, it means that your kernel is < 4.14 and need to install Access Broker and Resource Manager Daemon (ABRMD). ABRMD / /dev/tpmrm0 can help multiple application access /dev/tpm0 at the same time.
```bash
sudo apt install libtpm2-pkcs11-1 libtpm2-pkcs11-tools
```
* Self test
```bash
sudo tpm2_selftest
# Full test
sudo tpm2_selftest -f
```

# tpm-tools usage

Refer to [the manual of TPM](https://github.com/tpm2-software/tpm2-tools/tree/master/man)

How to use tpm-tools [example](https://blog.csdn.net/jianming21/article/details/108042271)

* Manage Access
```bash
# 3 kinds of password: owner, endorsement, lockout
# Set new password
tpm2_changeauth -c owner <pass>
tpm2_changeauth -c endorsement <pass>
tpm2_changeauth -c lockout <pass>
# Update password
tpm2_changeauth -c o -p <pass> <newpass>
tpm2_changeauth -c e -p <pass> <newpass>
tpm2_changeauth -c l -p <pass> <newpass>
# Set the password to empty
tpm2)changeauth -c o -p <pass>
# If you forget the password, reset TPM
echo 5 > /sys/class/tpm/tpm0/ppi/request
reboot
```
* Get the capabilities of TPM
```bash
# Supported commands
tpm2_getcap commands
# fixed TPM properties
tpm2_getcap properties-fixed
```
* Test whether the algorithm is supported by TPM
```bash
# specifier:  type
tpm2_testparms rsa4096
# specifier:  type:scheme:symmetric-details
tpm2_testparms ecc256:ecdsa:aes128ctr
# Show result:
# 0: success, 1-4: different errors, 5: not supported
echo $?
```
* Get random 8 bytes from the TPM: `sudo tpm2_getrandom 8 | xxd -p`
* PCR operation
  - The meaning of the different PCR number can refer to [here](https://link.springer.com/chapter/10.1007/978-1-4302-6584-9_12#Tab1)
```bash
# List all PCR in TPM
tpm2_pcrread
# Only list certain PCR (e.g. sha256:0)
tpm2_pcrread sha256:0
# Extend PCR
tpm2_pcrextend 4:sha1=f1d2d2f924e986ac86fdf7b36c94bcdf32beec15
```
* Create primary key
```bash
# Create primary object
# -C: o(owner), p(platform), e(endorsement), n(null)
# -g: hash algorithm
# -G: how to generate key, e.g. rsa2048:null:aes128cfb, ecc
# -c: context output path
tpm2_createprimary -C o -g sha256 -G ecc -c primary.ctx
# Simpler
tpm2_createprimary -c primary.ctx
```
* Create child object, which can be key or sealed object
```bash
tpm2_create -C primary.ctx -u key.pub -r key.priv
# Use different algorithm, e.g. rsa2048
tpm2_create -C primary.ctx -Grsa2048 -u key.pub -r key.priv
```
* Load public/private key into TPM
```bash
tpm2_load -C primary.ctx -u key.pub -r key.priv -c key.ctx
```
* encrypt/decrypt (RSA)
  - Note that you need to use rsa2048 in tpm2_create
```bash
echo "plaintext message" > msg.dat
# encrypt
tpm2_rsaencrypt -c key.ctx -o msg.enc msg.dat
# decrypt
tpm2_rsadecrypt -c key.ctx -o msg.ptext msg.enc
cat msg.ptext
```
* Sign
```bash
# Sign the data
tpm2_sign -c key.ctx -g sha256 -o sig.rssa msg.dat
# Verify signature
tpm2_verifysignature -c key.ctx -g sha256 -s sig.rssa -m msg.dat
```
* Seal & Unseal data
```bash
# We can seal data into TPM while running tpm2_create (at most 128 bytes)
echo "This is sealed data" > seal.dat
tpm2_create -C primary.ctx -u key.pub -r key.priv -i seal.dat

# Load the context
tpm2_load -C primary.ctx -u key.pub -r key.priv -c key.ctx

# evict a persistent handle (Note that the handles will exist after reboot)
# Output:
# persistent-handle: 0x81000000
# action: persisted
tpm2_evictcontrol -C o -c key.ctx   # Same as `tpm2_evictcontrol --hierarchy=o --object-context=key.ctx`
# Remove key from TPM
tpm2_evictcontrol -C o -c 0x81000000

# List and read persistent handler
tpm2_getcap handles-persistent
tpm2_readpublic -c 0x81000000

# Unseal data from TPM
tpm2_unseal -c 0x81000000   # `tpm2_unseal --object-context=0x81000000`
```
* TPM read/write data stored in a Non-Volatile (NV)s index
```bash
tpm2_nvdefine -C o -s 32 -a "ownerread|policywrite|ownerwrite" 1
echo "please123abc" > nv.dat
tpm2_nvwrite -C o -i nv.dat 1
tpm2_nvread -C o -s 32 1
```
* hash
```bash
tpm2_hash -g sha1 -o hash.bin -t ticket.bin data.txt
```

# Use TPM to SSH

Refer to [用 TPM 晶片登入 SSH](https://blog.libralight.dev/tpm2-ssh-key/) and [Protecting authentication keys with a TPM 2.0](https://www.barbhack.fr/slides/2021/barbhack2021_tpm_auth.pdf)

* Init database and create slot for keys
  - The key is stored under the database `$HOME/.tpm2_pkcs11/tpm2_pkcs11.sqlite3`
  - The key is encrypted by Storage Root Key (SRK)
```bash
tpm2_ptool init
```
* Create token
  - pid should be the same as you run `tpm2_ptool init`
  - sopin: Security Officier PIN (Used for recovery)
  - userpin: The PIN number to access TPM
  - label: Your label name
```bash
tpm2_ptool addtoken --pid=1 --sopin=mysopin --userpin=myuserpin --label=mylabel
```
* Create key
  - label: Should be the same as you've created
  - algorithm: The encryption algorithm, which should be supported by your TPM
  - userpin: The PIN number you set
  - key-lable: The label name of your key
```bash
tpm2_ptool addkey --label=mylabel --algorithm=ecc256 --userpin=myuserpin --key-label=mykeylabel
```
* Get the public key
```bash
ssh-keygen -D /usr/lib/x86_64-linux-gnu/libtpm2_pkcs11.so.1
```
* Use the key to build SSH connection
```bash
ssh -I /usr/lib/x86_64-linux-gnu/libtpm2_pkcs11.so.1 [username]@[server_name]
```

# Infineon Embedded Linux TPM Toolbox 2

Besides standard TPM tools, you can use the tools provide by other TPM vendor, for example, Infineon.

* Build

```bash
git clone https://github.com/Infineon/eltt2
cd eltt2
make
```

* Run

```bash
# Full test
./eltt2 -t full
# Get properties
./eltt2 -g
# Generate random number (8 bytes)
./eltt2 -G 8
# Hash ABCD with SHA-256
./eltt2 -S 41424344
```

# TPM simulator
If you don't have TPM hardware, you can use [IBM's Software TPM 2.0](https://sourceforge.net/projects/ibmswtpm2/).

Refer to [How to setup TPM-simulator in Ubuntu 20.04](https://francislampayan.medium.com/how-to-setup-tpm-simulator-in-ubuntu-20-04-25ec673b88dc) for how to use TPM simulator.

# Reference

* [可信計算基礎](https://www.slideserve.com/sadie/2222582): **Really good resource** to realize the architecture of TPM and how it works.
* [I'M JAY'S FATHER - TRUSTED PLATFORM MODULE (TPM)](http://junyelee.blogspot.com/2020/11/a-practical-guide-to-tpm-2.html): How to use TPM pratically
* [對TCG的概要分析和對TPM的學習-可信存儲根RTS（三）](https://www.twblogs.net/a/5e5518f4bd9eee2117c5bdee): Explain keys in TPM
* [Documentation for TPM specification](https://trustedcomputinggroup.org/resources?): The standard of TPM.
* [TPM自我測試與系統測試的澄清](https://www.wpgdadatong.com/tw/blog/detail?BID=B0160): Test criteria of TPM
* [A Technical Introduction to the Use of Trusted Platform Module 2.0 with Linux](https://lenovopress.com/lp0599.pdf): TPM usage provided by Lenovo. Although its commands are out-dated, it's valuable to learn the basic knowledge of TPM.
* [A Practical Guide to TPM 2.0](https://link.springer.com/book/10.1007/978-1-4302-6584-9): The book which describes the detail of TPM.
  - [中文版：TPM 2.0 原理及應用指南新安全時代的可信平臺模塊](https://github.com/leeehui/a-practical-guide-to-tpm2-book-cn)
