//  Snake.h
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once
#include "Figure.hpp"
#include <vector>

class Snake : public Figure {

private:
	struct SnakeSegment {
		int m_x, m_y;
		SnakeSegment( int t_x, int t_y ) : m_x( t_x ), m_y( t_y ) {}
	};

	using SnakeContainer = std::vector<SnakeSegment>;
	
	enum Direction { NONE, LEFT, RIGHT, UP, DOWN };

	SnakeContainer m_snakeBody;
	Direction m_direction;
	int m_score;
	int m_highScore;

	void extend() override;
	void onInput() override;

public:
	Snake( int,int );
	~Snake();

	int getScore() const;
	int getHighScore() const;
	void draw() const override;
	void update() override;
	
};
