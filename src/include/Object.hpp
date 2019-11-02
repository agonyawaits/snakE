//  Object.hpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once
#include "Vector2.hpp"

class Object {
public:
    virtual ~Object() {};

    virtual void draw() const = 0;
    virtual void onInput( const int& ) {};
    virtual void update() = 0;
    virtual void extend() {};
    virtual int size() const { return 0; };

    inline int getX() const { return m_position.x; }
    inline int getY() const { return m_position.y; }
protected:
    Vector2i m_position;
};
