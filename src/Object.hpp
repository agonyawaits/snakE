//  Object.hpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once
#include "Vector2.hpp"
#include <ncurses.h>

class Object {
public:
    Object( const Vector2i& position ) : m_position( position ) {}

    virtual ~Object() {};

    virtual void draw( WINDOW* ) const = 0;
    virtual void update() = 0;
    virtual void extend() {}
    virtual void onInput( const int& ) {}

    inline int getX() const { return m_position.getX(); }
    inline int getY() const { return m_position.getY(); }
    inline void setX( const int& x ) { m_position.setX( x ); }
    inline void setY( const int& y ) { m_position.setY( y ); }

protected:
    Vector2i m_position;
};
