//  Game.cpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include "include/Game.h"
#include "include/Desk.h"
#include "include/Apple.h"
#include "include/Snake.h"
#include "include/ScoreManager.hpp"
#include "include/Config.hpp"
#include <ncurses.h>
#include <thread>
#include <ctime>

using namespace std::chrono_literals;

Game::Game() 
    : m_score( 0 ), m_highScore( 0 ) 
{
    initscr();
    clear();
    noecho();
    cbreak();
    curs_set( 0 );
    m_highScore = ScoreManager::getScore();
}

int Game::start() {
    Desk desk;
    Snake snake;
    Apple apple;

    while ( !snake.isDead() ) {
        desk.draw( apple, snake, m_score, m_highScore );
        desk.update( apple, snake, m_score );
    }   
    
    std::this_thread::sleep_for( 1s );
    clear();
    mvprintw( Config::deskHeight/2, Config::deskWidth/2, "GAME OVER!" );
    refresh();
    std::this_thread::sleep_for( 2s );
    endwin();

    return 0;
}

int Game::run() {
    Game game;
    return game.start();
}

Game::~Game() {
    if ( m_score > m_highScore ) {
        ScoreManager::logScore( m_score );
    }
}
