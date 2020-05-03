#pragma once

template <typename T>
class Vector2 {
public:
    Vector2() : m_x(0), m_y(0) {}
    Vector2(const T& x, const T& y) : m_x(x), m_y(y) {}

    T x() const { return m_x; }
    T y() const { return m_y; }
    bool operator== (const Vector2& other) const {
        return other.m_x == m_x && other.m_y == m_y;
    }

private:
    T m_x;
    T m_y;
};

typedef Vector2<int> Vector2i;
