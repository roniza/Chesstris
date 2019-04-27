#pragma once

class IBoard;

class IPiece
{
	//IBoard* _board;
protected:
	IPiece() {}
public:
	virtual ~IPiece() {}
	virtual bool IsOnBoard(IBoard* board) = 0;
};

