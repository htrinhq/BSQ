##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

SRC	=	source/main.c	\
		source/fill_tab.c	\
		source/my_getnbr.c	\
		source/find_angles.c	\
		source/find_bsq.c	\
		source/easy_case.c

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

CFLAGS	=	-W -Wall -Wextra -I include -g

LDFLAGS	=	-L ./lib/my -lmy

all:	libmake $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

libmake:
	make -C ./lib/my/

clean:
	rm -f $(OBJ)
	make clean -C ./lib/my/

fclean:	clean
	rm -f $(NAME)
	make fclean -C ./lib/my/

re:	fclean all

PHONY: fclean clean all re libmake
