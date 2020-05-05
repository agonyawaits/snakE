#pragma once

#include "Window.hpp"
#include "Object.hpp"
#include "Snake.hpp"
#include "Direction.hpp"
#include "Edge.hpp"

class Game final {
public:
    Game(const Window&);

    void execute();

private:
    bool            m_wasted;
    const Window&   m_window;
    Edge            m_edge;
    Snake           m_snake;
    Object          m_apple;

    void render() const;
    void update();
};
