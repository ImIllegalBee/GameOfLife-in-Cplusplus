#include "Board.hpp"

#include <iostream>

Board::Board(const int& width, const int& height)
{
    m_Width = width;
    m_Height = height;

    unsigned char** tmpContentPtr = (unsigned char**) malloc(width * height * sizeof(unsigned char*));
    if (!tmpContentPtr)
        throw;

    for (int i = 0; i < m_Height; i++)
    {
        tmpContentPtr[ i ] = (unsigned char*) malloc(width * height * sizeof(unsigned char));
        if (!tmpContentPtr[ i ])
            throw;

        for (int j = 0; j < m_Width; j++)
            tmpContentPtr[ i ][ j ] = 0;
    }

    // DEBUG
    {
        tmpContentPtr[ 2 ][ 2 ] = 1;
        tmpContentPtr[ 2 ][ 4 ] = 1;
        tmpContentPtr[ 3 ][ 3 ] = 1;
        tmpContentPtr[ 3 ][ 1 ] = 1;
        tmpContentPtr[ 2 ][ 2 ] = 1;
        tmpContentPtr[ 2 ][ 3 ] = 1;
        tmpContentPtr[ 2 ][ 4 ] = 1;
        tmpContentPtr[ 3 ][ 2 ] = 1;
        tmpContentPtr[ 3 ][ 3 ] = 1;
        tmpContentPtr[ 4 ][ 2 ] = 1;
        tmpContentPtr[ 4 ][ 4 ] = 1;
        tmpContentPtr[ 3 ][ 5 ] = 1;
        tmpContentPtr[ 3 ][ 4 ] = 1;
        tmpContentPtr[ 2 ][ 5 ] = 1;
        tmpContentPtr[ 2 ][ 6 ] = 1;
    }

    m_Content = tmpContentPtr;
}

Board::~Board()
{
    for (int i = 0; i < m_Height; i++)
        free(m_Content[ i ]);

    free(m_Content);
}

void Board::PrintBoard()
{
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif // _WIN32

    static unsigned char terminalOutput[ 2048 ] = { 0 };

    int charIndx = 0;
    for (int i = 0; i < m_Height; i++)
    {
        for (int j = 0; j < m_Width; j++)
        {
            terminalOutput[ charIndx++ ] = m_Content[ i ][ j ] ? FULL_BLOCK_CHAR : EMPTY_BLOCK_CHAR;
        }

        terminalOutput[ charIndx++ ] = '\n';
    }

    terminalOutput[ charIndx ] = '\0';
    std::cout << terminalOutput;
}
