#include "ChesstrisBoard.h"

#include "Chesstris.h"
#include <iostream>
#include <assert.h>

#define EMPTY ' '
#define KNIGHT 'K'
#define STEPPED '*'

using namespace Chesstris;
using namespace std;

void ChesstrisBoard::ClearPos(int x, int y)
{
	assert(x >= 0);
	assert(x < 8);
	assert(y >= 0);
	assert(y < 8);

	tiles_[y][x] = EMPTY;
}

void ChesstrisBoard::MarkStepedPos(int x, int y)
{
	assert(x >= 0);
	assert(x < 8);
	assert(y >= 0);
	assert(y < 8);

	tiles_[y][x] = STEPPED;
}
void ChesstrisBoard::SetKnightAtPos(int x, int y)
{
	assert(x >= 0);
	assert(x < 8);
	assert(y >= 0);
	assert(y < 8);

	tiles_[y][x] = KNIGHT;
}


ChesstrisBoard::ChesstrisBoard()
{
	Clear();
}

ChesstrisBoard::~ChesstrisBoard()
{

}

void ChesstrisBoard::Clear()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			tiles_[i][j] = EMPTY;
			moves_[i][j] = 0;
		}
	}
}

/// The draw implementation uses the standard output.
/// Every tile is marked as [ ]
/// And can be eithr empty [ ] or stepped [*] or [K] Meaning the Knight is standing on it
void ChesstrisBoard::draw() {
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			int pos = j + 8 * i;
			cout << "[" << (moves_[i][j] > 0 ? moves_[i][j] : tiles_[i][j]) << "] ";
		}
		cout << endl << endl;
	}
}

void ChesstrisBoard::EndShow()
{
	cout << "The End!!!" << endl;
}

int ChesstrisBoard::MaxY() {
	return 8;
}

int ChesstrisBoard::MaxX() {
	return 8;
}

bool ChesstrisBoard::IsClearPos(int x, int y)
{
	assert(x >= 0);
	assert(x < 8);
	assert(y >= 0);
	assert(y < 8);

	return (EMPTY == tiles_[y][x]);
}

bool ChesstrisBoard::IsValidPos(int x, int y)
{
	return 
	(x >= 0) &&
	(x < 8) &&
	(y >= 0) &&
	(y < 8);
}

void ChesstrisBoard::MarkMoveAtPos(int x, int y, MOVE m)
{
	assert(x >= 0);
	assert(x < 8);
	assert(y >= 0);
	assert(y < 8);

	moves_[y][x] = m;
}
void ChesstrisBoard::ClearMoves()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			moves_[i][j] = 0;
		}
	}
}
