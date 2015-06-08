#all:	help
all:	build-native build-target-arm

help:
	@echo Please read Makefile

hello-thread:	src/main.c
	$(CC) -o $@ $<

build-target:	src/main.c
	$(CROSS_COMPILE)$(CC) $(CFLAGS) -o hello-thread-$(ARCH) $<

build-native:	hello-thread

build-target-arm:
	$(MAKE) ARCH=arm CC=gcc CFLAGS="-static" CROSS_COMPILE=arm-none-linux-gnueabi- build-target

clean:
	rm -f hello-thread hello-thread-arm

# EOF
