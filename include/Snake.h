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
	void LevelUp();

public:
	Snake(int,int);
	bool GetIsDead() const;
	int GetScore() const;
	int GetHighScore() const;
	~Snake();
public:
	void Draw() const;
	void Update();
	void OnInput();
};