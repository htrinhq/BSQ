/*
** EPITECH PROJECT, 2017
** bsq.h
** File description:
** include bsq
*/

#ifndef BSQ_H_
#define BSQ_H_

struct boolean {
	int bp;
	int bo;
};

typedef struct boolean boolean_t;

struct table {
	char *size;
	char **square;
	char *nbline;
	int column;
};

typedef struct table table_t;

void my_printf(const char *format, ...);
char **fill_tab(table_t *table, struct stat s, boolean_t *boolean);
void next_line(table_t *table, struct stat s, int *x, int *y);
char *find_nbline(table_t *table, int *i);
void display(table_t *table);
void fill_struct(table_t *table, struct stat s);
int my_getnbr(char const *str);
void column_sup(table_t *table, int line);
void line_supp(table_t *table);
void empty_display(table_t *table);
void booleans(boolean_t *boolean, table_t *table);
void choose_b(table_t *table, boolean_t *boolean, int i);

#endif
