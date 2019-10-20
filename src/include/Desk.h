//  Desk.h
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once
#include "Figure.hpp"

class Desk {
public:
    Desk( int, int );

    inline int getHeight() const { return m_height; }
    inline int getWidth() const { return m_width; }

    void draw( const Figure&, const Figure&, const int&, const int& ) const;
    void update( Figure&, Figure&, int& );

private:
    const int m_height, m_width;
};
