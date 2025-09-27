# gpg

## Basic: gpg key

* generate gpg key (Save in `~/.gnupg`)
  * `gpg --full-generate-key`: Recommended
  * `gpg --gen-key`
* Create revoke certificate
  * `gpg -o revoke.asc --gen-revoke <ID substring>`
* export
  * pub key: `gpg -ao mypub.asc --export <ID substring>`
  * priv key: `gpg -ao mypriv.asc --export-secret-keys <ID substring>`
* import
  * pub key: `gpg --import <mypub.asc>`
  * priv key: `gpg --import <mypriv.asc>`
* List all current key
  * pub key: `gpg --list-keys`
  * secret key: `gpg --list-secret-keys` or `gpg -K`
* Delete key (pub key can only be deleted while there's no priv key)
  * pub key: `gpg --delete-keys <ID substring>`
  * priv key: `gpg --delete-secret-keys <ID substring>`
* Backup (2 ways)
  * copy ~/.gnupg
  * export and then import key

## Cowork with others

* Search for other keys from the server
  * `gpg --search-keys <keyword>`
* Add other's pub key (Save in `~/.gnupg/pubring.gpg`)
  * `gpg --recv-keys <pub_key>`
* Update others key
  * `gpg --refresh-keys`
* import one key
  * `gpg --import <somebody.asc>`
* import many keys
  * `gpg --import import.txt`
* export all key list
  * `gpg --export -ao export.txt`

## Encrypt/Decrypt file

* Encrypt
  * `gpg -ear <other ID substring> < originfile > encrypt_file.asc`
* Decrypt
  * `gpg -d < encyrpt_file.asc > originfile`

## Digital Sign

* Sign: will generate originfile.asc
  * `gpg --clearsign <originfile>`
* Verify
  * `gpg --verify < originfile.asc`

## Used with GitHub

You can sign the commit with GPG keys

* [Adding a GPG key to your GitHub account](https://docs.github.com/en/authentication/managing-commit-signature-verification/adding-a-gpg-key-to-your-github-account)
* [Generating a new GPG key](https://docs.github.com/en/authentication/managing-commit-signature-verification/generating-a-new-gpg-key)
  * `gpg --full-generate-key`: Suggest using RSA 4096
  * `gpg --list-secret-keys --keyid-format=long`: List the keys with ID
  * `gpg --armor --export <ID>`: Copy the ID to GitHub
* [Signing commits](https://docs.github.com/en/authentication/managing-commit-signature-verification/signing-commits)
  * `git commit -S -s`: `-S` means GPG sing, while `-s` means sign-off

## GUI tool

* Kleopatra: For Linux platform

## Reference

* [[GnuPG] gpg 金鑰管理](http://pre.tir.tw/008/blog/output/gnupg-gpg-jin-yao-guan-li.html)
* [使用 GnuPG 建立你的 PGP 金鑰， 讓別人能夠私密寄信給你](https://newtoypia.blogspot.com/2013/12/gnupg-pgp.html)
