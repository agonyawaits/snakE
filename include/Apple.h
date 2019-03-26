//  Apple.h
//  SnakeGame_OOP
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once
#include "Figure.hpp"

class Apple : public Figure {
public:
	Apple(int, int);

public:
	void Draw() const override;
	void Update() override;
};