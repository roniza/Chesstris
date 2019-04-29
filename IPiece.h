#pragma once

class IBoard;

/// An bastract game piece class
class IPiece
{
	//IBoard* _board;
protected:
	IPiece() {}
public:
	virtual ~IPiece() {}
	virtual bool IsOnBoard(IBoard* board) = 0;
};

