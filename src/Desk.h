//  Desk.h
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once
#include "Object.hpp"
#include <ncurses.h>

class Desk final {
public:
    Desk( Object&, Object& );

    void draw( WINDOW* ) const;
    void update( const int& ) const;

private:
    void onInput( const int& ) const;

    const int m_height, m_width;
    Object& m_char;
    Object& m_food;
};
