//  Desk.cpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include "Desk.h"
#include "Object.hpp"
#include "Vector2.hpp"
#include <random>
#include <ncurses.h>

Desk::Desk( const int& height, const int& width )
    : m_height( height ), m_width( width ), m_hero( nullptr ), m_food( nullptr ) {}

void Desk::draw( WINDOW* window ) const {
    if ( !initialized() ) {
        return;
    }

    box( window, 0, 0 );
    m_hero->draw( window );
    m_food->draw( window );
}

void Desk::update( const int& input ) {
    if ( !initialized() ) {
        return;
    }
    
    onInput( input );

    m_hero->update();

    if ( heroHasCrashed() ) {
        if ( m_hero->alive() ) {
            killHero();
        }

        return;
    }

    if ( m_food->getPosition() == m_hero->getPosition() ) {
        m_food->setPosition( getRandomPosition() );
        m_hero->extend();
    }
}

bool Desk::initialized() const {
    return m_hero != nullptr && m_food != nullptr;
}

void Desk::onInput( const int& input ) const {
    m_hero->onInput( input );
    m_food->onInput( input );
}

Vector2i Desk::getRandomPosition() const {
    return Vector2i(
        rand() % ( m_width-2 ) + 1,
        rand() % ( m_height-2 ) + 1
    );
}

bool Desk::heroHasCrashed() const {
    return m_hero->getX() == m_width-1 || m_hero->getY() == m_height-1 ||
        m_hero->getX() == 0 ||  m_hero->getY() == 0;
}

void Desk::killHero() {
    m_hero->suicide();
}
