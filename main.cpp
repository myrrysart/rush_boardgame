

#include "Santorini.hpp"

#define PLAYER_1_VICTORY 200
#define PLAYER_2_VICTORY 300
#define PLAYER1 1
#define PLAYER2 2

int main(void)
{

    Santorini mySant;

    std::cout << "Player one choose a grid to place first worker" << std::endl;

    
    

    mySant.initWorkers();
    while (mySant.gameRunning == true)
    {
        int buildlocation = -1;
        buildlocation = mySant.moveWorker(PLAYER1);
        if (buildlocation != PLAYER_1_VICTORY || buildlocation != PLAYER_2_VICTORY) //Player 1 wins if he can reach level 3, player 2 wins if he cant move at all
            mySant.build(buildlocation);
        buildlocation = mySant.moveWorker(PLAYER1);
        if (buildlocation != PLAYER_2_VICTORY || buildlocation != PLAYER_1_VICTORY)
            mySant.build(buildlocation);

    }
    

}