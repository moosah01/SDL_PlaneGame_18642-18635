#pragma once

#include<iostream>
#include <stdlib.h> 
#include "GameObject.h"
#include "Player.h" 


Player::Player(int x, int y):GameObject(x, y) {

	alive = true;

	ascii_art.append(L" || ");
	ascii_art.append(L"@  @");
	ascii_art.append(L" @@ ");
	ascii_art.append(L" || ");
}


void Player::PlayerDestroy()
{
	ascii_art.clear();

	ascii_art.append(L"\\|//");
	ascii_art.append(L"-xx-");
	ascii_art.append(L"-xx-");
	ascii_art.append(L"//|\\");
}

void Player::Move()
{
	//x = x + (int)tx;
	//y = y + (int)ty;

	unitBounds->x = unitBounds->x + (int)tx;
	unitBounds->y = unitBounds->y + (int)ty;

	if (unitBounds->x < 0)
	{
		unitBounds->x = 0;
	}

	else if (unitBounds->x > 1216)
	{
		unitBounds->x = 1216;
	}

	if (unitBounds->y < 0)
	{
		unitBounds->y = 0;
	}
	else if (unitBounds->y > 656) {
		unitBounds->y = 656;
	}
	tx *= frictionCoff;
	ty *= frictionCoff;

}


Player::~Player()
{

}

void Player::Fire()
{

}

wstring Player::Art()
{
	ascii_art.clear();

	ascii_art.append(L" || ");
	ascii_art.append(L"@  @");
	ascii_art.append(L" @@ ");
	ascii_art.append(L" || ");
	return ascii_art;
}