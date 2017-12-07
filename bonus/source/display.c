/*
** EPITECH PROJECT, 2017
** display.c
** File description:
** display functions
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

void disp_colors(table_t *table, int *x, int y)
{
	if (table->square[y][*x] == 'x')
		my_printf("\e[32m%c\e[0m", table->square[y][*x]);
	else if (table->square[y][*x] == 'o')
		my_printf("\e[31m%c\e[0m", table->square[y][*x]);
	else
		my_printf("\e[34m%c\e[0m", table->square[y][*x]);
}

void disp_x(table_t *table, int *x, int y)
{
	while (table->square[y][*x]){
		disp_colors(table, x, y);
		*x = *x + 1;
	}
}

void display(table_t *table)
{
	int y = 0;
	int x = 0;

	while (table->square[y][x]) {
		disp_x(table, &x, y);
		y = y + 1;
		x = 0;
		if (table->square[y])
			my_printf("\n");
	}
}
