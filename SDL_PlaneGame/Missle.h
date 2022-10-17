#pragma once
#include<iostream>
#include <stdlib.h> 
#include "GameObject.h"

using namespace std;

class Missle :public GameObject
{

public:

	Missle(int x, int y);
	~Missle();
	void Move();
	wstring Art();


};

