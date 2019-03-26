#include "../include/Apple.h"
#include <random>
#include <ncurses.h>

Apple::Apple(const int deskHeight, const int deskWidth) {
	Figure::mDeskHeight = deskHeight;
	Figure::mDeskWidth = deskWidth;
	Figure::mIsDead = false;
	Figure::mX = (rand() % (mDeskWidth-2)) + 1;
	Figure::mY = (rand() % (mDeskHeight-2)) + 1;
}

void Apple::Draw() const {
	mvprintw(mY, mX, "@");
}

void Apple::Update() {
	Figure::mX = (rand() % (mDeskWidth-2)) + 1;
	Figure::mY = (rand() % (mDeskHeight-2)) + 1;
}