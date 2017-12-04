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

/*void mallocs(struct stat s, char *size, char **square, char *nbline)
{
	size = malloc(sizeof(char) * s.st_size);
	square = malloc(sizeof(char*) * s.st_size);
	nbline = malloc(sizeof(char) * s.st_size);
}*/

void fill_struct(table_t *table, struct stat s)
{
	table->size = malloc(sizeof(char) * s.st_size);
	table->square = malloc(sizeof(char*) * s.st_size);
	table->nbline = malloc(sizeof(char) * s.st_size);
}

int main(int ac, char **av)
{
	struct stat s;
	table_t *table = malloc(sizeof(table_t));
	int fd;

	if (ac != 2)
		return (84);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (84);
	stat(av[1], &s);
	fill_struct(table, s);
	read(fd, table->size, s.st_size);
	table->square = fill_tab(table, s);
	display(table);
	free(table);
	return (0);
}
