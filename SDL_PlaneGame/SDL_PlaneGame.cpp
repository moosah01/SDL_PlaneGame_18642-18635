#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>
#include "GameObject.h"
#include "Player.h"


const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;


int main(int argc, char* argv) {

	SDL_Renderer* gameRenderer;
	SDL_Surface* background;
	SDL_Surface* WindowSurface;
	GameObject* player1 = new Player(200, 520);
	

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {

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

	background = IMG_Load("media/gameBG.bmp");
	

	if (background == NULL) {
		std::cout << "Could not load background image. Error Code : " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	gameRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	player1->setImage(gameRenderer, "media/player_sprite.png");
	//Load Player Plane
	//SDL_Texture* Player = NULL;
	//Player = IMG_LoadTexture(R, "media/player_sprite.png");
	SDL_Texture* gameBG = IMG_LoadTexture(gameRenderer, "media/gameBG.bmp");

	player1->setUnitBounds(64, 64);

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

	while (true) {

		if (SDL_PollEvent(&window_event)) {

			if (SDL_QUIT == window_event.type) {
				break;
			}

			if (SDL_KEYDOWN == window_event.type) {
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
				if (SDLK_SPACE == window_event.key.keysym.sym) {

				}
				if (SDLK_b == window_event.key.keysym.sym) {

				}
			}

		}

		//Player Render

		
		SDL_RenderCopy(gameRenderer, gameBG, NULL, Background_Rect);
		SDL_RenderCopy(gameRenderer, player1->unitTexture, NULL, player1->unitBounds);
		player1->Move();
		SDL_RenderPresent(gameRenderer);
		SDL_RenderClear(gameRenderer);
		//SDL_UpdateWindowSurface(window);
	}

	SDL_FreeSurface(background);
	SDL_FreeSurface(WindowSurface);

	background = NULL;
	WindowSurface = NULL;

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(gameRenderer);

	SDL_Quit();

	return EXIT_SUCCESS;
}