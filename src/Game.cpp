//  Game.cpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include "Game.h"
#include "Desk.h"
#include "Apple.h"
#include "Snake.h"
#include "ScoreManager.hpp"
#include <ncurses.h>

Game::Game() 
    : m_score( 0 ), m_highScore( ScoreManager::getScore() ) 
{
    initscr();
    noecho();
    curs_set( 0 );
    halfdelay( 1 );

    m_window = newwin( Desk::height, Desk::width, 1, 0 );
    keypad( m_window, TRUE );
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

void Game::updateScore( const int& charSize ) {
    m_score = 10 * charSize;
    mvprintw( 0, 0, "Score: %d", m_score );
    refresh();
}

Game::~Game() {
    mvwprintw( m_window, Desk::height/2-1, Desk::width/2 - 5, "Game Over!" );
    mvwprintw( m_window, Desk::height/2, Desk::width/2 - 10, "Press enter to exit..." );
    nocbreak();
    wgetch( m_window );
    delwin( m_window );
    endwin();
    
    if ( m_score > m_highScore ) {
        ScoreManager::logScore( m_score );
    }
}
