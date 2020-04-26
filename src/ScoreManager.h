//  ScoreManager.h
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once

class ScoreManager {
public:
    ScoreManager();

    inline int getScore() const { return m_score; };

    void updateScore( const int& );
    void printScore() const;
    int getLastHighScore() const;
    void logNewHighScore( const int& ) const;

private:
    int m_score;
    int m_step;
};
