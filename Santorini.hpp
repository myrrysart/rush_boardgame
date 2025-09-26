
#pragma once
#include <iostream>
#include <vector>

#define PLAYER_1_VICTORY std::pair{200, 0}
#define PLAYER_2_VICTORY std::pair{300, 0}
#define PLAYER1 1
#define PLAYER2 2
#define GIVEUP std::pair{-200, 0}

enum e_state {
	PLAYER1_INIT_WORKER1,
	PLAYER1_INIT_WORKER2,
	PLAYER1_CHOOSE_WORKER,
	PLAYER1_MOVE_WORKER,
	PLAYER1_BUILD,
	PLAYER2_INIT_WORKER1,
	PLAYER2_INIT_WORKER2,
	PLAYER2_CHOOSE_WORKER,
	PLAYER2_MOVE_WORKER,
	PLAYER2_BUILD
}

class Santorini
{
    public:
        bool gameRunning = true;
        int pieces[4] = {22, 18, 14, 18};
        //There are more domes than lvl 3 pieces so domes cannot run out;

        bool isValidInput(const std::pair<int, int> &input, int player);
		bool Santorini::placeWorker(const std::pair<int, int> &coords, int player);
		bool Santorini::chooseWorker(const std::pair<int, int> &coords, int player);
		bool Santorini::moveWorker(const std::pair<int, int> &coords, int player);
		bool Santorini::build(const std::pair<int, int> &coords, int player);
        void Santorini::printBoard();

        class Cell
        {
            public:
                int lvl = 0;
                int worker = 0;
        };

        Cell _board[5][5];
		e_state gameState;
		std::pair<int, int> chosenSquare;
};
