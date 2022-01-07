LINUXDIR ?= /lib/modules/$(shell uname -r)/build

obj-m := dummy.o

all:
	make -C $(LINUXDIR) M=$(shell pwd)

clean:
	make -C $(LINUXDIR) M=$(shell pwd) clean
