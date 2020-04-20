//  Game.cpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include "Game.h"
#include "Desk.h"
#include "Apple.h"
#include "Snake.h"
#include "ScoreManager.hpp"
#include <ncurses.h>
#include <memory>

Game::Game()
    : m_scoreManager( std::make_unique<ScoreManager>() )
{
    setupScreen();
}

int Game::start() {
    Snake snake( Desk::getRandomPosition() );
    Apple apple( Desk::getRandomPosition() );
    Desk desk( snake, apple );

    while ( snake.alive() ) {
        wclear( m_window );

        desk.draw( m_window );
        desk.update( wgetch( m_window ) );
        
        m_scoreManager->updateScore( snake.size() );
        m_scoreManager->printScore();
    }

    return 0;
}

int Game::run() {
    return Game().start();
}

Game::~Game() {
    finalizeScreen();

    int finalScore = m_scoreManager->getScore();
    if ( finalScore > ScoreManager::getLastHighScore() ) {
        ScoreManager::logNewHighScore( finalScore );
    }
}

void Game::setupScreen() {
    initscr();
    noecho();
    curs_set( 0 );
    halfdelay( 1 );

    m_window = newwin( Desk::height, Desk::width, 1, 0 );
    keypad( m_window, TRUE );
}

void Game::finalizeScreen() {
    mvwprintw( m_window, Desk::height/2-1, Desk::width/2 - 5, "Game Over!" );
    mvwprintw( m_window, Desk::height/2, Desk::width/2 - 10, "Press enter to exit..." );
    nocbreak();
    wgetch( m_window );
    delwin( m_window );
    endwin();
}
