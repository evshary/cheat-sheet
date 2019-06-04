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

# Certificate
## RSA self-signed certificate
```
# Generate RSA key with length 2048 bits
openssl genrsa -out server.key 2048
# Generate CSR with key and sign CSR with sha384
openssl req -new -sha384 -key server.key -out server.csr
# Generate the self-signed certificate
openssl x509 -req -sha1 -days 3650 -signkey server.key -in server.csr -out server.crt
```
## ECC self-signed certificate
```
# Generate ECC key
openssl ecparam -genkey -name secp384r1 -out ecc.key
# Generate CSR with key and sign CSR with sha384
openssl req -new -sha384 -key ecc.key -out ecc.csr
# Generate the self-signed certificate
openssl x509 -req -sha1 -days 3650 -signkey ecc.key -in ecc.csr -out ecc.crt
```
## Generate certificate with cnf
* Create config.cnf file
```
[req]
prompt = no
distinguished_name = req_1
[req_1]
C = TW
ST = Taiwan
L = Taipei
O = Company Inc.
OU = SW Department
CN = 127.0.0.1
```
* Create certificate
```
openssl genrsa -out server.key 2048
openssl req -new -sha384 -config config.cnf -key server.key -out server.csr
openssl x509 -req -sha1 -days 3650 -signkey server.key -in server.csr -out server.crt
```
## Create CA and sign the certificate
```
# CA
openssl genrsa -out ca.key 4096
openssl req -new -x509 -days 3650 -subj "/C=TW/ST=Taiwan/L=Taipei/O=CompanyInc/CN=127.0.0.1" -key ca.key -out ca.crt
# Create server CSR
openssl genrsa -out server.key 2048
openssl req -new -subj "/C=TW/ST=Taiwan/L=Taipei/O=CompanyInc/CN=127.0.0.1" -key server.key -out server.csr
# Sign server.csr and get server.crt
openssl x509 -req -days 3650 -CA ca.crt -CAkey ca.key -set_serial 02 -in server.csr -out server.crt
```
## Show info
```
# Show the info of private key
openssl rsa -text -in server.key # RSA
openssl ec -text -in ecc.key     # ECC
# Show the info of CSR
openssl req -in server.csr -noout -text
# Show the info of certificate
openssl x509 -text -noout -in server.crt
```

# Documentation
Refer to [OpenSSL official documentation](https://www.openssl.org/docs/manmaster/man3/) for more function usage.