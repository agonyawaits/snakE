//  ScoreManager.h
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once
#include "Vector2.hpp"

class ScoreManager {
public:
    ScoreManager();

    inline int getScore() const { return m_score; };
    inline int getHighScore() const { return m_highScore; };

    void updateScore( const int& );
    void printScores( const Vector2i&, const Vector2i& ) const;
    void logNewHighScore( const int& ) const;

private:
    int m_score;
    int m_highScore;
    int m_step;

    int getLastHighScore() const;
};
