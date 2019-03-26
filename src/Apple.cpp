#include "../include/Apple.h"
#include <random>
#include <ncurses.h>

Apple::Apple(const int deskHeight, const int deskWidth) 
	: mDeskHeight(deskHeight),
	  mDeskWidth(deskWidth) 
{
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