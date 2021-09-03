#pragma once

struct V2 {
    V2() : x(0), y(0)
    {
    }

    V2(int _x, int _y) : x(_x), y(_y) 
    {
    }

    bool operator==(const V2 &other) const {
        return other.x == x && other.y == y;
    }

    int x, y;
};
