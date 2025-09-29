
#pragma once
#include <iostream>
#include <vector>
#include <array>

#define PLAYER_1_VICTORY std::pair{200, 0}
#define PLAYER_2_VICTORY std::pair{300, 0}
#define PLAYER1 1
#define PLAYER2 2
#define GIVEUP std::pair{-200, 0}


class Santorini
{
    public:
        bool gameRunning = true;
        std::array<int, 4> pieces = {22, 18, 14, 18};
        //There are more domes than lvl 3 pieces so domes cannot run out;

        bool isValidInput(const std::pair<int, int> &input, int player);
		bool placeWorker(const std::pair<int, int> &coords, int player);
		bool chooseWorker(const std::pair<int, int> &coords, int player);
		bool moveWorker(const std::pair<int, int> &coords, int player);
		bool build(const std::pair<int, int> &coords, int player);
        void printBoard();
		int	victoryCheck();
		
		enum State {
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
		};

        class Cell
        {
            public:
                int lvl = 0;
                int worker = 0;
        };

        Cell _board[5][5];
		State gameState = State::PLAYER1_INIT_WORKER1;
		std::pair<int, int> chosenSquare = {-1, -1};
		int turn = 0;
};
