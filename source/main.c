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

void display(char **square)
{
	int y = 0;

	while (square[y]) {
		my_printf("%s", square[y]);
		y = y + 1;
		if (square[y])
			my_printf("\n");
	}
}

char *find_nbline(char *size, char *nbline, int *i)
{
	while (size[*i] != '\n') {
		nbline[*i] = size[*i];
		*i = *i + 1;
	}
	nbline[*i] = '\0';
	*i = *i + 1;
	return(nbline);
}

char **fill_tab(char *size, char **square, struct stat s, char *nbline)
{
	int x = 0;
	int i = 0;
	int y = 0;

	square[y] = malloc(sizeof(char) * s.st_size);
	nbline = find_nbline(size, nbline, &i);
	while (i != s.st_size) {
		square[y][x] = size[i];
		if (size[i] == '\n') {
			square[y][x] = '\0';
			x = 0;
			y = y + 1;
			square[y] = malloc(sizeof(char) * s.st_size);
		} else
			x = x + 1;
		i = i + 1;
	}
	square[y][x] = '\0';
	square[y + 1] = '\0';
	return (square);
}

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
