//  main.cpp
//  SnakeGame_OOP
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include <iostream>
#include "../include/Game.h"
#include <random>
#include <ctime>

#define DESK_HEIGHT 20
#define DESK_WIDTH 61

int main() {
	srand( time( nullptr ) );

	Game snakeGame;
	snakeGame.launch( DESK_HEIGHT, DESK_WIDTH );

	return 0;
}