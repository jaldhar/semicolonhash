#
# sys.s -- Call into syscalls so we don't need libc
#
# By Jaldhar H. Vyas <jaldhar@braincells.com>
# Copyright (C) 2017, Consolidated Braincells Inc. All rights reserved.
# "Do what thou wilt" shall be the whole of the license.
#

    .global sys_exit
    .global sys_read
    .global sys_write
    .global errno

    .text
sys_exit:
    movq $60, %rax  # exit syscall = 60
    syscall
    ret

sys_read:
    movq $0, %rax   # read syscall = 0
    syscall
    test %rax, %rax
    js error
    ret

sys_write:
    movq $1, %rax   # write syscall = 1
    syscall
    test %rax, %rax
    js error
    ret

error:
    neg %rax
    mov %rax, errno
    sbb %rax, %rax
    ret

    .bss
errno: .INT 0
