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
	char *size;
	char **square;
	char *nbline;
	int fd;

	if (ac != 2)
		return (84);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (84);
	stat(av[1], &s);
	size = malloc(sizeof(char) * s.st_size);
	square = malloc(sizeof(char*) * s.st_size);
	nbline = malloc(sizeof(char) * s.st_size);
	read(fd, size, s.st_size);
	square = fill_tab(size, square, s, nbline);
	display(square);
	return (0);
}
