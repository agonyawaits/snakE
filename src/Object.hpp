#pragma once

#include "Vector2.hpp"
#include "Direction.hpp"
#include <ncurses.h>

class Object {
public:
    Object();
    Object(const Vector2i&);
    virtual ~Object();

    virtual void draw(WINDOW*, const chtype='o') const;
    virtual void move(const Direction&);
    int y() const;
    int x() const;
    Vector2i position() const;
    Direction direction() const;
    bool operator== (const Object&) const;

protected:
    Vector2i m_position;
    Direction m_direction;

private:
    bool canChangeDirection(const Direction&) const;
};
