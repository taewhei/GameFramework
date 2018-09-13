#include "Game.h"
#include <iostream>
bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		if (fullscreen == true)
		{
			m_pWindow = SDL_CreateWindow(title, xpos,ypos, width, height, SDL_WINDOW_FULLSCREEN);
		}
		else
		{
			m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		}
		
		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

		}

	}
	else {
		m_bRunning = false;
		return false;
	}
	SDL_Rect rect = { 10,10,40,40 };
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
	SDL_SetRenderDrawColor(m_pRenderer, 10, 50, 10, 255);
	SDL_RenderDrawRect(m_pRenderer, &rect);

	
	SDL_Surface* pTempSurface = SDL_LoadBMP("assets/rider.bmp");
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer,pTempSurface);

	SDL_FreeSurface(pTempSurface);
	SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);



	m_bRunning = true;
	return true;
}
void Game::update()
{

}
void Game::render()
{
	//SDL_RenderClear(m_pRenderer);
	//SDL_RenderPresent(m_pRenderer);
	m_destinationRectangle.x = m_sourceRectangle.x = 0;
	m_destinationRectangle.y = m_sourceRectangle.y = 0;
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;

	SDL_RenderClear(m_pRenderer);

	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
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