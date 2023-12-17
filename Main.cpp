#include <chrono>
#include <thread>

#include "Board.hpp"
#include "GameLogic.hpp"
#include "PlayerInput.h"

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

}