#pragma once

#include "Object.hpp"
#include "Board.hpp"
#include "IDrawable.hpp"
#include <vector>
#include <ncurses.h>

class Snake final : public IDrawable {
public:
    Snake();
    Snake(const Vector2i&);

    void    draw(WINDOW*) const;
    void    move(const Direction&);
    void    extend();
    bool    collides(const Object&) const;
    bool    collides(const Board&) const;
    bool    died() const;
    Object  head() const;

private:
    static const int    s_minSizeCanDie;
    std::vector<Object> m_body;
};
