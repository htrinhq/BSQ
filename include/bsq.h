/*
** EPITECH PROJECT, 2017
** bsq.h
** File description:
** include bsq
*/

#ifndef BSQ_H_
#define BSQ_H_

void my_printf(const char *format, ...);
char **fill_tab(char *size, char **square, struct stat s, char *nbline);
void next_line(char **square, struct stat s, int *x, int *y);
char *find_nbline(char *size, char *nbline, int *i);
void display(char **square);

#endif
