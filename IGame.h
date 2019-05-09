#pragma once

#include "Chesstris.h"

namespace Chesstris {
	class IBoard;

	/// An abstract game class
	class IGame
	{
	protected:
		IGame() {}
	public:
		virtual ~IGame() {}

		/// Start the game
		virtual void start() = 0;

		/// Make a move
		virtual void move(const MOVE) = 0;

		/// Display some game over banner
		virtual void EndShow() = 0;

		/// True if game is over
		virtual bool ended() = 0;

		/// Get the game board
		virtual IBoard& getBoard() = 0;

		/// Check if a move is valid
		virtual bool isValidMove(const MOVE) = 0;

		/// Draw the game
		virtual void draw() = 0;
	};

}

