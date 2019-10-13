#pragma once
#include <fstream>

class ScoreManager
{
public:
    static void initScore( int& );
    static void logScore( int );
};

void ScoreManager::initScore( int& t_score) {
    std::fstream fin( "highscore.txt", std::ios::in );
    if ( fin.is_open() ) {
        fin >> t_score;
        fin.close();
    }
}

void ScoreManager::logScore( int t_score ) {
    std::fstream fout( "highscore.txt", std::ios::out );
    if ( fout.is_open() ) {
        fout << t_score;
        fout.close();
    }
}