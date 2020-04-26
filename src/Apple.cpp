//  Apple.cpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include "Apple.h"
#include "Desk.h"
#include <ncurses.h>

#define APPLE '@'

Apple::Apple( const Vector2i& position ) : Object( position ) {}

void Apple::draw( WINDOW* window ) const {
    mvwaddch( window, getY(), getX(), APPLE );
}
