##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	test_my_printf.c

OBJ	=	$(SRC:%.c=%.o)

CFLAGS	=	-Wshadow -I ../include

LIB	=	-L ../lib/my -lmy

NAME	=	unit_tests

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C ../lib/my
		$(CC) -o $(NAME) $(OBJ) $(LIB) --coverage -lcriterion

clean:
	rm -f $(OBJ)
	make -C ../lib/my clean
	rm -f *.gcno *.gcda

fclean:	clean
	make -C ../lib/my fclean
	rm -f $(NAME)

re:	fclean all
