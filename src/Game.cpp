//  Game.cpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include "Game.h"
#include "Desk.h"
#include "Apple.h"
#include "Snake.h"
#include "ScoreManager.h"
#include "Vector2.hpp"
#include <ncurses.h>
#include <memory>

Game::Game( const int& windowHeight, const int& windowWidth )
    : m_scoreManager( std::make_unique<ScoreManager>() ),
    m_windowHeight( windowHeight ), m_windowWidth( windowWidth )
{
    setupScreen();
}

int Game::start() {
    Desk desk( m_windowHeight, m_windowWidth );
    Snake snake( Vector2i( 1, 1 ) );
    Apple apple( desk.getRandomPosition() );

    desk.setHero( &snake );
    desk.setFood( &apple );

    while ( snake.alive() ) {
        wclear( m_window );

        desk.draw( m_window );
        desk.update( wgetch( m_window ) );

        m_scoreManager->updateScore( snake.size() );
        m_scoreManager->printScores( Vector2i( 0, 0 ), Vector2i( m_windowWidth - 15, 0 ) );
    }

    return 0;
}

Game::~Game() {
    finalizeScreen();

    int finalScore = m_scoreManager->getScore();
    if ( finalScore > m_scoreManager->getHighScore() ) {
        m_scoreManager->logNewHighScore( finalScore );
    }
}

void Game::setupScreen() {
    initscr();
    noecho();
    curs_set( 0 );
    halfdelay( 1 );

    m_window = newwin( m_windowHeight, m_windowWidth, 1, 0 );
    keypad( m_window, TRUE );
}

void Game::finalizeScreen() {
    mvwprintw( m_window, m_windowHeight/2-1, m_windowWidth/2 - 5, "Game Over!" );
    mvwprintw( m_window, m_windowHeight/2, m_windowWidth/2 - 10, "Press enter to exit..." );
    nocbreak();
    wgetch( m_window );
    delwin( m_window );
    endwin();
}
