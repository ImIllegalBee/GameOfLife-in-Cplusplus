#include "Board.hpp"
#include "GameLogic.hpp"
#include "PlayerInput.h"

#include <chrono>
#include <thread>
#include <iostream>

#define BOARD_SIZE_W 80
#define BOARD_SIZE_H 16

#define GAME_UPDATE_LATENCY 100ms

int main()
{
    using namespace std::chrono_literals;

    Board myBoard(BOARD_SIZE_W, BOARD_SIZE_H);
    Board dummy(BOARD_SIZE_W, BOARD_SIZE_H);

    PlayerInput pI = {};

    pI.SpawnInputThread();

    while (!pI.GetQuit())
    {
        myBoard.PrintBoard();
        UpdateGame(myBoard, dummy);

        std::this_thread::sleep_for(GAME_UPDATE_LATENCY);
    }

    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif // _WIN32

    std::cout << "The end" << std::endl;
    std::cout << "GGs";
    std::this_thread::sleep_for(GAME_UPDATE_LATENCY * 25);
}