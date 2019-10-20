//  Snake.h
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once
#include "Figure.hpp"
#include <vector>

class Snake : public Figure {
public:
    Snake( int, int );

    void draw() const override;
    void update() override;
    
private:
    struct SnakeSegment {
        int m_xPos, m_yPos;
        SnakeSegment( int t_xPos, int t_yPos ) : m_xPos( t_xPos ), m_yPos( t_yPos ) {}
    };
    
    enum Direction { 
        NONE, 
        LEFT, 
        RIGHT, 
        UP, 
        DOWN 
    };

    std::vector<SnakeSegment> m_snakeBody;
    Direction m_direction;

    void extend() override;
    void onInput() override;
    void changeDirection( int );
    bool hasDied() const;
    void moveOneStepForward();
};
