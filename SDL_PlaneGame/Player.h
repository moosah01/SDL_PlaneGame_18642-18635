#pragma once

#include<iostream>
#include <stdlib.h> 
#include "GameObject.h"

class Player :public GameObject
{


public:

	double planeX;
	double planeY;

	Player(int x, int y);
	void Move();
	void PlayerDestroy();
	wstring Art();
	void Fire();
	~Player();

};

