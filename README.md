# ;# interpreter

## Intro

This is an interpreter for a very simple esoteric programming language whose
description I came across at [this stackexchange entry](https://codegolf.stackexchange.com/questions/121921/make-a-interpreter.).

While the original link goes to a competion to get the smallest possible
source code, I wanted to see how small I could make the executable while still
primarily remaining in C. (The syscalls do use inline asm.)  I got to 1064
bytes but I think it might be possible to get smaller yet.  I welcome any
patches.

The downside is that this code is not portable; it will probably only work on
x86_64 Linux.  In any case it has only been tested on that platform.

## About ;#

The ;# (pronounced "Semicolon Hash") language only has two commands:

* ; add one to the accumulator
* &#35; modulo the accumulator by 127, convert to ASCII character and output without
  a newline. After this, reset the accumulator to 0. Yes, 127 is correct.

This interpreter reads from standard input and writes to standard output.

## Examples

There are some sample programs included:

* helloworld - the perennial first program
* exclamation - prints an exclamation mark.
* fizzbuzz - does fizzbuzz from 1 to 100.


## Copyright/License

By Jaldhar H. Vyas <jaldhar@braincells.com>

Copyright (C) 2017, Consolidated Braincells Inc. All rights reserved.

"Do what thou wilt" shall be the whole of the license.
   
