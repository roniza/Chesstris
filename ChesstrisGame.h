#pragma once

#include "ChesstrisBoard.h"
#include "IGame.h"

using namespace std;

class ChesstrisGame : public IGame {
	bool ended_;
	ChesstrisBoard board_;

	int posX;
	int posY;

	//MOVE moves[8];

	void North();
	void South();

	// True if pos is valid and clear
	bool isValidMovePos(int x, int y);

public:
	ChesstrisGame();

	virtual IBoard& getBoard();

	virtual void start();

	virtual bool ended();

	virtual bool isValidMove(const MOVE move);

	virtual void move(const MOVE move);

	virtual void EndShow();

	virtual void draw();
};