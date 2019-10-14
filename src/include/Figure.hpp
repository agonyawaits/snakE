//  Figure.hpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once

class Figure {
public:
    virtual ~Figure() {};

    virtual void draw() const = 0;
    virtual void update() = 0;

    virtual void onInput() {};
    virtual void extend() {};

    int getX() const { return m_x; }
    int getY() const { return m_y; }
    bool isDead() const { return m_isDead; }
    
protected:
    int m_x, m_y;
    bool m_isDead;
    int m_deskHeight, m_deskWidth;
};
