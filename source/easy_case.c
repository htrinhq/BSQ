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

void single_column(table_t *table, int y)
{
	if (table->column == 1) {
		while (table->square[y][0] == 'o') {
			y = y + 1;
		}
		table->square[y][0] = 'x';
		display(table);
		exit (0);
	}

}

int find_bsq(table_t *table, final_t *final, boolean_t *boolean)
{
	int y = 0;
	int x = 0;

	single_column(table, y);
	if (find_angles(table, final, &x, &y)) {
		final->x = final->x + 1;
		final->y = final->y + 1;
		boolean->path = boolean->path + 1;
		if (!find_bsq(table, final, boolean) && \
			boolean->path == final->y) {
			fill_with_cross(x, y, final, table);
			return (1);
		}
	}
	return (0);
}

void booleans(boolean_t *boolean, table_t *table)
{
	if (boolean->bo && !boolean->bp)
		display(table);
	else if (boolean->bp && !boolean->bo)
		empty_display(table);
	else {
		final_t *final = malloc(sizeof(final_t));
		final->x = 0;
		final->y = 0;
		boolean->path = 0;
		find_bsq(table, final, boolean);
	}
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
