#pragma once

#include "Chesstris.h"

class IBoard;

class IGame
{
protected:
	IGame() {}
public:
	virtual ~IGame() {}

	virtual void EndShow() = 0;
	virtual bool ended() = 0;
	virtual IBoard& getBoard() = 0;
	virtual void start() = 0;
	virtual void move(const MOVE) = 0;
	virtual bool isValidMove(const MOVE) = 0;
	virtual void draw() = 0;
};

