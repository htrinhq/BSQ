/*
** EPITECH PROJECT, 2017
** find_bsq.c
** File description:
** find_bsq functions, if angles are detected
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

int check_square_y(table_t *table, final_t *final, int *x)
{
	while (final->inter_x <= final->x + *x) {
		if (table->square[final->inter_y][final->inter_x] == 'o')
			return (0);
		final->inter_x = final->inter_x + 1;
	}
	return (1);
}

int check_square(table_t *table, final_t *final, int *x, int *y)
{
	final->inter_x = *x;
	final->inter_y = *y;
	while (final->inter_y <= final->y + *y) {
		if (!check_square_y(table, final, x))
			return (0);
		final->inter_x = *x;
		final->inter_y = final->inter_y + 1;
	}
	return (1);
}

void x_cross(final_t *final, table_t *table, final_t *inter)
{
	while (inter->inter_x <= final->x + inter->x) {
		table->square[inter->inter_y][inter->inter_x] = 'x';
		inter->inter_x = inter->inter_x + 1;
	}
}

void fill_with_cross(int x, int y, final_t *final, table_t *table)
{
	final_t *inter = malloc(sizeof(final_t));

	inter->x = x;
	inter->y = y;
	inter->inter_x = x;
	inter->inter_y = y;
	final->x = final->x - 1;
	final->y = final->y - 1;
	while (inter->inter_y <= final->y + inter->y) {
		x_cross(final, table, inter);
		inter->inter_x = inter->x;
		inter->inter_y = inter->inter_y + 1;
	}
	display(table);
	free(inter);
}
