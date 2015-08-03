#include "image_load.h"

void	pause(void)
{
	int			done;
	SDL_Event	event;

	done = 0;
	while (!(done))
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT)
			done = 1;
	}
}

int		main(void)
{
	SDL_Surface *screen = NULL, *image = NULL, *tree = NULL;
	int			width = 800, high = 600;
	SDL_Rect	position, position_tree;

if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		fprintf(stderr, "Erreur init SDL: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_WM_SetIcon(SDL_LoadBMP("Pictures/sdl_icone.bmp"), NULL);
	screen = SDL_SetVideoMode(width, high, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	if (screen == NULL)
	{
		fprintf(stderr, "Erreur environnement video%s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_WM_SetCaption("test", 0x0);
	image = IMG_Load("Pictures/lac_en_montagne.bmp");

	tree = IMG_Load("Pictures/sapin.png");

	position.x = 0;
	position.y = 0;
	position_tree.x = 500;
	position_tree.y = 200;
	
	SDL_BlitSurface(image, NULL, screen, &position);
	SDL_BlitSurface(tree, NULL, screen, &position_tree);
	SDL_Flip(screen);
	
	pause();
	
	SDL_Quit();
	return (EXIT_SUCCESS);
}
