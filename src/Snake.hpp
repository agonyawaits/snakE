#pragma once

#include "Object.hpp"
#include <vector>
#include <ncurses.h>

class Snake final {
public:
    Snake();
    Snake(const Vector2i&);

    void        draw(WINDOW*) const;
    void        move(const Direction&);
    void        extend();
    bool        alive() const;
    Vector2i    headPosition() const;

private:
    std::vector<Object> m_body;
    bool                m_alive;

    void    moveBody();
    void    postMoveUpdate();
    chtype  currentHeadSymbol() const;
};
