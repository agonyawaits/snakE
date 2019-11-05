//  ScoreManager.hpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once
#include <fstream>

class ScoreManager {
public:
    static int getScore();
    static void logScore( const int& );
};

int ScoreManager::getScore() {
    int score = 0;
    std::fstream fin( "../data/highscore.txt", std::ios::in );
    if ( fin ) {
        fin >> score;
        fin.close();
    }

    return score;
}

void ScoreManager::logScore( const int& t_score ) {
    std::fstream fout( "../data/highscore.txt", std::ios::out );
    if ( fout.is_open() ) {
        fout << t_score;
        fout.close();
    }
}