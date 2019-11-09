//  Desk.h
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once
#include "Object.hpp"

class Desk final {
public:
    Desk( Object&,
          Object&,
          int& );

    void draw() const;
    void update( const int& ) const;
private:
    void drawSelf() const;
    void onInput ( const int& ) const;

    const int m_height, m_width;
    Object& m_snake;
    Object& m_food;
    int& m_score;
};
