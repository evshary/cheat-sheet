# Install
* Ubuntu
```sh
sudo apt-get install libssl-dev
```
* MAC
```sh
brew install openssl
# find the following two paths and put into the Makefile
# find the library path
find /usr/local/Cellar/ -name "libssl.*"
# find the include file path
find /usr/local/Cellar/ -name "ssl.h"
```

# Documentation
Refer to [OpenSSL official documentation](https://www.openssl.org/docs/manmaster/man3/) for more function usage.