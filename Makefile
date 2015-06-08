all:	hello-thread

help:
	@echo Please read Makefile

hello-thread:	src/main.c
	$(CC) -o hello-thread $<

clean:
	rm -f hello-thread

# EOF
