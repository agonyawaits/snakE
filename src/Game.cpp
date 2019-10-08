//  Game.cpp
//  snake
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
	curs_set( 0 );
}

void Game::launch(
	const int t_deskHeight, 
	const int t_deskWidth
	) const {
	using namespace std::chrono_literals;

	Desk gameDesk( t_deskHeight, t_deskWidth );
	Snake snake( t_deskHeight, t_deskWidth );
	Apple apple( t_deskHeight, t_deskWidth );

	while ( !snake.getIsDead() ) {
		gameDesk.draw( &apple, &snake );
		gameDesk.update( &apple, &snake );
	}	
	
	std::this_thread::sleep_for( 1s );
	clear();
	mvprintw( t_deskHeight/2, t_deskWidth/2, "GAME OVER!" );
	refresh();
	std::this_thread::sleep_for( 2s );
	endwin();
}
