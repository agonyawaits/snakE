//  Game.h
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once

#include "ScoreManager.hpp"
#include <ncurses.h>
#include <memory>

class Game final {
public:
    Game();
    ~Game();

    int start();
    void setupScreen();
    void finalizeScreen();

    static int run();
private:
    WINDOW* m_window;
    std::unique_ptr<ScoreManager> m_scoreManager;
};
