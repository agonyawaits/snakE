//  Desk.cpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include "Desk.h"
#include "Object.hpp"
#include <ncurses.h>

Desk::Desk( Object& character, Object& food )
    : m_char( character ), m_food( food ) {}

void Desk::draw( WINDOW* window ) const {
    box( window, 0, 0 );
    m_char.draw( window );
    m_food.draw( window );
}

void Desk::update( const int& input ) const {
    onInput( input );
    m_char.update();

    if (m_food.getX() == m_char.getX() && 
        m_food.getY() == m_char.getY())
    {
        m_food.update();
        m_char.extend();
    }
}

void Desk::onInput( const int& input ) const {
    m_char.onInput( input );
}