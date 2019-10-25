#pragma once

template <typename T>
class Vector2 {
public:
    Vector2();
    Vector2( T, T );

    T m_x;
    T m_y;
};

template <typename T>
Vector2<T>::Vector2() : m_x( 0 ), m_y( 0 ) {}

template <typename T>
Vector2<T>::Vector2( T t_x, T t_y ) : m_x( t_x ), m_y( t_y ) {}

typedef Vector2<int> Vector2i;