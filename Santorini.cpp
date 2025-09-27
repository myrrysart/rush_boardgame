
#include "Santorini.hpp"

bool Santorini::isValidInput(const std::pair<int, int> &input, int Player)
{
    if (input == GIVEUP)
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

bool Santorini::placeWorker(const std::pair<int, int> &coords, int player)
{
	if (this->_board[coords.first][coords.second].worker == 0)
	{
		this->_board[coords.first][coords.second].worker = player;
		return true;
	}
	else
	{
		std::cout << "square occupied" << std::endl;
		return false;
	}
}

bool Santorini::chooseWorker(const std::pair<int, int> &coords, int player)
{
	if (this->_board[coords.first][coords.second].worker == player)
	{
		std::cout << "Chose worker at " << coords.first << "," << coords.second << std::endl;
		this->chosenSquare = coords;
		return true;
	}
	else
	{
		std::cout << "No worker of yours at " << coords.first << "," << coords.second << std::endl;
		return false;
	}
}



bool Santorini::moveWorker(const std::pair<int, int> &coords, int player)
{
    
    if (this->_board[coords.first][coords.second].worker != 0 )
	{
		std::cout << "Square occupied" <<std::endl;
		return false;
	}
	if (std::abs(coords.first - this->chosenSquare.first) > 1 || std::abs(coords.second - this->chosenSquare.second) > 1
		|| (coords.first == this->chosenSquare.first && coords.second == this->chosenSquare.second))
	{
		std::cout << "Need to move exactly one square" <<std::endl;
		return false;
	}
	if (this->_board[coords.first][coords.second].lvl == 4)
	{
		std::cout << "Square has a dome" <<std::endl;
		return false;
	}
	if (this->_board[coords.first][coords.second].lvl > this->_board[this->chosenSquare.first][this->chosenSquare.second].lvl + 1 )
    {
    	std::cout << "Target more than one level above worker" <<std::endl;
		return false;
    }	
    this->_board[this->chosenSquare.first][this->chosenSquare.second].worker = 0;
    this->_board[coords.first][coords.second].worker = player;
	this->chosenSquare = coords;
    return true;
}

bool Santorini::build(const std::pair<int, int> &coords, int player)
{
    if (std::abs(coords.first - this->chosenSquare.first) > 1 || std::abs(coords.second - this->chosenSquare.second) > 1)
	{
		std::cout << "Too far from worker" <<std::endl;
		return false;
	}
	if (this->_board[coords.first][coords.second].lvl > 3)
	{
		std::cout << "Fully built already" <<std::endl;
		return false;
	}
	if (this->_board[coords.first][coords.second].worker != 0)
	{
		std::cout << "Square occupied" <<std::endl;
		return false;
	}
	if (this->pieces[this->_board[coords.first][coords.second].lvl] == 0)
    { 
      	std::cout << "No more required pieces" <<std::endl;
		return false;
	}
    // After validation and piece availability, increment the level to build
	this->pieces[this->_board[coords.first][coords.second].lvl]--;
    this->_board[coords.first][coords.second].lvl++;
	this->chosenSquare = {-1, -1};
	return true;
}

void	Santorini::printBoard()
{
	for (int i = 0; i < 5; ++i)
	{
		std::cout << "|";
		for (int j = 0; j < 5; ++j)
		{
			std::cout << this->_board[i][j].lvl;
			if (this->_board[i][j].worker == PLAYER1)
				std::cout << "P1";
			if (this->_board[i][j].worker == PLAYER2)
				std::cout << "P2";
			std::cout << "|";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
