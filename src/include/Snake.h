//  Snake.h
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once
#include "Object.hpp"
#include <vector>
#include "Vector2.hpp"

class Snake : public Object {
public:
    Snake();

    void draw() const override;
    void update() override;
    bool isDead() const;
private:
    struct SnakeSegment {
        Vector2i m_position;
        SnakeSegment( int t_xPos, int t_yPos ) {
            m_position.m_x = t_xPos; 
            m_position.m_y = t_yPos;
        }
    };
    
    enum Direction {  
        LEFT, 
        RIGHT, 
        UP, 
        DOWN 
    };

    std::vector<SnakeSegment> m_snakeBody;
    Direction m_direction;
    bool m_isDead;

    void extend() override;
    void onInput() override;
    void changeDirection( int );
    bool checkCollision() const;
    void move();
};
