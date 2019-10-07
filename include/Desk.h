//  Desk.h
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#pragma once
#include "Figure.hpp"

class Desk {

private:
	void onInput( Figure* );

	const int m_height, m_width;

public:
	Desk( int, int );

	int getHeight() const;
	int getWidth() const;

	void draw( Figure*, Figure* ) const;
	void update( Figure*, Figure* );
	
};
