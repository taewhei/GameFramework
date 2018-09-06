#include<SDL.h>

void init() {}
void render() {}
void update() {}
void handleEnvents() {}
void clean() {}

bool g_bRunning = true;

SDL_Window*g_pWindow = 0;
SDL_Renderer*g_pRenderer = 0;

/*int main(int argc, char* args[])
{
	

if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
{
g_pWindow = SDL_CreateWindow("PP01.HelloSDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN&&SDL_WINDOW_MAXIMIZED);
if (g_pWindow != 0) {
g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);

}

}
else {
return 1;
}
SDL_Rect rect = { 10,10,40,40 };

SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
SDL_RenderClear(g_pRenderer);
SDL_SetRenderDrawColor(g_pRenderer, 10, 50, 10, 255);
SDL_RenderDrawRect(g_pRenderer,&rect);
SDL_RenderPresent(g_pRenderer);
SDL_Delay(5000);
SDL_Quit();
return 0;
}*/
int main()
{
	init();
	while (g_bRunning) {
		handleEnvents();
		update();
		render();

	}
	clean();
}