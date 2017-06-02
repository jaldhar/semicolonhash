/*
 * sys.h: interfaces to some syscalls so we don't need libc
 *
 * By Jaldhar H. Vyas <jaldhar@braincells.com>
 * Copyright (C) 2017, Consolidated Braincells Inc. All rights reserved.
 * "Do what thou wilt" shall be the whole of the license.
 */

#ifndef __SYS_H__
#define __SYS_H__

typedef unsigned long size_t;
typedef unsigned long ssize_t;

#define stdin 0
#define stdout 1

extern int errno;

void    sys_exit(int error);
ssize_t sys_read(int fd, const void* buffer, size_t length);
ssize_t sys_write(int fd, const void* buffer, size_t length);

#endif
