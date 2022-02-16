# FTP

We use pure-ftpd to setup our own FTP server.

# docker

* We can run the following commands for FTP server.
  - Note that you should change PUBLICHOST to your own IP.

```bash
# Create your FTP folder
mkdir ~/myftp
# Run docker
docker run --rm -d --name myftp_server \
  -p 10021:21 \
  -p 30010-30019:30010-30019 \
  -e "FTP_PASSIVE_PORTS=30010:30019" \
  -e "FTP_USER_NAME=myuser" \
  -e "FTP_USER_PASS=mypass" \
  -e "FTP_USER_HOME=/home/myuser" \
  -e "PUBLICHOST=172.30.80.167" \
  -v /home/$USER/myftp:/home/myuser \
  stilliard/pure-ftpd
```

* You can also use docker-compose
  - Create `docker-compose.yml`
  - Run `docker-compose up`
  - After finish, run `docker-compose down`

```
version: '3'

# Usage example: https://github.com/stilliard/docker-pure-ftpd/wiki/Docker-stack-with-Wordpress-&-FTP

services:
  ftpd_server:
    image: stilliard/pure-ftpd
    container_name: myftp_server
    ports:
      - "10021:21"
      - "30010-30019:30010-30019"
    volumes: # remember to replace /folder_on_disk/ with the path to where you want to store the files on the host machine
      - "/home/$USER/myftp:/home/myuser"
# uncomment for ssl/tls, see https://github.com/stilliard/docker-pure-ftpd#tls
#      - "/folder_on_disk/ssl:/etc/ssl/private/"
# or ssl/tls with Let's Encrypt (cert and key as two files)
#      - "/etc/letsencrypt/live/<your_server>/cert.pem:/etc/ssl/private/pure-ftpd-cert.pem"
#      - "/etc/letsencrypt/live/<your_server>/privkey.pem:/etc/ssl/private/pure-ftpd-key.pem"
    environment:
      PUBLICHOST: "172.30.80.167"
      FTP_USER_NAME: myuser
      FTP_USER_PASS: mypass
      FTP_USER_HOME: /home/myuser
      FTP_PASSIVE_PORTS: 30010:30019
# also for ssl/tls:
#      ADDED_FLAGS: "--tls=2"
    restart: always
```

* Then we can connect to FTP server with user:myuser/pass:mypass/port:10021.
