#include "ChesstrisGame.h"
#include <iostream>
#include <assert.h>

#define DIM_OF(_A_) sizeof(_A_)/sizeof(_A_[0])

//template <int _X_=0, int _Y_=0>
class MoveType {
	int X, Y;
public:
	MoveType(int xy[])
		: X(xy[0])
		, Y(xy[1])
	{
	}

	MoveType(int x, int y)
		: X(x)
		, Y(y) {}

	int x() {
		return X;
	}
	int y() {
		return Y;
	}
};

MoveType moves[8]
{
	{ 1,-2}, 
	{ 1, 2},

	{-1, 2}, 
	{-1,-2},
	{ 2, 1},
	{ 2,-1},
	{-2, 1},
	{-2,-1}
};

void ChesstrisGame::North() {
	if (posY > 0)
	{
		board_.ClearPos(posX, posY);
		board_.MarkStepedPos(posX, posY);
		posY--;
		board_.SetKnightAtPos(posX, posY);
	}

}

void ChesstrisGame::South() {
	board_.ClearPos(posX, posY);
	board_.MarkStepedPos(posX, posY);
	posY += 2; posX++;
	board_.SetKnightAtPos(posX, posY);
}

ChesstrisGame::ChesstrisGame()
	: ended_(false)
	, board_()
	, posX(4)
	, posY(4)
{
}

IBoard& ChesstrisGame::getBoard()
{
	return (IBoard&)board_;
}

void ChesstrisGame::start()
{
	board_.Clear();
	posX = 4;
	posY = 4;
	board_.SetKnightAtPos(posX, posY);
}

bool ChesstrisGame::ended() {
	return ended_;
}

bool ChesstrisGame::isValidMove(const MOVE move)
{
	assert(move > '0');
	int mi = move - '1';
	int mpx = posX + moves[mi].x();
	int mpy = posY + moves[mi].y();
	return isValidMovePos(mpx, mpy);
}

void ChesstrisGame::move(const MOVE move)
{
	assert(isValidMove(move));

	board_.MarkStepedPos(posX, posY);
	int mi = move - '1';
	posX += moves[move - '1'].x();
	posY += moves[move - '1'].y();
	board_.SetKnightAtPos(posX, posY);
}

void ChesstrisGame::EndShow() {
	cout << "The End!" << endl;
}

bool ChesstrisGame::isValidMovePos(int x, int y)
{
	return (board_.IsValidPos(x, y) && board_.IsClearPos(x, y));
}

void ChesstrisGame::draw() 
{
	board_.ClearMoves();
	
	for (int i = 0; i < DIM_OF(moves); i++)
	{
		int mpx = posX + moves[i].x();
		int mpy = posY + moves[i].y();
		if (isValidMovePos(mpx, mpy))
		{
			board_.MarkMoveAtPos(mpx, mpy, '1' + i);
		}
	}

	board_.draw();
}