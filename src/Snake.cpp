//  Snake.cpp
//  SnakeGame_OOP
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include "../include/Snake.h"
#include <ncurses.h>
#include <fstream>

Snake::Snake(int deskHeight, int deskWidth)
	: mDirection(NONE),
	  mScore(0),
	  mHighScore(0)
{
	std::fstream fin;
	fin.open("highscore.txt", std::ios::in);
	if (fin.is_open()) {
		fin >> mHighScore;
		fin.close();
	}

	Figure::mDeskHeight = deskHeight;
	Figure::mDeskWidth = deskWidth;
	Figure::mX = deskWidth/2;
	Figure::mY = deskHeight/2;
	Figure::mIsDead = false;
}

int Snake::GetScore() const { return mScore; }
int Snake::GetHighScore() const { return mHighScore; }

void Snake::Draw() const {
	switch (mDirection) {
		case LEFT : 
		mvprintw(mY, mX, "<");
		break;
		
		case RIGHT : 
			mvprintw(mY, mX, ">");
			break;

		case UP : 
			mvprintw(mY, mX, "^");
			break;

		case DOWN : 
			mvprintw(mY, mX, "v");
			break;

		case NONE :
			break;
	}
	
	for (const auto& seg : mSnakeBody) {
		mvprintw(seg.mY, seg.mX, "o");
	}
	mvprintw(mDeskHeight+2, 0, "Score: %d", mScore);
	mvprintw(mDeskHeight+3, 0, "Highscore: %d", mHighScore);
}

void Snake::OnInput() {
	keypad(stdscr, TRUE);
	halfdelay(1);

	int input = getch();
	switch (input) {
		case KEY_LEFT :
			if (mDirection != RIGHT) {
				mDirection = LEFT;	
			}
			break;
		case KEY_RIGHT :
			if (mDirection != LEFT) {
				mDirection = RIGHT;	
			}
			break;
		case KEY_UP :
			if (mDirection != DOWN) {
				mDirection = UP;	
			}
			break;
		case KEY_DOWN :
			if (mDirection != UP) {
				mDirection = DOWN;	
			}
			break;

		default : break;
	}

}

void Snake::LevelUp() {
	mScore += 10;
	if (mSnakeBody.empty()) {
		SnakeSegment* newSegment = new SnakeSegment(mX, mY);
		mSnakeBody.push_back(*newSegment);
		delete newSegment;
	} else {
		SnakeSegment* newSegment = new SnakeSegment(mSnakeBody[mSnakeBody.size()-1].mX, mSnakeBody[mSnakeBody.size()-1].mY);
		mSnakeBody.push_back(*newSegment);
		delete newSegment;
	}
}

void Snake::Update() {
	int tempX = mX, tempY = mY;

	switch (mDirection) {
		case LEFT : 
			--mX;
			break;
		
		case RIGHT : 
			++mX;
			break;

		case UP : 
			--mY;
			break;

		case DOWN : 
			++mY;
			break;

		default : break;
	}

	for (int i = mSnakeBody.size()-1; i > 0; --i) {
		mSnakeBody[i].mX = mSnakeBody[i-1].mX;
		mSnakeBody[i].mY = mSnakeBody[i-1].mY;
	}
	if (!mSnakeBody.empty()) {
		mSnakeBody[0].mX = tempX;
		mSnakeBody[0].mY = tempY;
	}

	for (const auto& seg : mSnakeBody) {
		if (seg.mX == mX && seg.mY == mY) {
			mIsDead = true;
			break;
		}
	}

	if (mX == mDeskWidth-1 || mY == mDeskHeight-1 || mX == 0 || mY == 0) {
		mIsDead = true;
	}
}

Snake::~Snake() {
	if (mScore > mHighScore) {
		mHighScore = mScore;
		std::fstream fout;
		fout.open("highscore.txt", std::ios::out);
		if (fout.is_open()) {
			fout << mHighScore;
			fout.close();
		}
	}

}