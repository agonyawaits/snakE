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

void Game::Launch(const int mDeskHeight, const int mDeskWidth) const {
	using namespace std::chrono_literals;

	Desk GameDesk(mDeskHeight, mDeskWidth);
	Snake mSnake(GameDesk.mHeight, GameDesk.mWidth);
	Apple mApple(GameDesk.mHeight, GameDesk.mWidth);

	while (!mSnake.GetIsDead()) {
		GameDesk.Draw(&mApple, &mSnake);
		GameDesk.OnInput(&mSnake);
		GameDesk.Update(&mApple, &mSnake);
	}	
	
	clear();
	mvprintw(mDeskHeight/2, mDeskWidth/2, "GAME OVER!");
	refresh();
	std::this_thread::sleep_for(2s);
	endwin();
}