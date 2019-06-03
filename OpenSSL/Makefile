UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
# Put the path after install
SSL_PATH=/usr/local/Cellar/openssl@1.1/1.1.1c/
CFLAGS=-I$(SSL_PATH)include -L$(SSL_PATH)lib/ 
endif

CFLAGS+=-lcrypto -lssl
CC=gcc
BIN=ssl_server ssl_client

all: $(BIN)

ssl_server: ssl_server.c
	$(CC) $^ -o $@.out $(CFLAGS)

ssl_client: ssl_client.c
	$(CC) $^ -o $@.out $(CFLAGS)

clean:
	-rm *.out
