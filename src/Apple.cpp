//  Apple.cpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include "Apple.h"
#include "Config.hpp"
#include <random>
#include <ncurses.h>

Apple::Apple() {
    m_position.x = rand() % ( Config::deskWidth-2 ) + 1;
    m_position.y = rand() % ( Config::deskHeight-2 ) + 1;
}

void Apple::draw( WINDOW* window ) const {
    mvwprintw( window, m_position.y, m_position.x, "@" );
}

void Apple::update() {
    m_position.x = rand() % ( Config::deskWidth-2 ) + 1;
    m_position.y = rand() % ( Config::deskHeight-2 ) + 1;
}
