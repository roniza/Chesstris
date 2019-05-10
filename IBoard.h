#pragma once

namespace Chesstris {

	/// An abstract game board
	class IBoard
	{
	protected:
		IBoard() {}
	public:
		virtual ~IBoard() {}

		/// Draw the game board
		virtual void draw() = 0;
	};

}