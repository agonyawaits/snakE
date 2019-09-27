//  Desk.cpp
//  SnakeGame_OOP
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include "../include/Desk.h"
#include <ncurses.h>

Desk::Desk(
	const int height, 
	const int width
	) : m_height(height), m_width(width) {} 

void Desk::Draw(
	Figure* food, 
	Figure* character
	) const {

	clear();

	for ( int i = 0; i < m_height; ++i ) {
		for ( int j = 0; j < m_width; ++j ) {

			if ( ( i == 0 && j % 2 == 0 ) ||
				( i == m_height - 1 && j % 2 == 0 ) ||
				( j == 0 ) || ( j == m_width - 1 ) ) {

				mvprintw( i, j, "*" );

			} else if ( j == character->GetX() && i == character->GetY() ) {

				character->Draw();

			} else if ( j == food->GetX() && i == food->GetY() ) {

				food->Draw();

			}
		}
	}

	refresh();
}

void Desk::OnInput( Figure* character ) {
	character->OnInput();
}

void Desk::Update(
	Figure* food, 
	Figure* character 
	) {
	OnInput( character );

	character->Update();

	if ( food->GetX() == character->GetX() && 
		food->GetY() == character->GetY() ) {

		food->Update();
		character->Extend();
	}

}