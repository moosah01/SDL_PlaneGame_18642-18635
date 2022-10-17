#include "Ranger.h"
#include "gameObject.h" 

Ranger::Ranger(int x, int y) :GameObject(x, y)
{
	alive = true;
	this->isHit = false;

	ascii_art.append(L"    ");
	ascii_art.append(L" @@ ");
	ascii_art.append(L"¶  ¶");
	ascii_art.append(L" @@ ");

}

void Ranger::GotHit()
{

	ascii_art.clear();

	ascii_art.append(L"\\|//");
	ascii_art.append(L"-xx-");
	ascii_art.append(L"-xx-");
	ascii_art.append(L"//|\\");
}


wstring Ranger::Art()
{
	if (alive == true)
	{
		return ascii_art;
	}


	else
	{
		ascii_art.append(L"\\|//");
		ascii_art.append(L"-xx-");
		ascii_art.append(L"-xx-");
		ascii_art.append(L"//|\\");
	}
}

void Ranger::Move()
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

	if (unitBounds->y < 656)
	{
		unitBounds->y = unitBounds->y + 1;
	}
	else {
		alive = false;
	}

	/*tx *= frictionCoff;
	ty *= frictionCoff;*/
}

Ranger::~Ranger() 
{
	//printf("Rabbit Object destructor");
}
