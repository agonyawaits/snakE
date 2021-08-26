#pragma once

#include <ncurses.h>
#include "v2.h"
#include "idrawable.h"

enum Direction {
    NONE, LEFT, UP, RIGHT, DOWN
};

struct Entity : public IDrawable {
    Entity();
    Entity(const V2 &);

    void        draw(WINDOW *) const;
    void        draw(WINDOW *, chtype) const;
    void        move(Direction);
    void        moveTo(const V2 &);
    V2    position() const;
    Direction   direction() const;
    bool        operator==(const Entity &) const;

private:
    V2 newPos() const;

private:
    V2    m_position;
    Direction   m_direction;
};
