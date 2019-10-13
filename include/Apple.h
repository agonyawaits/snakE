//  Apple.h
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once
#include "Figure.hpp"

class Apple : public Figure {

public:
    Apple( int, int );

    void draw() const override;
    void update() override;
    
};
