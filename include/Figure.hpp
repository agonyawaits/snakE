#pragma once

class Figure {
protected:
	int mX, mY;
	bool mIsDead;
public:
	virtual ~Figure() {};
public:
	virtual void Draw() const = 0;
	virtual void OnInput() {};
	virtual void Update() = 0;
	virtual void LevelUp() {};
public:
	int GetX() { return mX; }
	int GetY() { return mY; }
};