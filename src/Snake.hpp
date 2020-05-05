#pragma once

#include "Object.hpp"
#include "Board.hpp"
#include <vector>
#include <ncurses.h>

class Snake final {
public:
    Snake();
    Snake(const Vector2i&);

    void    draw(WINDOW*) const;
    void    move(const Direction&);
    void    extend();
    bool    alive() const;
    bool    collides(const Object&) const;
    bool    collides(const Board&) const;
    Object  head() const;

private:
    std::vector<Object> m_body;
    bool                m_alive;

    bool    died() const;
};
