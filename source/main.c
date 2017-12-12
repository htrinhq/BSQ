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
	stat(av[1], &s);
	if (s.st_size == 0)
		return (84);
	mini_main(boolean, table, s, fd);
	free(table->nbline);
	free(table->square);
	//free(table->size);
	return (0);
}
