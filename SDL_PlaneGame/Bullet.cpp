#include "Bullet.h"
Bullet::Bullet(int x, int y) :GameObject(x, y) {

	alive = true;

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


}

Bullet::~Bullet() {

}

void Bullet::Move() {

	if (isBulletFromEnemy == false) {

		//from player
		if (unitBounds->y > 5) {
			unitBounds->y = unitBounds->y - 2;
		}
		else {
			alive = false;
		}
	}
	else
	{
		//from enenmy
		if (unitBounds->y < 719)
		{
			unitBounds->y = unitBounds->y + 2;
		}
		else {
			alive = false;
		}
	}
}

wstring Bullet::Art() {

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

