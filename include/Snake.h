//  Snake.h
//  SnakeGame_OOP
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once
#include "Figure.hpp"
#include <vector>

class Snake : public Figure {
private:
	struct SnakeSegment {
		int mX, mY;
		SnakeSegment(int x, int y) : mX(x), mY(y) {}
	};
	using SnakeContainer = std::vector<SnakeSegment>;
	enum Direction { NONE, LEFT, RIGHT, UP, DOWN };

private:
	SnakeContainer mSnakeBody;
	Direction mDirection;
	int mScore;
	int mHighScore;

private:
	void Extend() override;

public:
	Snake(int,int);
	~Snake();
public:
	int GetScore() const;
	int GetHighScore() const;
	void Draw() const override;
	void Update() override;
	void OnInput() override;
};