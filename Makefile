#all:	help
all:	build-native build-target-arm

help:
	@echo Please read Makefile

hello-thread:	src/main.c
	$(CC) -o $@ $<

build-native:	hello-thread

sanity-checks:
	@if [ "$(ARCH)" = "" ]; then echo "Please define ARCH"; exit 1; fi
	@if [ "$(CROSS_COMPILE)" = "" ]; then echo "Please define CROSS_COMPILE"; exit 1; fi

build-target:	src/main.c
	$(MAKE) sanity-checks
	$(CROSS_COMPILE)$(CC) $(CFLAGS) -o hello-thread-$(ARCH) $<

build-target-arm:
	$(MAKE) ARCH=arm CC=gcc CFLAGS="-static" CROSS_COMPILE=arm-none-linux-gnueabi- build-target

clean:
	rm -f hello-thread hello-thread-arm

# EOF
