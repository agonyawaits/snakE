//  Desk.cpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include "include/Desk.h"
#include <ncurses.h>
#include "include/Config.hpp"
#include "include/Object.hpp"

Desk::Desk() 
    : m_height( Config::deskHeight ), m_width( Config::deskWidth ) {}

void Desk::draw(
    const Object& t_food, 
    const Object& t_character,
    const int& t_score,
    const int& t_highScore ) const 
{
    clear();

    draw();
    t_character.draw();
    t_food.draw();
    mvprintw( m_height+2, 0, "Score: %d", t_score );
    mvprintw( m_height+3, 0, "Highscore: %d", t_highScore );

    refresh();
}

void Desk::update(
    Object& t_food, 
    Object& t_character,
    int& t_score ) 
{
    t_character.update();
    if ( t_food.getX() == t_character.getX() && 
        t_food.getY() == t_character.getY() ) 
    {
        t_food.update();
        t_character.extend();
    }
    t_score = t_character.size() * 10;
}

void Desk::draw() const {
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