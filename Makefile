##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

all:
	make -C lib/my/
	cp lib/my/libmy.a ./libmy.a

clean:
	make -C lib/my clean
	rm -f *.gcno *.gcda

fclean:	clean
	make -C lib/my fclean
	rm -f libmy.a

re:	fclean all
