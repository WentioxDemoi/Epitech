##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## mkf
##

SRC	=	src/*.cpp				\
		src/system/*.cpp		\
		src/factory/*.cpp		\
		src/components/*.cpp

OBJ	=	$(SRC:.c=.o)

NAME	=	r-type_client

all:	$(NAME)

$(NAME):
	g++ $(SRC) -I/opt/homebrew/Cellar/sfml/2.5.1_2/include -I /opt/homebrew/Cellar/boost/1.79.0_2/include/  -o $(NAME) -L/opt/homebrew/Cellar/sfml/2.5.1_2/lib -L /opt/homebrew/Cellar/boost/1.79.0_2/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lboost_serialization -lpthread -std=c++11
clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re