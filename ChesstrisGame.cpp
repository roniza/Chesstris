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

/// The possible moves
MoveType moves[8]
{        
	{ 1,-2},         
	{ 2,-1},       
	{ 2, 1}, 
	{ 1, 2},
	{-1, 2}, 
	{-2, 1},
	{-2,-1},
	{-1,-2}
};

ChesstrisGame::ChesstrisGame()
	: _ended(false)
	, _numMoves(0)
	, _score(0)
	, _lastMovePoints(0)
	, _board()
	, posX(4)
	, posY(4)
{
}

IBoard& ChesstrisGame::getBoard()
{
	return (IBoard&)_board;
}

void ChesstrisGame::start()
{
	_board.Clear();
	posX = 4;
	posY = 4;
	_board.SetKnightAtPos(posX, posY);
}

bool ChesstrisGame::ended() {
	return _ended;
}

/// Translates the move to position and see if the position is free
bool ChesstrisGame::isValidMove(const MOVE move)
{
	assert(move > '0');
	int mi = move - '1';
	int mpx = posX + moves[mi].x();
	int mpy = posY + moves[mi].y();
	return isValidMovePos(mpx, mpy);
}

/// Check the directions and see how many stepped tiles are there
void ChesstrisGame::EvaluateState()
{
	/// There are 8 directions from the current position
	/// The order is important because the last 4 entries are exactly 
	/// oposite of the first 4
	static MoveType directions[]
	{
		{-1,-1},
		{-1, 0},
		{-1, 1},
		{ 0,-1},
		{ 1, 1},
		{ 1, 0},
		{ 1,-1},
		{ 0, 1}
	};

	int count[8];
	memset(count, 0, sizeof(count));

	/// We count is positions in every direction
	for (int i = 0; i < 8; i++) {
		int x = posX + directions[i].x();
		int y = posY + directions[i].y();
		while (_board.IsValidPos(x, y) && !_board.IsClearPos(x, y)) {
			count[i]++;
			x += directions[i].x();
			y += directions[i].y();
		}
	}

	/// Evaluate points!
	_lastMovePoints = 0;

	/// Then we add the counts of oposite directions and if its above 3 (+1) where the Knight stands
	/// then its a score
	for (int i = 0; i < 4; i++) {
		int n = count[i] + count[i + 4];
		if (n > 2) /// meaning 3 neighboars in a row
		{
			_lastMovePoints += n;
			{
				int x = posX + directions[i].x();
				int y = posY + directions[i].y();

				while (0 < count[i]--) {
					_board.ClearPos(x, y);
					x += directions[i].x();
					y += directions[i].y();
				}
			}
			{
				int x = posX + directions[i+4].x();
				int y = posY + directions[i+4].y();

				while (0 < count[i+4]--) {
					_board.ClearPos(x, y);
					x += directions[i+4].x();
					y += directions[i+4].y();
				}
			}
		}
	}

	_score += _lastMovePoints;
}

void ChesstrisGame::move(const MOVE move)
{
	assert(isValidMove(move));

	_board.MarkStepedPos(posX, posY);
	int mi = move - '1';
	posX += moves[move - '1'].x();
	posY += moves[move - '1'].y();
	_board.SetKnightAtPos(posX, posY);
	// Now check the new position
	EvaluateState();
}

void ChesstrisGame::EndShow() {
	cout << "The End!" << endl;
}

bool ChesstrisGame::isValidMovePos(int x, int y)
{
	return (_board.IsValidPos(x, y) && _board.IsClearPos(x, y));
}

void ChesstrisGame::draw() 
{
	_board.ClearMoves();
	
	for (int i = 0; i < DIM_OF(moves); i++)
	{
		int mpx = posX + moves[i].x();
		int mpy = posY + moves[i].y();
		if (isValidMovePos(mpx, mpy))
		{
			_board.MarkMoveAtPos(mpx, mpy, '1' + i);
		}
	}

	cout << endl << "Score: " << _score << "\tLast move points: " << _lastMovePoints << endl;
	_board.draw();
}