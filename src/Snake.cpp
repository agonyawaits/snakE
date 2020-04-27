//  Snake.cpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include "Snake.h"
#include "Desk.h"
#include <ncurses.h>

Snake::Snake( const Vector2i& position )
    : Object( position ), m_direction( Direction::RIGHT ) {}

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
            SnakeSegment( m_position )
        );
    } else {
        m_snakeBody.emplace_back(
            SnakeSegment( m_snakeBody.back().getPosition() )
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
    if ( clashedMyself() ) {
        suicide();
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
            m_position.setX( m_position.getX()-1 );
            break;

        case Direction::RIGHT :
            m_position.setX( m_position.getX()+1 );
            break;

        case Direction::UP :
            m_position.setY( m_position.getY()-1 );
            break;

        case Direction::DOWN :
            m_position.setY( m_position.getY()+1 );
            break;
    }
}

void Snake::moveBody() {
    for ( int i = m_snakeBody.size()-1; i > 0; --i ) {
        m_snakeBody[ i ].setPosition( m_snakeBody[ i-1 ].getPosition() );
    }

    if ( !m_snakeBody.empty() ) {
        m_snakeBody.front().setPosition( m_position );
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

int Snake::clashedMyself() const {
    for ( const auto& seg : m_snakeBody ) {
        if ( seg.getPosition() == m_position ) {
            return true;
        }
    }

    return false;
}
