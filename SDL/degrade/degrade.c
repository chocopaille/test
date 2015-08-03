#include "degrade.h"

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
	SDL_Surface *screen = NULL;
	Uint32		color;
	int			width = 600;
	int			high = 257;
	SDL_Surface	*list_degrade[256];
	SDL_Rect	position;
	int i;

	i = 0;
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
	while (i <= 256)
	{
		list_degrade[i] = SDL_CreateRGBSurface(SDL_HWSURFACE, width, 1, 32, 0, 0, 0, 0);
		position.x = 0;
		position.y = i;
		SDL_FillRect(list_degrade[i], NULL, SDL_MapRGB(screen->format, i, i, i));
		SDL_BlitSurface(list_degrade[i], NULL, screen, &position);
		i++;
	}

	SDL_Flip(screen);

	pause();
	for (i = 0; i <= 255; i++)
		SDL_FreeSurface(list_degrade[i]);
	SDL_Quit();
	return (EXIT_SUCCESS);
}
