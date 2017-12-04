/*
** EPITECH PROJECT, 2017
** easy_case.c
** File description:
** easy cases functions
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

void column_sup(table_t *table, int line)
{
	int y = 0;
	int x = 0;

	while (y <= line) {
		if (x >= line + 1 && y <= line) {
			x = 0;
			y = y + 1;
		} else {
			table->square[y][x] = 'x';
			x = x + 1;
		}
	}
}

void line_supp(table_t *table)
{
	int y = 0;
	int x = 0;

	while (y <= table->column - 1) {
		if (x >= table->column && y <= table->column - 1) {
			x = 0;
			y = y + 1;
		} else {
			table->square[y][x] = 'x';
			x = x + 1;
		}
	}
}

void empty_display(table_t *table)
{
	int line = my_getnbr(table->nbline) - 1;

	if (table->column > line)
		column_sup(table, line);
	else
		line_supp(table);
	display(table);
}

void booleans(boolean_t *boolean, table_t *table)
{
	if (boolean->bo && !boolean->bp)
		display(table);
	else if (boolean->bp && !boolean->bo)
		empty_display(table);
	else
		my_printf("c'est quand meme compliqué!\n");
}

void choose_b(table_t *table, boolean_t *boolean, int i)
{
	if (table->size[i] == '.')
		boolean->bo = 0;
	else if (table->size[i] == 'o')
		boolean->bp = 0;
	else
		exit(84);
}
