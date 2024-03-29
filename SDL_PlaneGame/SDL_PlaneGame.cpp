#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>
#include "GameObject.h"
#include "Player.h"
#include "doublyList.h"
#include "Bullet.h"
#include "Node.h"
#include "Ranger.h"
#include "Nimble.h"
#include <Windows.h>
#include <thread>
#include "Missle.h"




const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;



int main(int argc, char* argv)
{

	SDL_Renderer* gameRenderer;
	doublyList gameobject_list;
	doublyList bullet_list;
	doublyList missile_list;

	SDL_Surface* background;
	SDL_Surface* WindowSurface;


	GameObject* player1 = new Player(200, 520);


	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) 
	{

		std::cout << "SDL Failed to initialize. Error Code : " << SDL_GetError() << std::endl;

	}

	SDL_Window* window = SDL_CreateWindow("Plane Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
	WindowSurface = SDL_GetWindowSurface(window);

	if (window == NULL) {
		std::cout << "Could not initialize SDL Window. Error Code : " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	if (!(IMG_Init(IMG_INIT_PNG)) & IMG_INIT_PNG) {
		std::cout << "Could not initialize PNG. Error Code : " << SDL_GetError() << std::endl;
	}

	SDL_Event window_event;

	background = IMG_Load("media/gameBG.jpg");


	if (background == NULL) {
		std::cout << "Could not load background image. Error Code : " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	gameRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	player1->setImage(gameRenderer, "media/player_sprite.png");
	//Load Player Plane
	//SDL_Texture* Player = NULL;
	//Player = IMG_LoadTexture(R, "media/player_sprite.png");
	SDL_Texture* gameBG = IMG_LoadTexture(gameRenderer, "media/gameBG.jpg");

	SDL_Texture* button = IMG_LoadTexture(gameRenderer, "C:/Users/shahe/Desktop/final game dev/button.png");
	SDL_Texture* text = IMG_LoadTexture(gameRenderer, "C:/Users/shahe/Desktop/final game dev/text.png");
	SDL_Texture* escape = IMG_LoadTexture(gameRenderer, "C:/Users/shahe/Desktop/final game dev/x.png");
	SDL_Rect* esc = new SDL_Rect();
	esc->x = 10;
	esc->y = 20;
	esc->w = 32;
	esc->h = 16;


	player1->setUnitBounds(64, 64, 200, 520);

	/*SDL_Rect* Player_Rect = new SDL_Rect();
	Player_Rect->w = 64;
	Player_Rect->h = 64;
	Player_Rect->x = 200;
	Player_Rect->y = 1040 / 2;*/

	SDL_Rect* Background_Rect = new SDL_Rect();
	Background_Rect->w = SCREEN_WIDTH;
	Background_Rect->h = SCREEN_HEIGHT;
	Background_Rect->x = 0;
	Background_Rect->y = 0;
	int bullXBound = 0;
	int bullYBound = 0;
	int gameFrames = 0;
	int random = 0;
	int randomDodge = 0;
	int xDiff = 0;
	int yDiff = 0;
	bool game_running = false;
	bool flag = true;


	while (flag) {
		//if (SDL_PollEvent(&window_event))
		//{

		//	if (SDL_QUIT == window_event.type) {
		//		break;
		//	}
		//}

		while (!game_running) {

			SDL_Rect* rect = new SDL_Rect();
			rect->x = 500;
			rect->y = 550;
			rect->h = 64;
			rect->w = 256;


			SDL_RenderClear(gameRenderer);
			SDL_RenderCopy(gameRenderer, gameBG, NULL, NULL);
			SDL_RenderCopy(gameRenderer, button, NULL, rect);
			SDL_RenderCopy(gameRenderer, text, NULL, rect);
			SDL_RenderCopy(gameRenderer, escape, NULL, esc);
			SDL_RenderPresent(gameRenderer);
			if (SDL_PollEvent(&window_event))
			{

				if (SDL_QUIT == window_event.type) {
					flag = false;
					break;
				}

				if (SDL_KEYDOWN == window_event.type)
				{
					if (SDLK_SPACE == window_event.key.keysym.sym) {
						game_running = true;
					}
					if (SDLK_ESCAPE == window_event.key.keysym.sym) {
						flag = false;
						break;
					}
				}
			}

		}

		while (game_running)
		{

			gameFrames++;
			if (SDL_PollEvent(&window_event))
			{

				if (SDL_QUIT == window_event.type) {
					flag = false;
					break;
				}

				if (SDL_KEYDOWN == window_event.type)
				{
					if (SDLK_DOWN == window_event.key.keysym.sym) {
						//player1->unitBounds->y = player1->unitBounds->y + 5;
						player1->Translate(0, 2);
					}
					if (SDLK_UP == window_event.key.keysym.sym) {
						//player1->unitBounds->y = player1->unitBounds->y - 5;
						player1->Translate(0, -2);
					}
					if (SDLK_LEFT == window_event.key.keysym.sym) {
						//player1->unitBounds->x = player1->unitBounds->x - 5;
						player1->Translate(-2, 0);
					}
					if (SDLK_RIGHT == window_event.key.keysym.sym) {
						//player1->unitBounds->x = player1->unitBounds->x + 5;
						player1->Translate(2, 0);
					}
					if (SDLK_SPACE == window_event.key.keysym.sym)
					{
						GameObject* bulletA = new Bullet(player1->unitBounds->x + 20, player1->unitBounds->y - 16);
						GameObject* bulletB = new Bullet(player1->unitBounds->x + 40, player1->unitBounds->y - 16);
						bulletA->isBulletFromEnemy = false;
						bulletB->isBulletFromEnemy = false;
						bulletA->setImage(gameRenderer, "media/player_bullet.png");
						bulletB->setImage(gameRenderer, "media/player_bullet.png");
						bulletA->setUnitBounds(8, 16, player1->unitBounds->x + 20, player1->unitBounds->y - 16);
						bulletB->setUnitBounds(8, 16, player1->unitBounds->x + 40, player1->unitBounds->y - 16);

						bullet_list.insertAtTail(bulletA);
						bullet_list.insertAtTail(bulletB);
					}

					if (SDLK_b == window_event.key.keysym.sym) {


					}
				}
			}

			if (gameFrames % 250 == 0)
			{
				random = rand() % 1216;
				GameObject* newRanger = new Ranger(random, 0);
				//add bullet mechanism here
				//set bullet from enemy to true

				newRanger->setImage(gameRenderer, "media/rangerEnem.png");
				newRanger->setUnitBounds(64, 64, random, 0);

				newRanger->isRanger = true;
				gameobject_list.insertAtTail(newRanger);


			}

			if (gameFrames % 400 == 0)
			{

				random = rand() % 1216;
				GameObject* newNimble = new Nimble(520, 0);
				//add bullet mechanism here
				//set bullet from enemy to true

				newNimble->setImage(gameRenderer, "media/nimbleEnem.png");
				newNimble->setUnitBounds(64, 64, 520, 0);
				newNimble->isRanger = false;

				gameobject_list.insertAtTail(newNimble);


			}

			//bullet & plane
			for (int countBullet = 0; countBullet < bullet_list.returnSize(); countBullet++)
			{
				GameObject* tempBull = bullet_list.returnAt(countBullet);
				//player bullet & enemy plane
				if (tempBull->alive != false && tempBull->isBulletFromEnemy == false)
				{
					for (int countEnemy = 0; countEnemy < gameobject_list.returnSize(); countEnemy++)
					{
						GameObject* tempEnem = gameobject_list.returnAt(countEnemy);
						if (tempEnem->alive != false)
						{
							xDiff = tempBull->unitBounds->x - tempEnem->unitBounds->x;
							yDiff = tempBull->unitBounds->y - tempEnem->unitBounds->y;

							if (tempEnem->isRanger == false)
							{

								if (yDiff <= 200 && yDiff >= 128)
								{
									if (xDiff >= -7 && xDiff <= 71)
									{
										if (xDiff >= -7 && xDiff <= 32)
										{
											tempEnem->Translate(2, 0);
										}
										else if (xDiff >= 33 && xDiff <= 71)
										{
											tempEnem->Translate(-2, 0);
										}
									}
								}
								if (xDiff >= -6 && xDiff <= 70 && yDiff >= 0 && yDiff <= 64)
								{
									tempBull->alive = false;
									tempEnem->Health--;
									//tempEnem->alive = false;
								}
							}
							else if (tempEnem->isRanger == true)
							{
								if (xDiff >= -6 && xDiff <= 70 && yDiff >= 0 && yDiff <= 64)
								{
									tempBull->alive = false;
									tempEnem->Health--;
									//tempEnem->alive = false;
								}
							}

						}
					}
				}
				//enemy bullet and player plane
				else if (tempBull->alive != false && tempBull->isBulletFromEnemy == true)
				{
					xDiff = tempBull->unitBounds->x - player1->unitBounds->x;
					yDiff = tempBull->unitBounds->y - player1->unitBounds->y;

					if (xDiff >= -6 && xDiff <= 70 && yDiff >= 0 && yDiff <= 62)
					{
						//game_running = false;
						std::cout << "PlayerHit" << std::endl;
					}

				}

			}
			//player and enemy plane
			for (int countEnemy = 0; countEnemy < gameobject_list.returnSize(); countEnemy++)
			{
				GameObject* tempEnem = gameobject_list.returnAt(countEnemy);
				if (tempEnem->alive != false)
				{
					xDiff = tempEnem->unitBounds->x - player1->unitBounds->x;
					yDiff = tempEnem->unitBounds->y - player1->unitBounds->y;

					if (xDiff >= -62 && xDiff <= 62 && yDiff >= 0 && yDiff <= 62)
					{
						//game_running = false;
						std::cout << "PlayerHit" << std::endl;
					}
				}
			}

			Node* tempBullet = bullet_list.returnHead();
			Node* tempEnem = gameobject_list.returnHead();

			player1->Move();
			SDL_RenderCopy(gameRenderer, gameBG, NULL, Background_Rect);
			SDL_RenderCopy(gameRenderer, player1->unitTexture, NULL, player1->unitBounds);
			while (tempBullet != nullptr)
			{
				if (tempBullet != nullptr) {
					tempBullet->gmObject->Move();
				}

				if (tempBullet->gmObject->Alive() == true)
				{
					SDL_RenderCopy(gameRenderer, tempBullet->gmObject->unitTexture, NULL, tempBullet->gmObject->unitBounds);

				}

				if (tempBullet != nullptr)
				{
					tempBullet = tempBullet->next;
				}
			}

			while (tempEnem != nullptr)
			{
				if (tempEnem != nullptr) {
					tempEnem->gmObject->Move();
				}

				if (tempEnem->gmObject->Alive() == true)
				{
					if (gameFrames % 5000 == 0)
					{
						random = rand() % 10;
						if (random < 6)
						{
							GameObject* enemyBulletA = new Bullet(tempEnem->gmObject->x + 20, tempEnem->gmObject->y + 75);
							GameObject* enemyBulletB = new Bullet(tempEnem->gmObject->x + 40, tempEnem->gmObject->y + 75);
							enemyBulletA->isBulletFromEnemy = true;
							enemyBulletB->isBulletFromEnemy = true;

							if (tempEnem->gmObject->isRanger == true)
							{
								enemyBulletA->setImage(gameRenderer, "media/ranger_bullet.png");
								enemyBulletB->setImage(gameRenderer, "media/ranger_bullet.png");
							}
							else
							{
								enemyBulletA->setImage(gameRenderer, "media/nimble_bullet.png");
								enemyBulletB->setImage(gameRenderer, "media/nimble_bullet.png");
							}

							enemyBulletA->setUnitBounds(8, 16, tempEnem->gmObject->unitBounds->x + 20, tempEnem->gmObject->unitBounds->y + 75);
							enemyBulletB->setUnitBounds(8, 16, tempEnem->gmObject->unitBounds->x + 40, tempEnem->gmObject->unitBounds->y + 75);

							bullet_list.insertAtTail(enemyBulletA);
							bullet_list.insertAtTail(enemyBulletB);
						}
					}
					else if (gameFrames % 2000 == 0)
					{
						random = rand() % 10;
						if (random < 6)
						{
							GameObject* enemyBulletA = new Bullet(tempEnem->gmObject->x + 20, tempEnem->gmObject->y + 75);
							GameObject* enemyBulletB = new Bullet(tempEnem->gmObject->x + 40, tempEnem->gmObject->y + 75);
							enemyBulletA->isBulletFromEnemy = true;
							enemyBulletB->isBulletFromEnemy = true;

							if (tempEnem->gmObject->isRanger == true)
							{
								enemyBulletA->setImage(gameRenderer, "media/ranger_bullet.png");
								enemyBulletB->setImage(gameRenderer, "media/ranger_bullet.png");
							}
							else
							{
								enemyBulletA->setImage(gameRenderer, "media/nimble_bullet.png");
								enemyBulletB->setImage(gameRenderer, "media/nimble_bullet.png");
							}

							enemyBulletA->setUnitBounds(8, 16, tempEnem->gmObject->unitBounds->x + 20, tempEnem->gmObject->unitBounds->y + 75);
							enemyBulletB->setUnitBounds(8, 16, tempEnem->gmObject->unitBounds->x + 40, tempEnem->gmObject->unitBounds->y + 75);

							bullet_list.insertAtTail(enemyBulletA);
							bullet_list.insertAtTail(enemyBulletB);
						}
					}
					SDL_RenderCopy(gameRenderer, tempEnem->gmObject->unitTexture, NULL, tempEnem->gmObject->unitBounds);

				}

				if (tempEnem != nullptr)
				{
					tempEnem = tempEnem->next;
				}
			}



			SDL_RenderPresent(gameRenderer);
			SDL_RenderClear(gameRenderer);
			//SDL_UpdateWindowSurface(window);

			for (int count = 0; count < bullet_list.returnSize(); count++)
			{
				if (bullet_list.returnAt(count)->Alive() == false)
				{
					SDL_DestroyTexture(bullet_list.returnAt(count)->unitTexture);
					bullet_list.deleteNode(count);
					// now takes into account the middle of the list
					//gameobject_list.deleteNodeHead();
				}
			}

			for (int count = 0; count < gameobject_list.returnSize(); count++)
			{
				if (gameobject_list.returnAt(count)->Alive() == false)
				{
					SDL_DestroyTexture(gameobject_list.returnAt(count)->unitTexture);
					gameobject_list.deleteNode(count);
					// now takes into account the middle of the list
					//gameobject_list.deleteNodeHead();
				}
			}

			std::this_thread::sleep_for(std::chrono::milliseconds(2));
		}

		SDL_FreeSurface(background);
		SDL_FreeSurface(WindowSurface);

		background = NULL;
		WindowSurface = NULL;

		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(gameRenderer);

		SDL_Quit();

		this_thread::sleep_for(10000ms);
		return EXIT_SUCCESS;
	}
}