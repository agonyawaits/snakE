//  Snake.cpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include "Snake.h"
#include "Desk.h"
#include <ncurses.h>

Snake::Snake( const Vector2i& position )
    : Object( position ), m_direction( Direction::RIGHT ), m_isDead( false ) {}

void Snake::draw( WINDOW* window ) const {
    mvwaddch( window, getY(), getX(), currentHeadSymbol() );

    for ( const auto& seg : m_snakeBody ) {
        seg.draw( window );
    }
}

void Snake::update() {
    move();
    checkAndUpdateIfCollision();
}

void Snake::extend() {
    if ( m_snakeBody.empty() ) {
        m_snakeBody.emplace_back(
            SnakeSegment( Vector2i( getX(), getY() ) )
        );
    } else {
        m_snakeBody.emplace_back(
            SnakeSegment( Vector2i( m_snakeBody.back().getX(), m_snakeBody.back().getY() ) )
        );
    }
}

void Snake::onInput( const int& input ) {
    changeDirection( input );
}

void Snake::move() {
    moveBody();
    moveHead();
}

void Snake::checkAndUpdateIfCollision() {
    if ( crashedOut() || clashedMyself() ) {
        m_isDead = true;
    }
}

void Snake::changeDirection( const int& input ) {
    switch ( input ) {
        case KEY_LEFT :
            m_direction = m_direction != Direction::RIGHT ? Direction::LEFT : m_direction;
            break;

        case KEY_RIGHT :
            m_direction = m_direction != Direction::LEFT ? Direction::RIGHT : m_direction;
            break;

        case KEY_UP :
            m_direction = m_direction != Direction::DOWN ? Direction::UP : m_direction;
            break;

        case KEY_DOWN :
            m_direction = m_direction != Direction::UP ? Direction::DOWN : m_direction;
            break;

        default :
            break;
    }
}

void Snake::moveHead() {
    switch ( m_direction ) {
        case Direction::LEFT :
            --m_position.x;
            break;

        case Direction::RIGHT :
            ++m_position.x;
            break;

        case Direction::UP :
            --m_position.y;
            break;

        case Direction::DOWN :
            ++m_position.y;
            break;
    }
}

void Snake::moveBody() {
    for ( int i = m_snakeBody.size()-1; i > 0; --i ) {
        m_snakeBody[ i ].setX( m_snakeBody[ i-1 ].getX() );
        m_snakeBody[ i ].setY( m_snakeBody[ i-1 ].getY() );
    }

    if ( !m_snakeBody.empty() ) {
        m_snakeBody.front().setX( getX() );
        m_snakeBody.front().setY( getY() );
    }
}

chtype Snake::currentHeadSymbol() const {
    switch ( m_direction ) {
        case Direction::LEFT :
            return ACS_LARROW;

        case Direction::RIGHT :
            return ACS_RARROW;

        case Direction::UP :
            return ACS_UARROW;

        case Direction::DOWN :
            return ACS_DARROW;
    }
}

bool Snake::crashedOut() const {
    return getX() == Desk::width-1 || getY() == Desk::height-1 ||
        getX() == 0 || getY() == 0;
}

int Snake::clashedMyself() const {
    for ( const auto& seg : m_snakeBody ) {
        if ( seg.getX() == getX() && seg.getY() == getY() )
            return true;
    }

    return false;
}
