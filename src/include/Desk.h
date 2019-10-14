//  Desk.h
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once
#include "Figure.hpp"

class Desk {
public:
    Desk( int, int );

    int getHeight() const;
    int getWidth() const;

    void draw( Figure*, Figure*, const int&, const int& ) const;
    void update( Figure*, Figure*, int& );

private:
    const int m_height, m_width;
};
