#pragma once
#include "Figure.hpp"

class Desk {
public:
	const int mHeight, mWidth;

public:
	Desk(int,int);
	void Draw(Figure*, Figure*) const;
	void Update(Figure*, Figure*);

private:
	void OnInput(Figure*);
};