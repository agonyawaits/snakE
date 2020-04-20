//  Apple.cpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include "Apple.h"
#include "Desk.h"
#include <ncurses.h>

#define APPLE '@'

Apple::Apple( const Vector2i& position ) : Object( position ) {}

void Apple::draw( WINDOW* window ) const {
    mvwaddch( window, m_position.y, m_position.x, APPLE );
}

void Apple::update() {
    m_position = Desk::getRandomPosition();
}
