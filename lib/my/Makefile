##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	my_getnbr.c			\
		my_putchar.c			\
		my_put_nbr.c			\
		my_putstr.c			\
		my_revstr.c			\
		my_strlen.c			\
		my_put_unsigned_int.c		\
		convert_dec_to_hexa.c		\
		my_memset.c			\
		my_intlen.c			\
		convert_dec_to_hexa.c		\
		convert_dec_to_octal.c		\
		convert_dec_to_binary.c		\
		check_cases.c			\
		my_strcmp.c			\
		check_format.c			\
		fill_number.c			\
		manage_format.c			\
		my_printf.c

OBJ	=	$(SRC:%.c=%.o)

CFLAGS	=	-I ../../include/

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
