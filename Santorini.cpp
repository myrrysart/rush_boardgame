
#include "Santorini.hpp"


void Santorini::initWorkers()
{

    std::pair<int, int> input = {-1, -1};

     while (input.first < 0 || input.first > 4 || input.second < 0 || input.second > 4)
        input = take_input();
    
    _board[input.first][input.second].worker = 1;
    

    std::cout << "Player one choose an empty grid to place second worker" << std::endl;

     while (input.first < 0 || input.first > 4 || input.second < 0 || input.second > 4 || mySant._board[input.first][input.second].worker != 0)
        input = take_input();
    
    _board[input.first][input.second].worker = 1;

    std::cout << "Player two choose an empty grid to place first worker" << std::endl;

     while (input.first < 0 || input.first > 4 || input.second < 0 || input.second > 4 || mySant._board[input.first][input.second].worker != 0)
        input = take_input();
    
    _board[input.first][input.second].worker = 2;

     std::cout << "Player two choose an empty grid to place second worker" << std::endl;

     while (input.first < 0 || input.first > 4 || input.second < 0 || input.second > 4 || mySant._board[input.first][input.second].worker != 0)
        input = take_input();
    
    _board[input.first][input.second].worker = 2;
}