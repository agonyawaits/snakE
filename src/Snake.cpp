//  Snake.cpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include "include/Snake.h"
#include <ncurses.h>
#include "include/Config.hpp"

Snake::Snake() : m_direction( RIGHT ), m_isDead( false ) {
    m_position.m_x = Config::deskWidth/2;
    m_position.m_y = Config::deskHeight/2;
}

void Snake::draw() const {
    switch ( m_direction ) {
        case LEFT :
            mvprintw( m_position.m_y, m_position.m_x, "<" );
            break;

        case RIGHT :
            mvprintw( m_position.m_y, m_position.m_x, ">" );
            break;

        case UP :
            mvprintw( m_position.m_y, m_position.m_x, "^" );
            break;

        case DOWN :
            mvprintw( m_position.m_y, m_position.m_x, "v" );
            break;

        default:
            break;
    }

    for ( auto seg : m_snakeBody ) {
        mvprintw( seg.m_position.m_y, seg.m_position.m_x, "o" );
    }
}

void Snake::onInput() {
    keypad( stdscr, TRUE );
    halfdelay( 1 );
    int playerInput = getch();
    changeDirection( playerInput );
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
    if ( m_snakeBody.empty() ) {
        m_snakeBody.push_back( SnakeSegment( m_position.m_x, m_position.m_y) );    
    } else {
        m_snakeBody.push_back(
            SnakeSegment(
                m_snakeBody[ m_snakeBody.size()-1 ].m_position.m_x, 
                m_snakeBody[ m_snakeBody.size()-1 ].m_position.m_y
            )
        );
    }
}

void Snake::update() {
    onInput();
    move();
    m_isDead = checkCollision();
}

void Snake::move() {
    const int headPosX = m_position.m_x;
    const int headPosY = m_position.m_y;

    switch ( m_direction ) {
        case LEFT : 
            --m_position.m_x;
            break;

        case RIGHT : 
            ++m_position.m_x;
            break;

        case UP : 
            --m_position.m_y;
            break;

        case DOWN : 
            ++m_position.m_y;
            break;

        default : 
            return;
    }

    for ( int i = m_snakeBody.size()-1; i > 0; --i ) {
        m_snakeBody[ i ].m_position.m_x = m_snakeBody[ i-1 ].m_position.m_x;
        m_snakeBody[ i ].m_position.m_y = m_snakeBody[ i-1 ].m_position.m_y;
    }

    if ( !m_snakeBody.empty() ) {
        m_snakeBody[ 0 ].m_position.m_x = headPosX;
        m_snakeBody[ 0 ].m_position.m_y = headPosY;
    }
}

bool Snake::checkCollision() const {
    for ( auto seg : m_snakeBody ) {
        if ( seg.m_position.m_x == m_position.m_x && seg.m_position.m_y == m_position.m_y ) {
            return true;
        }
    }

    if ( m_position.m_x == Config::deskWidth-1 ||
        m_position.m_y == Config::deskHeight-1 ||
        m_position.m_x == 0 || m_position.m_y == 0 ) {
        return true;
    }

    return false;
}

bool Snake::isDead() const {
    return m_isDead;
}