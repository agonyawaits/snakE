#pragma once

struct V2 {
    V2() : m_x(0), m_y(0)
    {
    }

    V2(int x, int y) : m_x(x), m_y(y) 
    {
    }

    int x() const {
        return m_x;
    }

    int y() const {
        return m_y;
    }

    bool operator==(const V2 &other) const {
        return other.m_x == m_x && other.m_y == m_y;
    }

private:
    int m_x, m_y;
};
