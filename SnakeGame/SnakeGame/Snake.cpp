#define SDL_MAIN_HANDLED
//#include<Windows.h>
#include <SDL.h>

int main() {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Event e;
	bool running = true;

	while (running)
	{
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT)
			{
				running = false;
			}
			else if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					running = false;
					break;

				}
			}

		}
		SDL_SetRenderDrawColor(renderer, 0, 0,0, 255);
		SDL_RenderClear(renderer);
		// continue from here min 6.30 from the video


	}
	
	
	return 0;
}