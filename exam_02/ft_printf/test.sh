#!/bin/sh

gcc -Werror -Wextra -Wall ft_printf.c main.c
./a.out
rm a.out
