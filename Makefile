# ;# -- a very simple esoteric programming language.
#
# By Jaldhar H. Vyas <jaldhar@braincells.com>
# Copyright (C) 2017, Consolidated Braincells Inc. All rights reserved.
# "Do what thou wilt" shall be the whole of the license.

CC=cc
CFLAGS=-std=c99 -Os -g -Wall -Wextra -fno-stack-protector
LDFLAGS=-static -nostdlib
PROGRAM=semicolonhash
OBJECTS=semicolonhash.o

.POSIX:

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $^

all: $(PROGRAM) strip

$(PROGRAM): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $<

strip: $(PROGRAM)
	strip --strip-all $(PROGRAM)

clean:
	-rm $(PROGRAM) *.o
