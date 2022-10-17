#include "Missle.h"
#include "GameObject.h"

Missle::Missle(int x, int y) :GameObject(x, y)
{

	alive = true;

}

Missle::~Missle() {

}

void Missle::Move() 
{

	//from enenmy
	if (unitBounds->y > 5) 
	{
		unitBounds->y = unitBounds->y - 2;
	}
	else 
	{
		alive = false;
	}
	
}

wstring Missle::Art() 
{

	ascii_art.clear();

	if (isBulletFromEnemy == false)
	{
		ascii_art.append(L" ^^ ");
		ascii_art.append(L" || ");
		ascii_art.append(L"    ");
		ascii_art.append(L"    ");
	}

	else
	{
		ascii_art.append(L"    ");
		ascii_art.append(L"enem");
		ascii_art.append(L" || ");
		ascii_art.append(L" vv ");
	}

	return ascii_art;
}

