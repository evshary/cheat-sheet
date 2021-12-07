# TPM

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
* Install TPM tools
```bash
sudo apt install tpm2-tools
```
* Self test
```bash
sudo tpm2_selftest
# Full test
sudo tpm2_selftest -f
```

# tpm-tools usage

Refer to [the official website of tpm2-tools](https://tpm2-tools.readthedocs.io/en/latest/)

# Reference

* [用 TPM 晶片登入 SSH](https://blog.libralight.dev/tpm2-ssh-key/)
* [TPM自我測試與系統測試的澄清](https://www.wpgdadatong.com/tw/blog/detail?BID=B0160)
