#pragma once
#include<iostream>
#include <stdlib.h> 
#include "GameObject.h"

using namespace std;

class Bullet :public GameObject
{

public:

	Bullet(int x, int y);
	~Bullet();
	void Move();
	wstring Art();


};

