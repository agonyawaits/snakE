//  Game.h
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once

class Game {
public:
    Game();
    ~Game();

    void launch();
    
private:
    int m_score, m_highScore;
};
