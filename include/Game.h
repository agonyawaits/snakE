//  Game.h
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once

class Game {
private:
    int m_score;
    int m_highScore;
public:
    Game();
    ~Game();

    void launch( const int, const int );
};
