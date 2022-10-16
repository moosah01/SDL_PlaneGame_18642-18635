#pragma once
#pragma once
#include<iostream>
#include <stdlib.h> 
#include <SDL.h>
#include <SDL_image.h>


using namespace std;


// class to be inherited by our game objects i.e; Rabbit and Cloud
class GameObject
{
protected:
	wstring ascii_art;  // made protected beause else the Art function will not be able to access its values
	// v beause else the Art function will not be able to access its status

public:
	int x;
	int y;
	//int hp;
	float tx = 0.0;
	float ty = 0.0;
	bool isHit;
	bool alive;
	bool isBulletFromEnemy;
	bool canDodge = false;
	float frictionCoff = 0.995;
	SDL_Rect* unitBounds = new SDL_Rect();
	SDL_Texture* unitTexture = NULL;


	//gameObject();
	GameObject(int x, int y);
	GameObject();
	virtual ~GameObject(); // whenever it is deleted, it will also call the children's destructor method
	virtual wstring Art();  // gonna be updaed dynamically for Rabbit ONLY
	virtual void Move() = 0; // pure virtual because different for each of the children classes
	bool Alive();
	void changeAliveStatus();
	//int getHealth();
	void setImage(SDL_Renderer* gRender, string path);
	void setUnitBounds(int x, int y);
	//void setSDLRECT(int x, int y);

	void Translate(float xVal, float yVal);
};
