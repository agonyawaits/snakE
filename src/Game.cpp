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
    halfdelay( 1 );

    m_window = newwin( Config::deskHeight, Config::deskWidth, 1, 0 );
    keypad( m_window, TRUE );
    // TODO: Add difficulty levels
}

int Game::start() {
    Snake snake;
    Apple apple;
    Desk desk( snake, apple );

    while ( !snake.isDead() ) {
        wclear( m_window );

        desk.draw( m_window );
        desk.update( wgetch( m_window ) );
        updateScore( snake.size() );
    }   
    
    return 0;
}

int Game::run() {
    Game game;
    return game.start();
}

void Game::updateScore( const int& t_charSize ) {
    m_score = 10 * t_charSize;
    mvprintw( 0, 0, "Score: %d", m_score );
    refresh();
}

Game::~Game() {
    std::this_thread::sleep_for( std::chrono::milliseconds(500) );
    mvwprintw( m_window, Config::deskHeight/2-1, Config::deskWidth/2 - 5, "Game Over!" );
    wrefresh( m_window );
    std::this_thread::sleep_for( std::chrono::seconds(1) );
    delwin( m_window );
    endwin();
    
    if ( m_score > m_highScore ) {
        ScoreManager::logScore( m_score );
    }
}
