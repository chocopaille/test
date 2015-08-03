#include "event.h"

int main(void)
{
	SDL_Surface	*screen = NULL, *perso = NULL;
	SDL_Event	event;
	int			continuer = 1;
	SDL_Rect	pos_perso;

	SDL_Init(SDL_INIT_VIDEO);

	screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
	SDL_WM_SetCaption("Gestion des événements en SDL", NULL);
	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
	perso = IMG_Load("goomba.png");
	pos_perso.x = screen->w / 2 - perso->w / 2;
	pos_perso.y = screen->h / 2 - perso->h / 2;
	SDL_EnableKeyRepeat(10, 10);
	SDL_WarpMouse(screen->w / 2, screen->h / 2);


	while (continuer)
	{
		SDL_WaitEvent(&event);
		switch (event.type)
		{
			case SDL_QUIT:
				continuer = 0;
				break ;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						continuer = 0;
						break ;
					case SDLK_UP:
						pos_perso.y--;
						break ;
					case SDLK_DOWN:
						pos_perso.y++;
						break ;
					case SDLK_LEFT:
						pos_perso.x--;
						break ;
					case SDLK_RIGHT:
						pos_perso.x++;
						break ;
				}
				break ;
			case SDL_MOUSEBUTTONUP:
				if (event.button.button == SDL_BUTTON_RIGHT)
				{
					pos_perso.x = event.button.x;
					pos_perso.y = event.button.y;
				}
				break ;
			/*case SDL_MOUSEMOTION:
				pos_perso.x = event.motion.x;
				pos_perso.y = event.motion.y;
				break ;*/
			case SDL_VIDEORESIZE:
				pos_perso.x = event.resize.w / 2 - perso->w / 2;
				pos_perso.y = event.resize.h / 2 - perso->h / 2;
				break ;
		}
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
		SDL_BlitSurface(perso, NULL, screen, &pos_perso);
		SDL_Flip(screen);
	}

	SDL_Quit();

	return EXIT_SUCCESS;
}
