//  Desk.h
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once
#include "Object.hpp"
#include "Vector2.hpp"
#include <ncurses.h>

class Desk final {
public:
    Desk( const int&, const int& );

    inline int height() const { return m_height; }
    inline int width() const { return m_width; }

    inline void setHero( Object* hero ) { m_hero = hero; }
    inline void setFood( Object* food ) { m_food = food; }

    void draw( WINDOW* ) const;
    void update( const int& );
    Vector2i getRandomPosition() const;
private:
    bool initialized() const;
    void onInput( const int& ) const;
    bool heroHasCrashed() const;
    void killHero();

    int         m_height;
    int         m_width;
    Object*     m_hero;
    Object*     m_food;
};
