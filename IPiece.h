#pragma once

namespace Chesstris {
	class IBoard;

	/// An abstract game piece class.
	class IPiece
	{
		IBoard* _board;
	protected:
		IPiece() {}
	public:
		virtual ~IPiece() {}
		virtual bool IsOnBoard(IBoard* board) = 0;
		//virtual bool TryMove()
	};

}
