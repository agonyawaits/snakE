//  Game.cpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include "../include/Game.h"
#include "../include/Desk.h"
#include "../include/Apple.h"
#include "../include/Snake.h"
#include "../include/ScoreManager.hpp"
#include <ncurses.h>
#include <thread>
#include <ctime>

Game::Game() :
    m_score( 0 ),
    m_highScore( 0 ) {
    initscr();
    clear();
    noecho();
    cbreak();
    curs_set( 0 );
    ScoreManager::initScore( m_highScore );
}

void Game::launch(
    const int t_deskHeight, 
    const int t_deskWidth
    ) {
    using namespace std::chrono_literals;

    Desk gameDesk( t_deskHeight, t_deskWidth );
    Snake snake( t_deskHeight, t_deskWidth );
    Apple apple( t_deskHeight, t_deskWidth );

    while ( !snake.getIsDead() ) {
        gameDesk.draw( &apple, &snake, m_score, m_highScore );
        gameDesk.update( &apple, &snake, m_score );
    }   
    
    std::this_thread::sleep_for( 1s );
    clear();
    mvprintw( t_deskHeight/2, t_deskWidth/2, "GAME OVER!" );
    refresh();
    std::this_thread::sleep_for( 2s );
    endwin();
}

Game::~Game() {
    if ( m_score > m_highScore ) {
        ScoreManager::logScore( m_score );
    }
}
