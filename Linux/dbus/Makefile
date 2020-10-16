all: server client

%: %.c
	gcc $(shell pkg-config --cflags dbus-1) -o $@ $< $(shell pkg-config --libs dbus-1)
