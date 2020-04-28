//  ScoreManager.cpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include "ScoreManager.h"
#include "Vector2.hpp"
#include <fstream>
#include <ncurses.h>

ScoreManager::ScoreManager()
    : m_score( 0 ), m_highScore( getLastHighScore() ), m_step( 10 ) {}

void ScoreManager::updateScore( const int& multiplier ) {
    m_score = m_step * multiplier;
}

void ScoreManager::printScores( 
    const Vector2i& scorePosition,
    const Vector2i& highScorePosition ) const 
{
    mvprintw( scorePosition.getY(), scorePosition.getX(), "Score: %d", m_score );
    mvprintw( highScorePosition.getY(), highScorePosition.getX(), "High Score: %d", m_highScore );
    refresh();
}

int ScoreManager::getLastHighScore() const {
    std::fstream fin( "data/highscore.txt", std::ios::in );
    int score = 0;

    if ( fin ) {
        fin >> score;
        fin.close();
    }

    return score;
}

void ScoreManager::logNewHighScore( const int& score ) const {
    std::fstream fout( "data/highscore.txt", std::ios::out );

    if ( fout ) {
        fout << score;
        fout.close();
    }
}
