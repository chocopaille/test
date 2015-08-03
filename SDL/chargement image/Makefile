CPP = gcc

CFLAGS = -Ofast -Werror -Wall -Wextra

LDFLAGS = -lSDLmain -lSDL_image -lSDL

SRC = image_load.c

OBJ = image_load.o

NAME = image_load

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
