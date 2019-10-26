//  Apple.cpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include "include/Apple.h"
#include <random>
#include <ncurses.h>
#include "include/Config.hpp"

Apple::Apple() {
    m_position.m_x = ( rand() % ( Config::deskWidth-2 ) ) + 1;
    m_position.m_y = ( rand() % ( Config::deskHeight-2 ) ) + 1;
}

void Apple::draw() const {
    mvprintw( m_position.m_y, m_position.m_x, "@" );
}

void Apple::update() {
    m_position.m_x = ( rand() % ( Config::deskWidth-2 ) ) + 1;
    m_position.m_y = ( rand() % ( Config::deskHeight-2 ) ) + 1;
}
