#include "../include/Desk.h"
#include <ncurses.h>

Desk::Desk(const int height, const int width) 
	: mHeight(height),
	  mWidth(width) {} 

void Desk::Draw(Figure* mFood, Figure* mCharacter) const {
	clear();

	for (int i = 0; i < mHeight; ++i) {
		for (int j = 0; j < mWidth; ++j) {
			if (i == 0 && j % 2 == 0) {
				mvprintw(i, j, "*");
			} else if (i == mHeight - 1 && j % 2 == 0) {
				mvprintw(i, j, "*");
			} else if (j == 0) {
				mvprintw(i, j, "*");
			} else if (j == mWidth - 1) {
				mvprintw(i, j, "*");
			} else if (j == mCharacter->GetX() && i == mCharacter->GetY()) {
				mCharacter->Draw();
			} else if (j == mFood->GetX() && i == mFood->GetY()) {
				mFood->Draw();
			}
		}
	}

	refresh();
}

void Desk::OnInput(Figure* mCharacter) {
	mCharacter->OnInput();
}

void Desk::Update(Figure* mFood, Figure* mCharacter) {
	mCharacter->OnInput();

	mCharacter->Update();
	if (mFood->GetX() == mCharacter->GetX() && mFood->GetY() == mCharacter->GetY()) {
		mFood->Update();
		mCharacter->LevelUp();
	}
}