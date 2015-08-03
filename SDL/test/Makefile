CPP = gcc

CFLAGS = -Ofast -Werror -Wall -Wextra

LDFLAGS = -lSDLmain -lSDL

SRC = test.c

OBJ = test.o

NAME = test

all: $(NAME)

$(NAME): ocreate
	$(CPP) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

ocreate:
	$(CPP) $(CFLAGS) -c $(SRC)

clean:
	rm -fr *.o

fclean: clean
	rm -fr $(NAME)

re: fclean all
