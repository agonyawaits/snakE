//  ScoreManager.hpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once
#include <fstream>
#include <ncurses.h>

class ScoreManager {
public:
    ScoreManager()
        : m_score( 0 ) {}

    void updateScore( const int& multiplier ) {
        m_score = ScoreManager::step * multiplier;
    }

    void printScore() const {
        mvprintw( 0, 0, "Score: %d", m_score );
        refresh();
    }

    inline int getScore() const { return m_score; };

public:
    static const int step = 10;

    static int getLastHighScore() {
        std::fstream fin( "data/highscore.txt", std::ios::in );
        int score = 0;

        if ( fin ) {
            fin >> score;
            fin.close();
        }

        return score;
    }

    static void logNewHighScore( const int& score ) {
        std::fstream fout( "data/highscore.txt", std::ios::out );

        if ( fout ) {
            fout << score;
            fout.close();
        }
    }

private:
    int m_score;
};
