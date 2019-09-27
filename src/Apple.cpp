//  Apple.cpp
//  SnakeGame_OOP
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include "../include/Apple.h"
#include <random>
#include <ncurses.h>

Apple::Apple( 
	const int deskHeight, 
	const int deskWidth 
	) {
	Figure::m_deskHeight = deskHeight;
	Figure::m_deskWidth = deskWidth;
	Figure::m_isDead = false;
	Figure::m_x = ( rand() % ( m_deskWidth-2 ) ) + 1;
	Figure::m_y = ( rand() % ( m_deskHeight-2 ) ) + 1;
}

void Apple::Draw() const {
	mvprintw( m_y, m_x, "@" );
}

void Apple::Update() {
	m_x = ( rand() % ( m_deskWidth-2 ) ) + 1;
	m_y = ( rand() % ( m_deskHeight-2 ) ) + 1;
}