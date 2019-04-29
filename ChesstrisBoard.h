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
	TILE tiles_[8][8];

	/// Used for display of the moves.
	/// \todo This is a temporary patch because the Board is keeping the move marks acting actually as a Display.
	/// consider adding a Display class
	MOVE moves_[8][8]; 

public:

	ChesstrisBoard();

	virtual ~ChesstrisBoard();

	/// Draw the board.
	virtual void draw();

	/// Display something at the end of the game
	virtual void EndShow();

	/// Get the maximum X
	int MaxX();
	/// Get the maximum Y
	int MaxY();

	/// Clear the board
	void Clear();


	void ClearPos(int x, int y);
	void MarkStepedPos(int x, int y);
	void SetKnightAtPos(int x, int y);
	bool IsClearPos(int x, int y);
	bool IsValidPos(int x, int y);

	void MarkMoveAtPos(int x, int y, MOVE m);
	void ClearMoves();

};

