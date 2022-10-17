#include "gameObject.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>
#include "Bullet.h"

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
	char* c = const_cast<char*>(path.c_str());
	unitTexture = IMG_LoadTexture(gRender, c);

}

void GameObject::setUnitBounds(int widthBound, int heightBound, int xPos, int yPos)
{
	unitBounds->w = widthBound;
	unitBounds->h = heightBound;
	unitBounds->x = xPos;
	unitBounds->y = yPos; 
}

//void GameObject::fireGun(int xBound, int yBound)
//{
//
//	GameObject* enemyBulletA = new Bullet(xBound, yBound);
//	GameObject* enemyBulletB = new Bullet(xBound, yBound);
//
//	enemyBulletA->setImage(gameRenderer, "media/ranger_bullet.png");
//	enemyBulletB->setImage(gameRenderer, "media/ranger_bullet.png");
//
//	enemyBulletA->setUnitBounds(8, 16, xBound, yBound);
//	enemyBulletB->setUnitBounds(8, 16, xBound, yBound);
//
//	bullet_list.insertAtTail(enemyBulletA);
//	bullet_list.insertAtTail(enemyBulletB);
//
//}