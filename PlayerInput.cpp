#include "PlayerInput.h"

#ifdef _WIN32
#include <Windows.h>
#endif // _WIN32

#include <iostream>

PlayerInput::~PlayerInput()
{
    if (m_IsThreadOn.load())
    {
        m_IsThreadOn.store(false);
        m_InputThread.join();
    }
}

void PlayerInput::SpawnInputThread()
{
    if (m_IsThreadOn.load())
        return;

    m_IsThreadOn.store(true);
    m_InputThread = std::thread(&PlayerInput::CatchInput, this);
}

void PlayerInput::CatchInput()
{
    #ifdef _WIN32
    DWORD numberOfEvents;
    INPUT_RECORD iRec;
    HANDLE console = GetStdHandle(STD_INPUT_HANDLE);

    // Console not found
    if (console == NULL)
        return;

    for (;;)
    {
        ReadConsoleInput(console, &iRec, 1, &numberOfEvents);

        if (iRec.EventType == KEY_EVENT
            && ( (KEY_EVENT_RECORD&) iRec.Event ).bKeyDown)
        {
            // std::cout << ( (KEY_EVENT_RECORD&) iRec.Event ).uChar.AsciiChar;

            if (( (KEY_EVENT_RECORD&) iRec.Event ).uChar.AsciiChar == 'q')
            {
                m_Quit.store(true);

                return;
            }
        }
    }

    return;
    #endif // _WIN32

    throw;
}
