//  Apple.cpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include "include/Apple.h"
#include <random>
#include <ncurses.h>

Apple::Apple( 
    const int t_deskHeight, 
    const int t_deskWidth 
    ) {
    m_deskHeight = t_deskHeight;
    m_deskWidth = t_deskWidth;
    m_isDead = false;
    m_xPos = ( rand() % ( m_deskWidth-2 ) ) + 1;
    m_yPos = ( rand() % ( m_deskHeight-2 ) ) + 1;
}

void Apple::draw() const {
    mvprintw( m_yPos, m_xPos, "@" );
}

void Apple::update() {
    m_xPos = ( rand() % ( m_deskWidth-2 ) ) + 1;
    m_yPos = ( rand() % ( m_deskHeight-2 ) ) + 1;
}
