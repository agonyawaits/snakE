#pragma once

#include "Vector2.hpp"
#include "Direction.hpp"
#include <ncurses.h>

class Object final { // TODO: Think if should be not final with virtual methods.
public:
    Object();
    Object(const Vector2i&);

    void        draw(WINDOW*, const chtype='o') const;
    void        move(const Direction&);
    void        moveTo(const Vector2i&);
    int         y() const;
    int         x() const;
    Vector2i    position() const;
    Direction   direction() const;
    bool        operator== (const Object&) const;

protected:
    Vector2i    m_position;
    Direction   m_direction;

private:
    bool canChangeDirection(const Direction&) const;
};
