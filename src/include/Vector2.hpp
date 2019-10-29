//  Vector2.hpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once

template <typename T>
class Vector2 {
public:
    Vector2();
    Vector2( const T&, const T& );

    T x;
    T y;
};

template <typename T>
Vector2<T>::Vector2() : x( 0 ), y( 0 ) {}

template <typename T>
Vector2<T>::Vector2( const T& t_x, const T& t_y ) : x( t_x ), y( t_y ) {}

typedef Vector2<int> Vector2i;