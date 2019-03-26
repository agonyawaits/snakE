#pragma once
#include "Figure.hpp"

class Apple : public Figure {
private:
	const int mDeskHeight, mDeskWidth;
public:
	Apple(int, int);

public:
	void Draw() const;
	void Update();
};