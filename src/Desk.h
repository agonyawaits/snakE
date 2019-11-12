//  Desk.h
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once
#include "Object.hpp"
#include <ncurses.h>

class Desk final {
public:
    static const int height = 20;
    static const int width = 60;
    
public:
    Desk( Object&, Object& );

    void draw( WINDOW* ) const;
    void update( const int& ) const;

private:
    void onInput( const int& ) const;

    Object& m_char;
    Object& m_food;
};
