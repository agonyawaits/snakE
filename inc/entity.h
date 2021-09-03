#pragma once

#include <ncurses.h>
#include "v2.h"
#include "idrawable.h"

enum Direction {
    NONE, LEFT, UP, RIGHT, DOWN
};

struct Entity : public IDrawable {
    Entity();
    Entity(const V2 &position);

    void        draw(WINDOW *) const override;
    void        draw(WINDOW *, chtype) const;
    void        move(Direction);
    void        move_to(const V2 &);
    V2          position() const;
    Direction   direction() const;
    bool        operator==(const Entity &) const;

private:
    V2          new_pos() const;

private:
    V2          m_position;
    Direction   m_direction;
};
