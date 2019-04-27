#include "IBoard.h"
#include "IPiece.h"
#include "IGame.h"
#include "main.h"
#include <iostream>
#include <assert.h>
#include "ChesstrisGame.h"

using namespace std;

int main()
{
	// Create a new Chestris game
	ChesstrisGame TheGame;

	IGame& game = (IGame&)TheGame;

	// From here onward only abtract interfaces
	game.start();

	while (!game.ended())
	{
		game.draw();
		MOVE move;

		cin >> move;
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
}
