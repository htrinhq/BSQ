/*
** EPITECH PROJECT, 2017
** fill_tab.c
** File description:
** handles fill tab functions
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

char *find_nbline(table_t *table, int *i)
{
	while (table->size[*i] != '\n') {
		table->nbline[*i] = table->size[*i];
		*i = *i + 1;
	}
	table->nbline[*i] = '\0';
	*i = *i + 1;
	return (table->nbline);
}

void next_line(table_t *table, struct stat s, int *x, int *y)
{
	table->square[*y][*x] = '\0';
	table->column = *x;
	*x = 0;
	*y = *y + 1;
	table->square[*y] = malloc(sizeof(char) * s.st_size);
}

char **fill_tab(table_t *table, struct stat s, boolean_t *boolean)
{
	int x = 0;
	int i = 0;
	int y = 0;

	table->square[y] = malloc(sizeof(char) * s.st_size);
	table->nbline = find_nbline(table, &i);
	while (i != s.st_size) {
		table->square[y][x] = table->size[i];
		if (table->size[i] == '\n')
			next_line(table, s, &x, &y);
		else {
			choose_b(table, boolean, i);
			x = x + 1;
		}
		i = i + 1;
	}
	table->square[y][x] = '\0';
	table->square[y + 1] = '\0';
	return (table->square);
}

void fill_struct(table_t *table, struct stat s)
{
	table->size = malloc(sizeof(char) * s.st_size);
	table->square = malloc(sizeof(char*) * s.st_size);
	table->nbline = malloc(sizeof(char) * s.st_size);
}
