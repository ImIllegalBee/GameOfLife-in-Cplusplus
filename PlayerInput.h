#pragma once

#include <atomic>
#include <thread>

class PlayerInput
{
public:

    PlayerInput() = default;

    ~PlayerInput();

public:

    void SpawnInputThread();

public:

    bool GetQuit() { return m_Quit.load(); }

private:

    void CatchInput();

private:

    std::atomic_bool m_IsThreadOn = false;
    std::thread m_InputThread;

    std::atomic_bool m_Quit = false;
};
