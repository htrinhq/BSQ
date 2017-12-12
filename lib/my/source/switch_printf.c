/*
** EPITECH PROJECT, 2017
** switch_printf.c
** File description:
** switch of my_printf
*/

#include "stdyo.h"

void printfswitchsec(const char *format, int *x, va_list list)
{
	switch (format[*x]) {
		case 'x':
			bighexaconvert(va_arg(list, unsigned int));
			break;
		case '#':
			*x = *x + 1;
			dieseswitch(format, x, list);
			break;
		case 'l':
			*x = *x + 1;
			longswitch(format, x, list);
			break;
		case 'h':
			*x = *x + 1;
			shortswitch(format, x, list);
			break;
	}
}

void printfswitchone(const char *format, int *x, va_list list)
{
	switch (format[*x]) {
		case 'u':
			my_unsigned_putnbr(va_arg(list, unsigned int));
			break;
		case 'o':
			octalconvert(va_arg(list, unsigned int));
			break;
		case 'b':
			binaryconvert(va_arg(list, unsigned int));
			break;
		case 'X':
			hexaconvert(va_arg(list, unsigned int));
			break;
		default:
			printfswitchsec(format, x, list);
			break;
	}
}

void my_printf_switch(const char *format, int *x, va_list list)
{
	switch (format[*x]) {
		case 's':
			my_putstr(va_arg(list, char*));
			break;
		case 'd':
		case 'i':
			my_put_nbr(va_arg(list, int));
			break;
		case 'c':
			my_putchar(va_arg(list, int));
			break;
		case '%':
			my_putchar('%');
			break;
		default:
			printfswitchone(format, x, list);
			break;
	}
}
