#include "IBoard.h"
#include "IPiece.h"
#include "IGame.h"
#include <iostream>
#include <assert.h>

#include "ChesstrisGame.h"

using namespace std;
using namespace Chesstris;

/// The main function handles command line arguments and then creates the game and runs 
/// a very basic generic game loop usingthe IGame abstract interface
int main(int argc, char* argv[])
{
	/// Command line argument: length of row that gives a score
	/// Default = 4
	int scoring_length = 4;
	if (argc > 1) {
		if (strlen(argv[1]) == 1 && *argv[1] > '1' && *argv[1] < '9')
			scoring_length = *argv[1] - '0';
		else
		{
			cout << "Invalid command line arguments" << endl;
			exit(0);
		}
	}

	// Create a new Chestris game
	ChesstrisGame TheGame(scoring_length);

	IGame& game = (IGame&)TheGame;

	// From here onward only abtract interfaces are used
	game.start();

	while (!game.ended())
	{
		game.draw();

		MOVE move(cin.get());

		if (game.isValidMove(move))
		{
			game.move(move);
		}
		else
		{
			cout << "Inavlid Move!" << endl;
		}
	}


	game.EndShow();
	cout << "Game over!" << endl;
}
