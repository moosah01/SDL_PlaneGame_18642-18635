#pragma once
#include<iostream>
#include <stdlib.h> 
#include "GameObject.h"

class Nimble :public GameObject
{


public:

	bool isHit;
	Nimble(int x, int y);
	~Nimble();
	void Move();
	void GotHit(); //for when rabbit is at starting position
	wstring Art();

};



