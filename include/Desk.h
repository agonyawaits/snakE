#pragma once
#include "Figure.hpp"

class Desk {
public:
	const int mHeight, mWidth;
public:
	Desk(int,int);
public:
	void Draw(Figure*, Figure*) const;
	void OnInput(Figure*);
	void Update(Figure*, Figure*);
};