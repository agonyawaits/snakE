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

    inline int getX() const { return m_xPos; }
    inline int getY() const { return m_yPos; }
    inline bool isDead() const { return m_isDead; }
    
protected:
    int m_xPos, m_yPos;
    bool m_isDead;
    int m_deskHeight, m_deskWidth;
};
