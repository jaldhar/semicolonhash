/*
 * ;# -- a very simple esoteric programming language.
 *
 * By Jaldhar H. Vyas <jaldhar@braincells.com>
 * Copyright (C) 2017, Consolidated Braincells Inc. All rights reserved.
 * "Do what thou wilt" shall be the whole of the license.
 */

#include "sys.h"

/* Because we are not linking with libc we can't use main() */
void _start() {
    unsigned char accumulator = 0;

    unsigned char c = 0;

    while (sys_read(stdin, &c, 1) > 0) {
        if (c == ';') {
            accumulator++;
        } else if (c == '#') {
            accumulator %= 127;
            sys_write(stdout, &accumulator, 1);
            accumulator = 0;
        }
        /* Ignore all other characters */

    }

    sys_exit(0);
}

