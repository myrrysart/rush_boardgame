
#include "Santorini.hpp"


void Santorini::initWorkers()
{

    std::pair<int, int> input = {-1, -1};

     while (isValidInput(input, PLAYER1) == false)
        input = take_input();
    
    _board[input.first][input.second].worker = 1;
    
    print();

    std::cout << "Player one choose an empty grid to place second worker" << std::endl;

     while (isValidInput(input, PLAYER1) == false || _board[input.first][input.second].worker != 0)
        input = take_input();
    
    _board[input.first][input.second].worker = 1;
    print();

    std::cout << "Player two choose an empty grid to place first worker" << std::endl;

     while (isValidInput(input, PLAYER2) == false || _board[input.first][input.second].worker != 0)
        input = take_input();
    print();

    _board[input.first][input.second].worker = 2;

     std::cout << "Player two choose an empty grid to place second worker" << std::endl;

     while (isValidInput(input, PLAYER2) == false || _board[input.first][input.second].worker != 0)
        input = take_input();
    print();
    
    _board[input.first][input.second].worker = 2;
}


bool Santorini::isValidInput(const std::pair<int, int> &input, int Player)
{
    if (input.first == GIVEUP)
    {
        if (Player == PLAYER1)
            std::cout << "Player 2 won";
        else
            std::cout << "Player 1 won";
        exit(0);
    }
    if (input.first < 0)
        return false;
    if (input.first > 4)
        return false;
    if (input.second < 0)
        return false;
    if (input.second > 4)
        return false;
    return true;

}

std::pair<int, int> &Santorini::moveWorker(int Player)
{
    std::cout << "Select a tile that includes your worker" << std::endl;

    std::pair<int, int> input = {-1, -1};

    while (isValidInput(input, Player) == false || _board[input.first][input.second].worker != 0 || _board[input.first][input.second].worker != Player)
    {
        input = take_input();   
    }
    std::cout << "Select a tile to move to" << std::endl;
    
    std::pair<int, int> source = input;

    while (isValidInput(input, Player) == false || _board[input.first][input.second].worker != 0 || std::abs(input.first - source.first) > 1 || std::abs(input.second - source.second) > 1)
    {
        input = take_input(); 
    }
    _board[source.first][source.second].worker = 0;
    _board[input.first][input.second].worker = Player;

    return input;

}
