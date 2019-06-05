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
openssl req -new -x509 -days 3650 -subj "/C=TW/ST=Taiwan/L=Taipei/O=CACompanyInc/CN=CACompany.com" -key ca.key -out ca.crt
# Create server CSR
openssl genrsa -out server.key 2048
openssl req -new -subj "/C=TW/ST=Taiwan/L=Tainan/O=CompanyInc/CN=127.0.0.1" -key server.key -out server.csr
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

# Connection
## Normal connection
* Server
```
# Open port at 8080 with private key server.key and cert server.crt
openssl s_server -accept 8080 -key server.key -cert server.crt
```
* Client
```
# Connect to server 127.0.0.1:8080
openssl s_client -connect 127.0.0.1:8080
# Connection detail
openssl s_client -msg -connect 127.0.0.1:8080
# Designated cipher
openssl s_client -connect 127.0.0.1:8080 -cipher ECDHE-RSA-AES128-GCM-SHA256 -curves secp384r1 -sigals RSA+SHA512
# Limit connection with TLS1.2
openssl s_client -no_tls1 -no_ssl3 -connect 127.0.0.1:8080
```
* List all ciphers
```
openssl ciphers ALL
```
## Connection with server certificate authentication
* Server
```
# The server.crt should be signed with ca.key
openssl s_server -accept 8080 -key server.key -cert server.crt
```
* Client
```
# -CAfile means we should trust ca.crt
openssl s_client -connect 127.0.0.1:8080 -CAfile ca.crt
```
## Connection with client certificate authentication
* Server
```
# Include ca.crt to verify client certificate, -Verify means client needs client certificate
openssl s_server -accept 8080 -key server.key -cert server.crt -CAfile ca.crt -Verify 10
```
* Client
```
# Client should have its own key and certificate
openssl s_client -connect 127.0.0.1:8080 -key client.key -cert client.crt
```
## Connection with both certificate authentication
* Server
```
# The ca.crt here should be used to sign client.crt
openssl s_server -accept 8080 -key server.key -cert server.crt -CAfile ca.crt -Verify 10
```
* Client
```
# The ca.crt here should be used to sign server.crt
openssl s_client -connect 127.0.0.1:8080 -key client.key -cert client.crt -CAfile ca.crt
```

# Documentation
Refer to [OpenSSL official documentation](https://www.openssl.org/docs/manmaster/man3/) for more function usage.