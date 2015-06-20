CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c99 -D_BSD_SOURCE

.PHONY: clean

all: pack_intel unpack_intel

clean:
	rm -f *.o pack_intel unpack_intel pack_intel.exe unpack_intel.exe

pack_intel: pack.o
	$(CC) -o $@ $< $(CFLAGS)

unpack_intel: unpack.o
	$(CC) -o $@ $< $(CFLAGS)
