#include "test.h"

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
		if (event->type == SDL_KEYDOWN)
			event->key 
	}
}

int		main(void)
{
	SDL_Surface *screen = NULL;
	SDL_Surface *square = NULL;
	Uint32		color;
	int			width = 600;
	int			high = 400;
	Uint32		color_square;
	SDL_Rect	coord_square;
	int			side_square = 59;


if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		fprintf(stderr, "Erreur init SDL: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	screen = SDL_SetVideoMode(width, high, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	if (screen == NULL)
	{
		fprintf(stderr, "Erreur environnement video%s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_WM_SetCaption("test", 0x0);
	
	color = SDL_MapRGB(screen->format, 255, 255, 0);
	SDL_FillRect(screen, NULL, color);
	
	square = SDL_CreateRGBSurface(SDL_HWSURFACE, side_square, side_square, 32, 0, 0, 0, 0);
	coord_square.x = width / 2 - side_square / 2;
	coord_square.y = high / 2 - side_square / 2;
	color_square = SDL_MapRGB(screen->format, 255, 0, 0);
	SDL_FillRect(square, NULL, color_square);
	
	SDL_Flip(screen);
	SDL_BlitSurface(square, NULL, screen, &coord_square);
	
	pause();
	
	SDL_FreeSurface(square);
	SDL_Quit();
	return (EXIT_SUCCESS);
}
