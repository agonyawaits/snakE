//  Snake.h
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once
#include "Object.hpp"
#include "Vector2.hpp"
#include <vector>
#include <ncurses.h>

#define SEGMENT 'o'

class Snake final : public Object {
public:
    Snake( const Vector2i& );

    void draw( WINDOW* ) const override;
    void update() override;

    void extend();
    void onInput( const int& );

    inline bool alive() const { return !m_isDead; }
    inline int size() const { return m_snakeBody.size(); }

private:
    class SnakeSegment : public Object {
    public:
        SnakeSegment( const Vector2i& position )
            : Object( position ) {}

        void draw( WINDOW* window ) const override {
            mvwaddch( window, this->getY(), this->getX(), SEGMENT );
        }

    private:
        void update() {};
    };

    enum class Direction {
        LEFT,
        RIGHT,
        UP,
        DOWN
    };

private:
    bool                        m_isDead;
    std::vector<SnakeSegment>   m_snakeBody;
    Direction                   m_direction;

    void    changeDirection( const int& );
    void    move();
    void    checkAndUpdateIfCollision();
    void    cut( const int& );
    chtype  currentHeadSymbol() const;
    void    moveHead();
    void    moveBody();
    bool    crashedOut() const;
    int     clashedSegmentIndex() const;

private:
    using Object::setX;
    using Object::setY;
};
