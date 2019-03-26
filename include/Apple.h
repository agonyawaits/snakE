#pragma once
#include "Figure.hpp"

class Apple : public Figure {
public:
	Apple(int, int);

public:
	void Draw() const override;
	void Update() override;
};