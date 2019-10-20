//  Snake.cpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include "include/Snake.h"
#include <ncurses.h>

Snake::Snake( 
    int t_deskHeight,
    int t_deskWidth 
    ) : m_direction( NONE ) {
    m_deskHeight = t_deskHeight;
    m_deskWidth = t_deskWidth;
    m_xPos = t_deskWidth/2;
    m_yPos = t_deskHeight/2;
    m_isDead = false;
    m_snakeBody.push_back( SnakeSegment( m_xPos-1, m_yPos ) );
}

void Snake::draw() const {
    switch ( m_direction ) {
        case LEFT :
            mvprintw( m_yPos, m_xPos, "<" );
            break;

        case RIGHT :
            mvprintw( m_yPos, m_xPos, ">" );
            break;

        case UP :
            mvprintw( m_yPos, m_xPos, "^" );
            break;

        case DOWN :
            mvprintw( m_yPos, m_xPos, "v" );
            break;

        case NONE :
            mvprintw( m_yPos, m_xPos, ">" );
            break;
    }

    for ( const auto& seg : m_snakeBody ) {
        mvprintw( seg.m_yPos, seg.m_xPos, "o" );
    }
}

void Snake::onInput() {
    keypad( stdscr, TRUE );
    halfdelay( 1 );
    int userInput = getch();
    changeDirection( userInput );
}

void Snake::changeDirection( int t_playerInput ) {
    switch ( t_playerInput ) {
        case KEY_LEFT :
            m_direction = m_direction != RIGHT ? LEFT : m_direction;
            break;

        case KEY_RIGHT :
            m_direction = m_direction != LEFT ? RIGHT : m_direction;
            break;

        case KEY_UP :
            m_direction = m_direction != DOWN ? UP : m_direction;
            break;

        case KEY_DOWN :
            m_direction = m_direction != UP ? DOWN : m_direction;
            break;

        default : 
            break;
    }
}

void Snake::extend() {
    m_snakeBody.push_back(
        SnakeSegment(
            m_snakeBody[ m_snakeBody.size()-1 ].m_xPos, 
            m_snakeBody[ m_snakeBody.size()-1 ].m_yPos 
        )
    );
}

void Snake::update() {
    onInput();
    moveOneStepForward();
    m_isDead = hasDied();
}

void Snake::moveOneStepForward() {
    const int headPosX = m_xPos;
    const int headPosY = m_yPos;

    switch ( m_direction ) {
        case LEFT : 
            --m_xPos;
            break;

        case RIGHT : 
            ++m_xPos;
            break;

        case UP : 
            --m_yPos;
            break;

        case DOWN : 
            ++m_yPos;
            break;

        default : 
            return;
    }

    for ( int i = m_snakeBody.size()-1; i > 0; --i ) {
        m_snakeBody[ i ].m_xPos = m_snakeBody[ i-1 ].m_xPos;
        m_snakeBody[ i ].m_yPos = m_snakeBody[ i-1 ].m_yPos;
    }

    if ( !m_snakeBody.empty() ) {
        m_snakeBody[ 0 ].m_xPos = headPosX;
        m_snakeBody[ 0 ].m_yPos = headPosY;
    }
}

bool Snake::hasDied() const {
    for ( const auto& seg : m_snakeBody ) {
        if ( seg.m_xPos == m_xPos && seg.m_yPos == m_yPos ) {
            return true;
            break;
        }
    }

    if ( m_xPos == m_deskWidth-1 || m_yPos == m_deskHeight-1 ||
        m_xPos == 0 || m_yPos == 0 ) {
        return true;
    }

    return false;
}