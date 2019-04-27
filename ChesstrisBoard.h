#pragma once

#include "Chesstris.h"
#include "IBoard.h"

/// The chesstris game board
class ChesstrisBoard : public IBoard
{

private:

	typedef char TILE; /// representing what is on this tile
	typedef int POSITION;
	typedef char PIECE;

	/// The board is made of 8x8 tiles
	/// At this point the tile is 
	TILE tiles_[8][8];

	/// \todo This is a temporary patch because the Board is keeping the move marks acting actually as a Display.
	/// The moves stored here are displayed so the user can see his optional moves.
	MOVE moves_[8][8]; 

public:

	ChesstrisBoard();

	virtual ~ChesstrisBoard();

	/// Draw the board.
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

