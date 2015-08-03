CPP = gcc

CFLAGS = -Ofast -Werror -Wall -Wextra

LDFLAGS = -lSDLmain -lSDL

SRC = degrade.c

OBJ = degrade.o

NAME = degrade

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
