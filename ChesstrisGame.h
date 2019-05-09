#pragma once

#include "ChesstrisBoard.h"
#include "IGame.h"

using namespace std;

namespace Chesstris {
	/// Chesstris Game
	class ChesstrisGame : public IGame {

		// How many 
		const int _SCORING_LEN;

		bool _ended; // Set to true when game ended

		int _numMoves; // Counts the number of moves

		int _score; // Keeps the score

		int _lastMovePoints; // The points earned in last move

		ChesstrisBoard _board; // The game board holds the current state

		int posX; // The X position of the Knight
		int posY; // The Y position of the Knight

		// True if pos is valid and clear
		bool isValidMovePos(int x, int y);

		// Evaluate state after move
		void EvaluateState();

		// Return number of availale valid moves
		int MarkValidMoves();

		// Display the game banner
		void Banner();

	public:
		ChesstrisGame(int score_len = 4);

		virtual IBoard& getBoard();

		virtual void start();

		virtual bool ended();

		virtual bool isValidMove(const MOVE move);

		virtual void move(const MOVE move);

		virtual void EndShow();

		virtual void draw();
	};

}// Chesstris namespace ends here