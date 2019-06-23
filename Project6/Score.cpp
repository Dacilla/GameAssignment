#include "Score.h"
#include <SDL_ttf.h>
#include <SDL.h>


Score::Score()
{
	//TTF_Font* scoreFont = TTF_OpenFont("assets/BebasNeue-Regular.ttf", 16);
	//SDL_Color textColour = { 0, 0, 0, 60 };
	////create surface
	//SDL_Surface* textSurface = TTF_RenderText_Blended(scoreFont, getScore(), textColour);
	////convert to texture
	//SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	//SDL_FreeSurface(textSurface);
}


Score::~Score()
{
}

int Score::getScore()
{
	return 0;
}

void Score::startScoreCount()
{
	Uint32 lastUpdate = SDL_GetTicks();
	Uint32 timeDiff = SDL_GetTicks() - lastUpdate;
	float DT = timeDiff / 1000.0;
}

void Score::endScoreCount()
{
	
}

//void Score::destroyScoreText()
//{
//	SDL_DestroyTexture(textTexture);
//}

void Score::draw()
{
	
}

