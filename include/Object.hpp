#pragma once

#include "Vector2.hpp"
#include "Direction.hpp"
#include "IDrawable.hpp"
#include <ncurses.h>

class Object final : public IDrawable {
public:
    Object();
    Object(const Vector2i&);

    void        draw(WINDOW*) const;
    void        draw(WINDOW*, const chtype&) const;
    void        move(const Direction&);
    void        moveTo(const Vector2i&);
    Vector2i    position() const;
    Direction   direction() const;
    bool        operator== (const Object&) const;

private:
    Vector2i    m_position;
    Direction   m_direction;

    bool        canChangeDirection(const Direction&) const;
};
