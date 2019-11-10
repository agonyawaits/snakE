//  Apple.h
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once
#include "Object.hpp"
#include <ncurses.h>

class Apple final : public Object {
public:
    Apple();

    void draw( WINDOW* ) const override;
    void update() override;
};
