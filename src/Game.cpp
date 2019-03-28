//  Game.cpp
//  SnakeGame_OOP
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include "../include/Game.h"
#include "../include/Desk.h"
#include "../include/Apple.h"
#include "../include/Snake.h"
#include <ncurses.h>
#include <thread>
#include <ctime>

Game::Game() {
	initscr();
  	clear();
	noecho();
	cbreak();
	curs_set(0);
}

void Game::Launch(const int DeskHeight, const int DeskWidth) const {
	using namespace std::chrono_literals;

	Desk GameDesk(DeskHeight, DeskWidth);
	Snake snake(GameDesk.mHeight, GameDesk.mWidth);
	Apple apple(GameDesk.mHeight, GameDesk.mWidth);

	while (!snake.GetIsDead()) {
		GameDesk.Draw(&apple, &snake);
		GameDesk.Update(&apple, &snake);
	}	
	
	std::this_thread::sleep_for(1s);
	clear();
	mvprintw(DeskHeight/2, DeskWidth/2, "GAME OVER!");
	refresh();
	std::this_thread::sleep_for(2s);
	endwin();
}