//  Game.h
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once

class Game {
public:
    Game();
    ~Game();

    void launch( const int, const int );
    
private:
    int m_score, m_highScore;
};
