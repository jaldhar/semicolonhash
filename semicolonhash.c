/*
 * ;# -- a very simple esoteric programming language.
 *
 * By Jaldhar H. Vyas <jaldhar@braincells.com>
 * Copyright (C) 2017, Consolidated Braincells Inc. All rights reserved.
 * "Do what thou wilt" shall be the whole of the license.
 */

typedef unsigned long size_t;
typedef unsigned long ssize_t;

/* some syscalls so we don't need libc */

void sys_exit(int error) {
    __asm__ __volatile__ (
        "movq $60, %%rax;"  /* exit syscall = 60 */
        "syscall;"
        :
        : "D"(error)
        : "cc", "rcx", "r11", "memory"
    );
}

ssize_t sys_read(int fd, const void* buffer, size_t length) {
    int retval = 0;

    __asm__ __volatile__ (
        "movq $0, %%rax;"  /* read syscall = 0 */
        "syscall;"
        : "=a"(retval)
        : "D"(fd), "S"(buffer), "d"(length)
        : "cc", "rcx", "r11", "memory"
    );

    return retval;
}

ssize_t sys_write(int fd, const void* buffer, size_t length) {
    int retval = 0;

    __asm__ __volatile__ (
        "movq $1, %%rax;"  /* write syscall = 1 */
        "syscall;"
        : "=a"(retval)
        : "D"(fd), "S"(buffer), "d"(length)
        : "cc", "rcx", "r11", "memory"
    );

    return retval;
}

/* Because we are not linking with libc we can't use main() */
void _start() {
    unsigned char accumulator = 0;

    unsigned char c = 0;
    while (sys_read(0, &c, 1) > 0) {
        if (c == ';') {
            accumulator++;
        } else if (c == '#') {
            accumulator %= 127;
            sys_write(1, &accumulator, 1);
            accumulator = 0;
        }
        /* Ignore all other characters */
    }

    sys_exit(0);
}

