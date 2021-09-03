#pragma once

#include <ncurses.h>
#include "window.h"
#include "entity.h"
#include "snake.h"
#include "board.h"
#include "menu.h"

struct Score : public IDrawable {
    Score(const V2 &position, int step);

    void increase();
    void draw(WINDOW *) const override;
    void reset();

private:
    V2  m_position;
    int m_score;
    int m_high_score;
    int m_step;
};

struct Game {
    Game(const Window &);

private:
    void launch_menu();
    void launch_game();
    void render() const;
    void update();
    void reset();

private:
    const Window&   m_window;
    Menu            m_menu;
    bool            m_wasted;
    Board           m_board;
    Snake           m_snake;
    Entity          m_apple;
    Score           m_score;
};
