#pragma once

#include <ncurses.h>
#include "window.h"
#include "entity.h"
#include "snake.h"
#include "board.h"

struct Score : public IDrawable {
    Score(const V2 &, int);

    void increase();
    void draw(WINDOW *) const override;

private:
    V2  m_position;
    int m_score;
    int m_step;
};

struct Game {
    Game(const Window &);

private:
    void render() const;
    void update();

private:
    const Window&   m_window;
    bool            m_wasted;
    Board           m_board;
    Snake           m_snake;
    Entity          m_apple;
    Score           m_score;
};
