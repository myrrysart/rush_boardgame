
#pragma once
#include <iostream>
#include <vector>

#define PLAYER_1_VICTORY 200
#define PLAYER_2_VICTORY 300
#define PLAYER1 1
#define PLAYER2 2
#define GIVEUP -200


class Santorini
{
    public:
        bool gameRunning = true;
        int lvl_1_piece = 22;
        int lvl_2_piece = 18;
        int lvl_3_piece = 14;
        //There are more domes than lvl 3 pieces so domes cannot run out;

        void initWorkers();
        bool isValidInput(const std::pair<int, int> &input, int player);
        int moveWorker(int Player);

        class Cell
        {
            public:
                int lvl = 0;
                int worker = 0;
        };

        Cell _board[5][5];
    

};
