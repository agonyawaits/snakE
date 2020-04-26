//  ScoreManager.cpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include "ScoreManager.h"
#include <fstream>
#include <ncurses.h>

ScoreManager::ScoreManager()
    : m_score( 0 ), m_step( 10 ) {}

void ScoreManager::updateScore( const int& multiplier ) {
    m_score = m_step * multiplier;
}

void ScoreManager::printScore() const {
    mvprintw( 0, 0, "Score: %d", m_score );
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
