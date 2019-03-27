//  Figure.hpp
//  SnakeGame_OOP
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once

class Figure {
protected:
	int mX, mY;
	bool mIsDead;
	int mDeskHeight, mDeskWidth;

public:
	virtual ~Figure() {};

public:
	virtual void Draw() const = 0;
	virtual void Update() = 0;

public:
	virtual void OnInput() {};
	virtual void Extend() {};

public:
	int GetX() const { return mX; }
	int GetY() const { return mY; }
	bool GetIsDead() const { return mIsDead; }
};