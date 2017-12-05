/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

int main(int ac, char **av)
{
	struct stat s;
	table_t *table = malloc(sizeof(table_t));
	boolean_t *boolean = malloc(sizeof(boolean_t));
	int fd;

	if (ac != 2)
		return (84);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (84);
	boolean->bp = 1;
	boolean->bo = 1;
	stat(av[1], &s);
	if (s.st_size == 0)
		return (84);
	fill_struct(table, s);
	read(fd, table->size, s.st_size);
	table->square = fill_tab(table, s, boolean);
	booleans(boolean, table);
	free(boolean);
	free(table);
	return (0);
}
