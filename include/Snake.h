//  Snake.h
//  SnakeGame_OOP
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once
#include "Figure.hpp"
#include <vector>

class Snake : public Figure {

private:
	struct SnakeSegment {
		int m_x, m_y;
		SnakeSegment( int x, int y ) : m_x( x ), m_y( y ) {}
	};

	using SnakeContainer = std::vector<SnakeSegment>;
	
	enum Direction { NONE, LEFT, RIGHT, UP, DOWN };

	SnakeContainer m_snakeBody;
	Direction m_direction;
	int m_score;
	int m_highScore;

	void Extend() override;

public:
	Snake( int,int );
	~Snake();

	int GetScore() const;
	int GetHighScore() const;
	void Draw() const override;
	void Update() override;
	void OnInput() override;

};