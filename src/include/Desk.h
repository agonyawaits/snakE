//  Desk.h
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once
#include "Object.hpp"

class Desk {
public:
    Desk();

    inline int getHeight() const { return m_height; }
    inline int getWidth() const { return m_width; }

    void draw( const Object&, const Object&, const int&, const int& ) const;
    void update( Object&, Object&, int& );

private:
    const int m_height, m_width;
};
