//  Desk.cpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include "include/Desk.h"
#include <ncurses.h>

Desk::Desk(
    const int t_height, 
    const int t_width
    ) : m_height( t_height ), m_width( t_width ) {}

void Desk::draw(
    const Figure& t_food, 
    const Figure& t_character,
    const int& t_score,
    const int& t_highScore
    ) const {
    clear();

    for ( int i = 0; i < m_height; ++i ) {
        for ( int j = 0; j < m_width; ++j ) {

            if ( ( i == 0 && j % 2 == 0 ) ||
                ( i == m_height - 1 && j % 2 == 0 ) ||
                ( j == 0 ) || ( j == m_width - 1 ) ) {
                mvprintw( i, j, "*" );
            } else if ( j == t_character.getX() && i == t_character.getY() ) {
                t_character.draw();
            } else if ( j == t_food.getX() && i == t_food.getY() ) {
                t_food.draw();
            }
        }
    }
    mvprintw( m_height+2, 0, "Score: %d", t_score );
    mvprintw( m_height+3, 0, "Highscore: %d", t_highScore );

    refresh();
}

void Desk::update(
    Figure& t_food, 
    Figure& t_character,
    int& t_score
    ) {
    t_character.update();
    if ( t_food.getX() == t_character.getX() && t_food.getY() == t_character.getY() ) {
        t_food.update();
        t_character.extend();
        t_score += 10;
    }
}
