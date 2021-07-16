##
## EPITECH PROJECT, 2021
## sfml_t
## File description:
## Makefile
##

CFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system

NAME = chibre

OBJ =	src/main.cpp	\
		src/key_put.cpp	\
		src/class/pigon.cpp

OK:
	g++ -o $(NAME) $(OBJ) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -g -I include

all = $(OK)

START:
	$(OK)
	./chibre

clean:
	rm -f $(NAME)

fclean:	clean
	rm -f $(NAME)
	make -C tests/ fclean

re:	fclean OK