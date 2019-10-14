//  Snake.cpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include "include/Snake.h"
#include <ncurses.h>

Snake::Snake( 
    int t_deskHeight,
    int t_deskWidth 
    ) : m_direction( NONE ) 
{
    m_deskHeight = t_deskHeight;
    m_deskWidth = t_deskWidth;
    m_x = t_deskWidth/2;
    m_y = t_deskHeight/2;
    m_isDead = false;

    m_snakeBody.push_back( SnakeSegment( m_x-1, m_y ) );
}

void Snake::draw() const {
    switch ( m_direction ) {
        case LEFT :
            mvprintw( m_y, m_x, "<" );
            break;

        case RIGHT :
            mvprintw( m_y, m_x, ">" );
            break;

        case UP :
            mvprintw( m_y, m_x, "^" );
            break;

        case DOWN :
            mvprintw( m_y, m_x, "v" );
            break;

        case NONE :
            mvprintw( m_y, m_x, ">" );
            break;
    }

    for ( const auto& seg : m_snakeBody ) {
        mvprintw( seg.m_y, seg.m_x, "o" );
    }
}

void Snake::onInput() {
    keypad( stdscr, TRUE );
    halfdelay( 1 );

    int input = getch();
    switch ( input ) {
        case KEY_LEFT :
            if ( m_direction != RIGHT ) {
                m_direction = LEFT;
            }
            break;

        case KEY_RIGHT :
            if ( m_direction != LEFT ) {
                m_direction = RIGHT;
            }
            break;

        case KEY_UP :
            if ( m_direction != DOWN ) {
                m_direction = UP;
            }
            break;

        case KEY_DOWN :
            if ( m_direction != UP ) {
                m_direction = DOWN;
            }
            break;

        default : 
            break;
    }

}

void Snake::extend() {
    m_snakeBody.push_back(
        SnakeSegment(
            m_snakeBody[ m_snakeBody.size()-1 ].m_x, 
            m_snakeBody[ m_snakeBody.size()-1 ].m_y 
        )
    );
}

void Snake::update() {
    onInput();

    const int tempHeadX = m_x;
    const int tempHeadY = m_y;

    switch ( m_direction ) {
        case LEFT : 
            --m_x;
            break;

        case RIGHT : 
            ++m_x;
            break;

        case UP : 
            --m_y;
            break;

        case DOWN : 
            ++m_y;
            break;

        default : 
            return;
    }

    for ( int i = m_snakeBody.size()-1;
        i > 0;
        --i ) {
        m_snakeBody[ i ].m_x = m_snakeBody[ i-1 ].m_x;
        m_snakeBody[ i ].m_y = m_snakeBody[ i-1 ].m_y;
    }

    if ( !m_snakeBody.empty() ) {
        m_snakeBody[ 0 ].m_x = tempHeadX;
        m_snakeBody[ 0 ].m_y = tempHeadY;
    }

    for ( const auto& seg : m_snakeBody ) {
        if ( seg.m_x == m_x && seg.m_y == m_y ) {
            m_isDead = true;
            break;
        }
    }

    if ( m_x == m_deskWidth-1 ||
        m_y == m_deskHeight-1 ||
        m_x == 0 || m_y == 0 ) 
    {
        m_isDead = true;
    }
}