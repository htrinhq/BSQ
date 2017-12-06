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
	int path;
};

typedef struct boolean boolean_t;

struct table {
	char *size;
	char **square;
	char *nbline;
	int column;
};

typedef struct table table_t;

struct final {
	int x;
	int y;
	int inter_x;
	int inter_y;
};

typedef struct final final_t;

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
int check_square_y(table_t *table, final_t *final, int *x);
int check_square(table_t *table, final_t *final, int *x, int *y);
void x_cross(final_t *final, table_t *table, final_t *inter);
void fill_with_cross(int x, int y, final_t *final, table_t *table);
int check_angles(table_t *table, final_t *final, int *x, int *y);
int find_angles(table_t *table, final_t *final, int *x, int *y);
void mini_main(boolean_t *boolean, table_t *table, struct stat s, int fd);
void single_column(table_t *table, int y, int x);
int find_bsq(table_t *table, final_t *final, boolean_t *boolean);

#endif
