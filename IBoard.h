#pragma once

class IBoard
{
protected:
	IBoard() {}
public:
	virtual ~IBoard() {}
	virtual void draw() = 0;
};

