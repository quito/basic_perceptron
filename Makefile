
NAME	=	neuronne

SRC	=	main.cpp \
		perceptron.cpp \
		trainer.cpp \
		graphic.cpp

CC	=	g++ -O3

CFLAGS	=	--Wall -Wextra -O3

OBJ	=	$(SRC:.cpp=.o)

LDFLAGS =	-lSDL -O3

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean $(NAME)
