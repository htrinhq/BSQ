/*
** EPITECH PROJECT, 2017
** bsq.h
** File description:
** include bsq
*/

#ifndef BSQ_H_
#define BSQ_H_

struct table {
	char *size;
	char **square;
	char *nbline;
};

typedef struct table table_t;

void my_printf(const char *format, ...);
char **fill_tab(table_t *table, struct stat s);
void next_line(table_t *table, struct stat s, int *x, int *y);
char *find_nbline(table_t *table, int *i);
void display(table_t *table);

#endif
