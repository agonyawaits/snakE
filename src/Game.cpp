//  Game.cpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include "Game.h"
#include "Desk.h"
#include "Apple.h"
#include "Snake.h"
#include "ScoreManager.hpp"
#include "Config.hpp"
#include <ncurses.h>
#include <thread>
#include <ctime>

Game::Game() 
    : m_score( 0 ), m_highScore( ScoreManager::getScore() ) 
{
    initscr();
    clear();
    noecho();
    cbreak();
    curs_set( 0 );
    keypad( stdscr, TRUE );
    halfdelay( 1 );
}

int Game::start() {
    Snake snake;
    Apple apple;
    Desk desk( snake, apple, m_score );

    while ( !snake.isDead() ) {
        desk.draw();
        desk.update( getch() );
    }   
    
    return 0;
}

int Game::run() {
    Game game;
    return game.start();
}

Game::~Game() {
    std::this_thread::sleep_for( std::chrono::milliseconds(500) );
    clear();
    mvprintw( Config::deskHeight/2, Config::deskWidth/2, "GAME OVER!" );
    refresh();
    std::this_thread::sleep_for( std::chrono::seconds(1) );
    endwin();
    
    if ( m_score > m_highScore ) {
        ScoreManager::logScore( m_score );
    }
}
