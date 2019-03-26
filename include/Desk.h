#pragma once
#include "Figure.hpp"

class Desk {
private:
	void OnInput(Figure*);

public:
	const int mHeight, mWidth;

public:
	Desk(int,int);
	
public:
	void Draw(Figure*, Figure*) const;
	void Update(Figure*, Figure*);
};