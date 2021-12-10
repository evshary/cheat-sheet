# TPM (Trusted Platform Module)

TPM is the cheap which has interface TCTI defined by TCG(Trusted Computing Group).
No matter key generation/storage, encryption/decrytion are done in TPM.

Since the key doesn't exist in memory, it'll be much safer.

If your application support PCKS #11, which is the API to communicate with hardware password, then you can use TPM.

If you want to know more about TPM software, refer to [tpm2-software community](https://tpm2-software.github.io/)

# Install packages

* Check whether tpm exist in your host
```bash
ls /dev/tpm*
```
* Check the TPM's version
```bash
dmesg | grep -i tpm
```
* Install TPM packages
  - Note that only work in Ubuntu 21.04
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

Refer to [the official website of tpm2-tools](https://tpm2-tools.readthedocs.io/en/latest/)

* Get random 8 bytes from the TPM: `sudo tpm2_getrandom 8 | xxd -p`
* List PCR in TPM: `sudo tpm2_pcrread`
  - Only list certain PCR (e.g. sha256:0): `sudo tpm2_pcrread sha256:0`
  - The meaning of the number can refer to [here](https://link.springer.com/chapter/10.1007/978-1-4302-6584-9_12#Tab1)

# Use TPM to SSH

Refer to [用 TPM 晶片登入 SSH](https://blog.libralight.dev/tpm2-ssh-key/)

* Init database and create slot for keys
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

# Reference

* [可信計算基礎](https://www.slideserve.com/sadie/2222582): **Really good resource** to realize the architecture of TPM and how it works.
* [TPM自我測試與系統測試的澄清](https://www.wpgdadatong.com/tw/blog/detail?BID=B0160)
* [對TCG的概要分析和對TPM的學習-可信存儲根RTS（三）](https://www.twblogs.net/a/5e5518f4bd9eee2117c5bdee): Explain keys in TPM
