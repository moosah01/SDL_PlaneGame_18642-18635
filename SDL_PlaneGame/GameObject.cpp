#include "gameObject.h"
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_PlaneGame.cpp"


GameObject::GameObject(int x, int y)
{
	this->x = x;
	this->y = y;


	isHit = false;
	alive = true;

}

wstring GameObject::Art()
{
	return ascii_art;
}

bool GameObject::Alive()
{
	return alive;
}



GameObject::~GameObject() {
	//printf("Game Object destructor");
}

void GameObject::Translate(float xVal, float yVal)
{
	this->tx = xVal;
	this->ty = yVal;
}

void GameObject::changeAliveStatus()
{
	ascii_art.clear();
	isHit = true;

	ascii_art.append(L"\\|//");
	ascii_art.append(L"-xx-");
	ascii_art.append(L"-xx-");
	ascii_art.append(L"//|\\");

}

GameObject::GameObject()
{

}

void GameObject::setImage(SDL_Renderer* gRender, string path)
{
	unitTexture = IMG_LoadTexture(gRender, "media/player_sprite.png");

}

void GameObject::setUnitBounds(int xBound, int yBound)
{
	unitBounds->w = xBound;
	unitBounds->h = yBound;
	unitBounds->x = 200;
	unitBounds->y = 1040 / 2; 
}