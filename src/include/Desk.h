//  Desk.h
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once
#include "Object.hpp"

class Desk final {
public:
    Desk();
    void draw( const Object&, const Object&, const int&, const int& ) const;
    void update( Object&, Object&, int& );
private:
    void draw() const;
    const int m_height, m_width;
};
