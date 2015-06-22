all:	help

help:
	@echo Please read Makefile

build-native:	hello-thread

build-target-arm:
	$(MAKE) ARCH=arm CROSS_COMPILE="arm-none-linux-gnueabi-" CC="gcc" CFLAGS="-static" LDFLAGS="-pthread" build-target

# -----------------------------------------------------------

hello-thread:	src/main.c
	$(CC) -o $@ -pthread $<

sanity-checks:
	@if [ "$(ARCH)" = "" ]; then echo "Please define ARCH"; exit 1; fi
	@if [ "$(CROSS_COMPILE)" = "" ]; then echo "Please define CROSS_COMPILE"; exit 1; fi

build-target:	src/main.c
	$(MAKE) sanity-checks
	$(CROSS_COMPILE)$(CC) $(CFLAGS) -o hello-thread-$(ARCH) $(LDFLAGS) $<

clean:
	rm -f hello-thread hello-thread-arm

# EOF
