//  main.cpp
//  SnakeGame_OOP
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include <iostream>
#include "../include/Game.h"
#include <random>
#include <ctime>

using namespace std;

int main() {
	const int DeskHeight = 20; 
	const int DeskWidth = 61;

	srand(time(nullptr));

	Game SnakeGame;
	SnakeGame.Launch(DeskHeight, DeskWidth);
}