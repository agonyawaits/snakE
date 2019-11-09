//  Desk.cpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include "Desk.h"
#include "Config.hpp"
#include "Object.hpp"
#include <ncurses.h>

Desk::Desk( Object& t_snake,
            Object& t_food,
            int& t_score )
    : m_height( Config::deskHeight ), m_width( Config::deskWidth ),
    m_snake( t_snake ), m_food( t_food ), m_score( t_score ) {}

void Desk::draw() const {
    clear();

    drawSelf();
    m_snake.draw();
    m_food.draw();
    mvprintw( m_height+1, 0, "Score: %d", m_score );

    refresh();
}

void Desk::update( const int& t_playerInput ) const {
    onInput( t_playerInput );
    m_snake.update();

    if ( m_food.getX() == m_snake.getX() && 
        m_food.getY() == m_snake.getY() )
    {
        m_food.update();
        m_snake.extend();
    }

    m_score = m_snake.size() * 10;
}

void Desk::drawSelf() const {
    for ( int i = 0; i < m_height; ++i ) {
        for ( int j = 0; j < m_width; ++j ) {
            if ( ( i == 0 && j % 2 == 0 ) ||
                ( i == m_height - 1 && j % 2 == 0 ) ||
                ( j == 0 ) || ( j == m_width - 1 ) )
            {
                mvprintw( i, j, "*" );
            }
        }
    }
}

void Desk::onInput( const int& t_playerInput ) const {
    m_snake.onInput( t_playerInput );
}