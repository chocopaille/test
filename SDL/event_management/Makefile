CPP = gcc

CFLAGS = -Ofast

LDFLAGS = -lSDLmain -lSDL_image -lSDL

SRC = main.c

OBJ = main.o

NAME = event

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
