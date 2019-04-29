#pragma once

#include "ChesstrisBoard.h"
#include "IGame.h"

using namespace std;

class ChesstrisGame : public IGame {
	bool ended_;
	int _numMoves;
	ChesstrisBoard board_;

	int posX;
	int posY;

	// True if pos is valid and clear
	bool isValidMovePos(int x, int y);

	// Evaluate state after move
	void EvaluateState();
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