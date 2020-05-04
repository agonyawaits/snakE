#pragma once

#include "Object.hpp"
#include "Window.hpp"
#include <vector>
#include <ncurses.h>

class Window; // NOTE: Forward declaration to avoid compile error.

class Snake final {
public:
    Snake();
    Snake(const Vector2i&);

    void    draw(WINDOW*) const;
    void    move(const Direction&);
    void    extend();
    bool    alive() const;
    bool    collides(const Object&) const;
    bool    collides(const Window&) const;
    Object  head() const;

private:
    std::vector<Object> m_body;
    bool                m_alive;

    bool    died() const;
    chtype  selfie() const;
};
