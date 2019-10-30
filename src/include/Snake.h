//  Snake.h
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once
#include "Object.hpp"
#include <vector>
#include "Vector2.hpp"

class Snake final : public Object {
public:
    Snake();

    bool isDead() const;
    void draw() const override;
    void update() override;
    void extend() override;
    int size() const override;

private:
    struct SnakeSegment {
        Vector2i position;
        
        SnakeSegment( const int& t_x, const int& t_y ) 
            : position( Vector2i( t_x, t_y ) ) {}
    };
    
    enum Direction {  
        LEFT, 
        RIGHT, 
        UP, 
        DOWN 
    };

    Direction                   m_direction;
    bool                        m_isDead;
    std::vector<SnakeSegment>   m_snakeBody;

    void onInput() override;
    void changeDirection( const int& );
    void move();
    void checkCollision();
    void cut( const std::vector<SnakeSegment>::iterator& );
};
