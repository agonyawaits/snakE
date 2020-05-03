#pragma once

#include "Vector2.hpp"
#include "Window.hpp"
#include "Object.hpp"
#include "Snake.hpp"
#include "Direction.hpp"
#include <ncurses.h>

class Board : public Window {
public:
    Board(const int&, const int&, const Vector2i&);

    void update();
    bool live() const;

private:
    Snake   m_snake;
    Object  m_apple;
    bool    m_live;

    void        draw() const;
    Vector2i    randomPosition() const;
    Direction   parseInput(const int&) const;
    bool        noCollision() const;
};
