#include "Nimble.h"
#include "gameObject.h" 


Nimble::Nimble(int x, int y) :GameObject(x, y)
{
	alive = true;
	this->isHit = false;
	canDodge = true;

	ascii_art.append(L" ^^ ");
	ascii_art.append(L"%  %");
	ascii_art.append(L" ¶¶ ");
	ascii_art.append(L" || ");

}

void Nimble::GotHit()
{

	ascii_art.clear();

	ascii_art.append(L"\\|//");
	ascii_art.append(L"-xx-");
	ascii_art.append(L"-xx-");
	ascii_art.append(L"//|\\");

}


wstring Nimble::Art()
{
	if (this->isHit == false)
	{
		return ascii_art;
	}

	else
	{
		GotHit();
	}
}

void Nimble::Move()
{

	unitBounds->x = this->x + (int)tx;
	//y = y + (int)ty;

	if (unitBounds->x < 0)
	{
		unitBounds->x = 0;
	}

	else if (unitBounds->x > 1216)
	{
		unitBounds->x = 1216;
	}

	if (unitBounds->y <656)
	{
		unitBounds->y = unitBounds->y + 1;
	}
	else {
		alive = false;
	}

	//tx *= frictionCoff;
	//ty *= frictionCoff;
}

Nimble::~Nimble() {
	//printf("Rabbit Object destructor");
}
