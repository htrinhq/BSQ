/*
** EPITECH PROJECT, 2017
** longshortswitch.c
** File description:
** long and short switches and diese switch
*/

#include "stdyo.h"
#include <stdlib.h>
#include <stdarg.h>

void dieseswitch (const char *format, int *x, va_list list)
{
	switch (format[*x]) {
	case 'o':
		my_putchar('0');
		octalconvert(va_arg(list, unsigned int));
		break;
	case 'x':
		my_putstr("0x");
		bighexaconvert(va_arg(list, unsigned int));
		break;
	case 'X':
		my_putstr("0X");
		hexaconvert(va_arg(list, unsigned int));
		break;
	}
}

void longlongswitch(const char *format, int *x, va_list list)
{
	switch (format[*x]) {
	case 'd':
	case 'i':
		my_longlong_putnbr(va_arg(list, long long));
		break;
	case 'u':
		my_ulonglong_putnbr(va_arg(list, unsigned long long));
		break;
	}
}

void longswitch(const char *format, int *x, va_list list)
{
	switch (format[*x]) {
	case 'd':
	case 'i':
		my_long_putnbr(va_arg(list, long));
		break;
	case 'u':
		my_ulong_putnbr(va_arg(list, unsigned long));
		break;
	case 'l':
		*x = *x + 1;
		longlongswitch(format, x, list);
		break;
	}
}

void shortswitch(const char *format, int *x, va_list list)
{
	switch (format[*x]) {
	case 'd':
	case 'i':
		my_short_putnbr(va_arg(list, int));
		break;
	case 'u':
		my_ushort_putnbr(va_arg(list, unsigned int));
		break;
	case 'h':
		*x = *x + 1;
		shortshortswitch(format, x, list);
		break;
	}
}

void shortshortswitch(const char *format, int *x, va_list list)
{
	switch (format[*x]) {
	case 'd':
	case 'i':
		my_put_nbr(va_arg(list, int));
		break;
	case 'u':
		my_put_nbr(va_arg(list, unsigned int));
		break;
	}
}
