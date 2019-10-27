//  Desk.h
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once
#include "Object.hpp"

class Desk {
public:
    Desk();

    void draw( const Object&, const Object&, const int&, const int& ) const;
    void update( Object&, Object&, int& );
private:
    const int m_height, m_width;
};
