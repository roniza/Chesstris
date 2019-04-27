#pragma once

#include "Chesstris.h"
#include "IBoard.h"

class ChesstrisBoard : public IBoard
{

private:

	typedef char TILE;
	typedef int POSITION;
	typedef char PIECE;

	TILE tiles_[64];
	MOVE moves_[64];

public:

	ChesstrisBoard();

	virtual ~ChesstrisBoard();

	virtual void draw();

	virtual void EndShow();

	int MaxY();

	int MaxX();

	void Clear();
	void ClearPos(int x, int y);
	void MarkStepedPos(int x, int y);
	void SetKnightAtPos(int x, int y);
	bool IsClearPos(int x, int y);
	bool IsValidPos(int x, int y);

	void MarkMoveAtPos(int x, int y, MOVE m);
	void ClearMoves();

};

