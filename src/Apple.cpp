//  Apple.cpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include "Apple.h"
#include "Desk.h"
#include <random>
#include <ncurses.h>

#define APPLE '@'

Apple::Apple() {
    m_position.x = rand() % ( Desk::width-2 ) + 1;
    m_position.y = rand() % ( Desk::height-2 ) + 1;
}

void Apple::draw( WINDOW* window ) const {
    mvwaddch( window, m_position.y, m_position.x, APPLE );
}

void Apple::update() {
    m_position.x = rand() % ( Desk::width-2 ) + 1;
    m_position.y = rand() % ( Desk::height-2 ) + 1;
}
