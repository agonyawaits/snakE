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

void Game::Launch(
	const int deskHeight, 
	const int deskWidth
	) const {
	using namespace std::chrono_literals;

	Desk gameDesk( deskHeight, deskWidth );
	Snake snake( gameDesk.GetHeight(), gameDesk.GetWidth() );
	Apple apple( gameDesk.GetHeight(), gameDesk.GetWidth() );

	while ( !snake.GetIsDead() ) {
		gameDesk.Draw( &apple, &snake );
		gameDesk.Update( &apple, &snake );
	}	
	
	std::this_thread::sleep_for( 1s );
	clear();
	mvprintw( deskHeight/2, deskWidth/2, "GAME OVER!" );
	refresh();
	std::this_thread::sleep_for( 2s );
	endwin();
}