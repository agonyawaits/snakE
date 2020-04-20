//  Vector2.hpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once

template <typename T>
class Vector2 {
public:
    Vector2();
    Vector2( const T&, const T& );

    T m_x;
    T m_y;
};

template <typename T>
Vector2<T>::Vector2() : m_x( 0 ), m_y( 0 ) {}

template <typename T>
Vector2<T>::Vector2( const T& x, const T& y ) : m_x( x ), m_y( y ) {}

typedef Vector2<int> Vector2i;
