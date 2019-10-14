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
        int m_x, m_y;
        SnakeSegment( int t_x, int t_y ) : m_x( t_x ), m_y( t_y ) {}
    };

    using SnakeContainer = std::vector<SnakeSegment>;
    
    enum Direction { NONE, LEFT, RIGHT, UP, DOWN };

    SnakeContainer m_snakeBody;
    Direction m_direction;

    void extend() override;
    void onInput() override;
};
