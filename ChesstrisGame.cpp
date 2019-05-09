#include "ChesstrisGame.h"
#include <iostream>
#include <assert.h>

#define DIM_OF(_A_) sizeof(_A_)/sizeof(_A_[0])

using namespace Chesstris;

/*
 * ChessTris is a board game played on 8x8 Chess board with a single Knight.
 * The game is somewhat similar to 4-in-a-row.
 * In every move the position of the knight is marked with a *
 * The puporse of the game is to mark rows, columns or diagonals of 4 or more adjecent tiles.
 */

void ChesstrisGame::Banner() {
	cout <<
		" _____ _              _____    _     " << endl <<
		"|     | |_ ___ ___ __|_   _|__|_|___ " << endl <<
		"|   --|   | -_|_ -|_ -|| ||  _| |_ -|" << endl <<
		"|_____|_|_|___|___|___||_||_| |_|___|" << endl << endl;
}

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
/// The order of the entires are important because they control the 
/// order of how they are displayed
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

// Ctor
// Initialize all member variables
ChesstrisGame::ChesstrisGame(int score_len)
	: _SCORING_LEN(score_len) 
	, _ended(false)
	, _numMoves(0)
	, _score(0)
	, _lastMovePoints(0)
	, _board()
	, posX(4)
	, posY(4)
{}

IBoard& ChesstrisGame::getBoard()
{
	return (IBoard&)_board;
}

void ChesstrisGame::start()
{
	Banner();
	cout << "Create rows of " << _SCORING_LEN << " *'s or more ..." << endl << endl;

	_board.Clear();
	posX = 4;
	posY = 4;
	_board.SetKnightAtPos(posX, posY);
	MarkValidMoves();
}

bool ChesstrisGame::ended() {
	return _ended;
}

/// Translates the move to position and see if the position is free
bool ChesstrisGame::isValidMove(const MOVE move)
{
	if (move < '1' || move > '8')
		return false;

	int mi = move - '1';
	int mpx = posX + moves[mi].x();
	int mpy = posY + moves[mi].y();
	return isValidMovePos(mpx, mpy);
}

/// Check the directions and see how many stepped tiles are there
/// Calculate scope and update the board
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
		int n = count[i] + count[i + 4] + 1; 
		if (n >= _SCORING_LEN)
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

	// Make the move
	_board.MarkStepedPos(posX, posY);
	int mi = move - '1';
	posX += moves[move - '1'].x();
	posY += moves[move - '1'].y();
	_board.SetKnightAtPos(posX, posY);
	
	// Now check the new position
	// and prepare the next move
	
	EvaluateState();

	// Clear the moves of last turn
	_board.ClearMoves();

	// Mark available moves and see if there's any at all
	_ended = (MarkValidMoves() == 0);
}

int ChesstrisGame::MarkValidMoves()
{
	// Mark the valid moves for this turn
	// If there are no valid moves the game is over
	int numValidMoves = 0; // for now
	for (int i = 0; i < DIM_OF(moves); i++)
	{
		int mpx = posX + moves[i].x();
		int mpy = posY + moves[i].y();
		if (isValidMovePos(mpx, mpy))
		{
			_board.MarkMoveAtPos(mpx, mpy, '1' + i);
			numValidMoves++; // Ok, there's a valid move
		}
	}
	return numValidMoves;
}

void ChesstrisGame::EndShow() {
	draw();
	cout << "The End!" << endl;
}

bool ChesstrisGame::isValidMovePos(int x, int y)
{
	return (_board.IsValidPos(x, y) && _board.IsClearPos(x, y));
}

void ChesstrisGame::draw() 
{
	// Check for end of game
	cout << endl << "Score: [" << _score << "] - Last move points: [" << _lastMovePoints << "]" << endl;
	_board.draw();
}