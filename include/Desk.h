//  Desk.h
//  SnakeGame_OOP
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once
#include "Figure.hpp"

class Desk {

private:
	void OnInput( Figure* );

public:
	const int m_height, m_width;

public:
	Desk( int, int );

public:
	void Draw( Figure*, Figure* ) const;
	void Update( Figure*, Figure* );
	
};