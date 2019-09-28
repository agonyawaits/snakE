//  main.cpp
//  SnakeGame_OOP
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include <iostream>
#include "../include/Game.h"
#include <random>
#include <ctime>

#define 20 DESK_HEIGHT
#define 61 DESK_WIDTH

int main() {
	srand( time( nullptr ) );

	Game snakeGame;
	snakeGame.Launch( DESK_HEIGHT, DESK_WIDTH );

	return 0;
}