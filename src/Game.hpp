#pragma once

#include "Vector2.hpp"
#include "Window.hpp"
#include "Object.hpp"
#include "Snake.hpp"
#include "Direction.hpp"
#include <ncurses.h>

class Game final {
public:
    Game(const Window&);

    void update();
    bool isOver() const;

private:
    bool            m_isOver;
    const Window&   m_window;
    Snake           m_snake;
    Object          m_apple;

    Direction       parseInput(const int&) const;
    bool            noCollision() const;
};
