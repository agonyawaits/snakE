//  Object.hpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once
#include "Vector2.hpp"
#include <ncurses.h>

class Object {
public:
    Object( const Vector2i& position )
        : m_position( position ), m_alive( true ) {}

    virtual ~Object() {};

    virtual void draw( WINDOW* ) const = 0;
    virtual void update() = 0;
    virtual void extend() {}
    virtual void onInput( const int& ) {}

    inline int getX() const { return m_position.getX(); }
    inline int getY() const { return m_position.getY(); }
    inline void setX( const int& x ) { m_position.setX( x ); }
    inline void setY( const int& y ) { m_position.setY( y ); }

    inline Vector2i getPosition() const { return m_position; }
    inline void setPosition( const Vector2i& position ) { m_position = position; }

    inline bool alive() const { return m_alive; }
    inline void suicide() { m_alive = false; }

protected:
    Vector2i    m_position;
    bool        m_alive;
};
