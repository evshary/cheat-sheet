# Basic: gpg key

* generate gpg key (Save in `~/.gnupg`)
  - `gpg --gen-key`
* Create revoke certificate
  - `gpg -o revoke.asc --gen-revoke <ID substring>`
* export
  - pub key: `gpg -ao mypub.asc --export <ID substring>`
  - priv key: `gpg -ao mypriv.asc --export-secret-keys <ID substring>`
* import
  - pub key: gpg --import <mypub.asc>
  - priv key: gpg --import <mypriv.asc>
* List all current key
  - pub key: `gpg --list-keys`
  - secret key: `gpg --list-secret-keys`
* Delete key (pub key can only be deleted while there's no priv key)
  - pub key: `gpg --delete-keys <ID substring>`
  - priv key: `gpg --delete-secret-keys <ID substring>`
* Backup
  - copy ~/.gnupg
  - export and then import key

# Cowork with others

* Search other key
  - `gpg --search-keys <keyword>`
* Add other's pub key (Save in `~/.gnupg/pubring.gpg`)
  - `gpg --recv-keys <pub_key>`
* Update others key
  - `gpg --refresh-keys`
* import one key
  - `gpg --import <somebody.asc>`
* import many keys
  - `gpg --import import.txt`
* export all key list
  - `gpg --export -ao export.txt`

# Encrypt/Decrypt file

* Encrypt
  - `gpg -ear <other ID substring> < originfile > encrypt_file.asc`
* Decrypt
  - `gpg -d < encyrpt_file.asc > originfile`

# Digital Sign

* Sign: will generate originfile.asc
  - `gpg --clearsign <originfile>`
* Verify
  - `gpg --verify < originfile.asc`

# Reference

* [[GnuPG] gpg 金鑰管理](http://pre.tir.tw/008/blog/output/gnupg-gpg-jin-yao-guan-li.html)
* [使用 GnuPG 建立你的 PGP 金鑰， 讓別人能夠私密寄信給你](https://newtoypia.blogspot.com/2013/12/gnupg-pgp.html)
