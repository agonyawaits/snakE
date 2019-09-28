//  Figure.hpp
//  SnakeGame_OOP
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once

class Figure {

protected:
	int m_x, m_y;
	bool m_isDead;
	int m_deskHeight, m_deskWidth;

public:
	virtual ~Figure() {};

	virtual void Draw() const = 0;
	virtual void Update() = 0;

	virtual void OnInput() {};
	virtual void Extend() {};

	int GetX() const { return m_x; }
	int GetY() const { return m_y; }
	bool GetIsDead() const { return m_isDead; }
	
};