#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <SDL.h>


namespace CFG {

	/* Window Settings */
	static int SCREEN_WIDTH = 800;
	static int SCREEN_HEIGHT = 600;
	static bool SHOW_CURSOR = SDL_DISABLE;

	/* Game Settings */
	static float GAME_BORDER_X1 = 21.0f;
	static float GAME_BORDER_X2 = 776.0f;
	static float GAME_BORDER_Y1 = 46.0f;
	static float GAME_BORDER_Y2 = 579.0f;

	/* Number of Objects */
	static unsigned int MAX_CARROTS = 20;
	static unsigned int MAX_FLOWERS_DEAD = 12;
	static unsigned int MAX_FLOWERS_SLOW = 4;
	static unsigned int MAX_FLOWERS_MAD = 1;
	static unsigned int MAX_FLOWERS_INVERTED = 1;
	static unsigned int MAX_FLOWERS_SPEED = 2;

	/* Object Properties */
	static float FLOWER01_SIZE_X = 10.0f;
	static float FLOWER01_SIZE_Y = 18.0f;
	static float FLOWER02_SIZE_X = 19.0f;
	static float FLOWER02_SIZE_Y = 32.0f;

	/* Player Settings */
	static float P1_SPAWN_POS_X = (SCREEN_WIDTH / 3.0f);
	static float P1_SPAWN_POS_Y = (SCREEN_HEIGHT / 2.0f);
	static float P2_SPAWN_POS_X = (SCREEN_WIDTH / 3 * 2.0f);
	static float P2_SPAWN_POS_Y = (SCREEN_HEIGHT / 2.0f);
	static float PLAYER_SIZE_X = 45.0f;
	static float PLAYER_SIZE_Y = 37.0f;
	static float START_SPEED = 64.0f;
	static float SPEED_INCREASE = 16.0f;
	static float SPEED_DECREASE = 20.0f;
	static Uint32 POISON_TIME = 10 * 1000;
	static Uint32 POISON_TIME_INCREASE = 3 * 1000;
	static Uint32 INVERTED_CONTROLS_TIME = 4 * 1000;


	/* Font and Color Settings*/
	static SDL_Color PLAYER_1 = { 127, 127, 255, 255 };
	static SDL_Color PLAYER_2 = { 255, 127, 127, 255 };
	static SDL_Color PLAYER_FONT_1 = { 12, 255, 255, 255 };
	static SDL_Color PLAYER_FONT_2 = { 255, 44, 44, 255 };
	static SDL_Color MAP_COLOR = { 235, 235, 235, 255 };
	static SDL_Color WHITE_COLOR = { 255, 255, 255, 255 };
	static SDL_Color BLACK_COLOR = { 0, 0, 0, 255 };

}

#endif 