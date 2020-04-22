//  Vector2.hpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once

template <typename T>
class Vector2 {
public:
    Vector2() : x( 0 ), y( 0 ) {}
    Vector2( const T& _x, const T& _y ) : x( _x ), y( _y ) {}

    inline T getX() const { return x; }
    inline T getY() const { return y; }

    inline void setX( const T& _x ) { x = _x; }
    inline void setY( const T& _y ) { y = _y; }

private:
    T x;
    T y;
};

typedef Vector2<int> Vector2i;
