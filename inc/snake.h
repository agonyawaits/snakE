#pragma once

#include <vector>
#include <ncurses.h>
#include "entity.h"
#include "board.h"
#include "idrawable.h"

struct Snake : public IDrawable {
    Snake();
    Snake(const V2 &position);

    void    draw(WINDOW *) const override;
    void    move(Direction);
    void    extend();
    bool    collides(const Entity &) const;
    bool    collides(const Board &) const;
    bool    died() const;
    Entity  head() const;
    void    relocate(const V2 &);

private:
    std::vector<Entity> m_body;
};
