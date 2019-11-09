//  Snake.h
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once
#include "Object.hpp"
#include "Vector2.hpp"
#include <vector>

class Snake final : public Object {
public:
    Snake();

    void draw() const override;
    void update() override;
    void extend() override;
    void onInput( const int& ) override;

    inline bool isDead() const { return m_isDead; }
    inline int size() const override { return m_snakeBody.size(); }

private:
    struct SnakeSegment {
        Vector2i position;
        
        SnakeSegment( const int& t_x, const int& t_y ) 
            : position( Vector2i( t_x, t_y ) ) {}
    };
    
    enum class Direction {  
        LEFT, 
        RIGHT, 
        UP, 
        DOWN 
    } m_direction;

    bool                        m_isDead;
    std::vector<SnakeSegment>   m_snakeBody;

    void changeDirection( const int& );
    void move();
    void checkCollision();
    void cut( const std::vector<SnakeSegment>::iterator& );
};
