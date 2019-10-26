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
        SnakeSegment( int t_x, int t_y ) : position( Vector2i( t_x, t_y ) ) {}
        Vector2i position;
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
