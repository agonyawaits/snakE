#pragma once

#include "Window.hpp"
#include "Object.hpp"
#include "Snake.hpp"
#include "Direction.hpp"

class Game final {
public:
    Game(const Window&);

    void render() const;
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
