UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
# Put the path after install
SSL_PATH=/usr/local/Cellar/openssl@1.1/1.1.1c/
CFLAGS=-I$(SSL_PATH)include -L$(SSL_PATH)lib/ 
endif

CFLAGS+=-lcrypto -lssl
CC=gcc

all: ssl bio chkcert

ssl: ssl_server.out ssl_client.out
ssl_server.out: ssl_server.c
	$(CC) $^ -o $@ $(CFLAGS)
ssl_client.out: ssl_client.c
	$(CC) $^ -o $@ $(CFLAGS)

bio: bio_server.out bio_client.out
bio_server.out: bio_server.c
	$(CC) $^ -o $@ $(CFLAGS)
bio_client.out: bio_client.c
	$(CC) $^ -o $@ $(CFLAGS)

chkcert: server_with_chkcert.out client_with_chkcert.out
server_with_chkcert.out: server_with_chkcert.c
	$(CC) $^ -o $@ $(CFLAGS)
client_with_chkcert.out: client_with_chkcert.c
	$(CC) $^ -o $@ $(CFLAGS)

clean:
	-rm *.out
