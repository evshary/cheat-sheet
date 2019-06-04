UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
# Put the path after install
SSL_PATH=/usr/local/Cellar/openssl@1.1/1.1.1c/
CFLAGS=-I$(SSL_PATH)include -L$(SSL_PATH)lib/ 
endif

CFLAGS+=-lcrypto -lssl
CC=gcc

all: ssl

ssl: ssl_server.out ssl_client.out
ssl_server.out: ssl_server.c
	$(CC) $^ -o $@ $(CFLAGS)
ssl_client.out: ssl_client.c
	$(CC) $^ -o $@ $(CFLAGS)


ssl_client: ssl_client.c
	$(CC) $^ -o $@.out $(CFLAGS)

clean:
	-rm *.out
