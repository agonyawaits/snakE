//  Apple.h
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once
#include "Object.hpp"

class Apple final : public Object {
public:
    Apple();

    void draw() const override;
    void update() override;
};
