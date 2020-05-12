#pragma once

#include "Window.hpp"
#include "Object.hpp"
#include "Snake.hpp"
#include "Direction.hpp"
#include "Board.hpp"
#include "Score.hpp"

class Game final {
public:
    Game(const Window&);

    void execute();

private:
    bool            m_wasted;
    const Window&   m_window;
    Board           m_board;
    Snake           m_snake;
    Object          m_apple;
    Score           m_score;

    void render() const;
    void update();
};
