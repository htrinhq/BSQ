/*
** EPITECH PROJECT, 2017
** find_angles.c
** File description:
** find angles functions
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

int check_angles(table_t *table, final_t *final, int *x, int *y)
{
	if (table->square[*y][*x + final->x] != '.')
		return (0);
	if (table->square[*y + final->y][*x + final->x] != '.')
		return (0);
	if (table->square[*y + final->y][*x] != '.')
		return (0);
	else {
		if (check_square(table, final, x, y))
			return (1);
		else
			return (0);
	}
}

int find_angles(table_t *table, final_t *final, int *x, int *y)
{
	int line = my_getnbr(table->nbline);

	while (*y < line) {
		if (!table->square[*y + final->y])
			return (0);
		if (table->square[*y][*x] == '\0') {
			*x = 0;
			*y = *y + 1;
		} else if (table->square[*y][*x] == '.' && \
			   table->square[*y][*x + final->x] && \
			   check_angles(table, final, x, y))
			break;
		*x = *x + 1;
	}
	return (1);
}

void mini_main(boolean_t *boolean, table_t *table, struct stat s, int fd)
{
	boolean->bp = 1;
	boolean->bo = 1;
	fill_struct(table, s);
	read(fd, table->size, s.st_size);
	table->square = fill_tab(table, s, boolean);
	booleans(boolean, table);
	free(boolean);
	free(table);
}

void single_column(table_t *table, int y, int x)
{
	if (table->column == 1) {
		while (table->square[y][0] == 'o') {
			y = y + 1;
		}
		table->square[y][0] = 'x';
		display(table);
		exit (0);
	} else if (my_getnbr(table->nbline) == 1) {
		while (table->square[0][x] == 'o') {
			x = x + 1;
		}
		table->square[0][x] = 'x';
		display(table);
		exit (0);
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
