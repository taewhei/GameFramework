#include "Game.h"
#include <iostream>
bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	bool g_bRunning = true;

	SDL_Window*g_pWindow = 0;
	SDL_Renderer*g_pRenderer = 0;

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		if (fullscreen == true)
		{
		g_pWindow = SDL_CreateWindow(title, xpos,ypos, width, height, SDL_WINDOW_FULLSCREEN);
		}
		else
		{
		g_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		}
		
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
	SDL_RenderDrawRect(g_pRenderer, &rect);
	SDL_RenderPresent(g_pRenderer);
	SDL_Delay(5000);
	SDL_Quit();
	return 0;
	return true;
}
void Game::update()
{

}
void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	SDL_RenderPresent(m_pRenderer);
}
void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}
void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
				m_bRunning = false;
				break;
		default:
				break;
		}
	}
}