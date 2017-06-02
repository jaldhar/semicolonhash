# ;# -- a very simple esoteric programming language.
#
# By Jaldhar H. Vyas <jaldhar@braincells.com>
# Copyright (C) 2017, Consolidated Braincells Inc. All rights reserved.
# "Do what thou wilt" shall be the whole of the license.

AS=as
CC=cc
CFLAGS=-std=c99 -Os -g -Wall -Wextra -fno-stack-protector
LDFLAGS=-static -nostartfiles -nodefaultlibs
PROGRAM=semicolonhash
OBJECTS=semicolonhash.o \
    sys.o

.POSIX:

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $^

.s.o:
	$(AS) -c -o $@ $^

all: $(PROGRAM) strip

$(PROGRAM): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

strip: $(PROGRAM)
	strip --strip-all $(PROGRAM)

clean:
	-rm $(PROGRAM) *.o
