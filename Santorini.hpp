
#pragma once
#include <iostream>
#include <vector>

class Santorini
{
    public:
    int lvl_1_piece = 22;
    int lvl_2_piece = 18;
    int lvl_3_piece = 14;
    //There are more domes than lvl 3 pieces so domes cannot run out;

    void initWorkers();

    

    class Cell
    {
        public:
            int lvl = 0;
            int worker = 0;
    };

    Cell _board[5][5];
    

};
