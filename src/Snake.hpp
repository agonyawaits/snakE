#pragma once

#include "Object.hpp"
#include "Edge.hpp"
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
    bool    alive() const;
    bool    collides(const Object&) const;
    bool    collides(const Edge&) const;
    Object  head() const;

private:
    std::vector<Object> m_body;
    bool                m_alive;

    bool    died() const;
};
