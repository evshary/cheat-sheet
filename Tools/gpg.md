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
* List my current key
  - `gpg --list-secret-keys`
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

## Digital Sign

* Sign: will generate originfile.asc
  - `gpg --clearsign <originfile>`
* Verify
  - `gpg --verify < originfile.asc`
