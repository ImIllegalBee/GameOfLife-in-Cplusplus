#pragma once

#define EMPTY_BLOCK_CHAR 176
#define FULL_BLOCK_CHAR 178

class Board
{
public:

    Board() :
        Board(0, 0)
    {}

    Board(const int& width, const int& height);

    ~Board();

public:

    /*
    * Print in terminal */
    void PrintBoard();

public:

    void SwapContent(Board& swap)
    {
        unsigned char** tmpContentPtr = m_Content;
        m_Content = swap.m_Content;
        swap.m_Content = tmpContentPtr;
    }

public:
    // Getters

    const int& GetWidth() { return m_Width; }

    const int& GetHeigh() { return m_Height; }

    unsigned char** GetContent() { return m_Content; }

private:

    int m_Width = 0;
    int m_Height = 0;

    unsigned char** m_Content = nullptr;

};
