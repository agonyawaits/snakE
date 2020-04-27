//  Game.h
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once

#include "ScoreManager.h"
#include <ncurses.h>
#include <memory>

class Game final {
public:
    Game( const int&, const int& );
    ~Game();

    int start();

    static int run( const int windowHeight=25, const int windowWidth=37 ) {
        return Game( windowHeight, windowWidth ).start();
    }

private:
    WINDOW*                         m_window;
    int                             m_windowHeight;
    int                             m_windowWidth;
    std::unique_ptr<ScoreManager>   m_scoreManager;

private:
    void setupScreen();
    void finalizeScreen();
};
