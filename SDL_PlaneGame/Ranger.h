#pragma once
#include<iostream>
#include <stdlib.h> 
#include "GameObject.h"

class Ranger :public GameObject
{

public:

	bool isHit;
	Ranger(int x, int y);
	~Ranger();
	void Move();
	void GotHit(); //for when rabbit is at starting position
	wstring Art();

};



