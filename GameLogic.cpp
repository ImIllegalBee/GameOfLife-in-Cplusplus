#include "GameLogic.hpp"

void UpdateGame(Board& main, Board& dummy)
{
    for (int i = 0; i < main.GetHeigh(); i++)
    {
        for (int j = 0; j < main.GetWidth(); j++)
        {
            // Load values
            const unsigned char curCellVal = main.GetContent()[ i ][ j ];
            unsigned char neighboursValues = 0;

            bool up = ( i - 1 ) >= 0,
                down = ( i + 1 ) < main.GetHeigh(),
                left = ( j - 1 ) >= 0,
                right = ( j + 1 ) < main.GetWidth();

            // Normal
            if (up)
                neighboursValues += main.GetContent()[ i - 1 ][ j ];

            if (down)
                neighboursValues += main.GetContent()[ i + 1 ][ j ];

            if (left)
                neighboursValues += main.GetContent()[ i ][ j - 1 ];

            if (right)
                neighboursValues += main.GetContent()[ i ][ j + 1 ];

            // Diagonal
            if (up && left)
                neighboursValues += main.GetContent()[ i - 1 ][ j - 1 ];

            if (up && right)
                neighboursValues += main.GetContent()[ i - 1 ][ j + 1 ];

            if (down && left)
                neighboursValues += main.GetContent()[ i + 1 ][ j - 1 ];

            if (down && right)
                neighboursValues += main.GetContent()[ i + 1 ][ j + 1 ];

            // Check to what value update the current cell
            if (curCellVal == 1 &&
                neighboursValues < 2)
            {
                dummy.GetContent()[ i ][ j ] = 0;
                continue;
            }

            if (curCellVal == 1 &&
                ( neighboursValues == 2 || neighboursValues == 3 ))
            {
                dummy.GetContent()[ i ][ j ] = 1;
                continue;
            }

            if (curCellVal == 1 &&
                neighboursValues > 3)
            {
                dummy.GetContent()[ i ][ j ] = 0;
                continue;
            }

            if (curCellVal == 0 &&
                neighboursValues == 3)
            {
                dummy.GetContent()[ i ][ j ] = 1;
                continue;
            }

            dummy.GetContent()[ i ][ j ] = 0;
        }
    }

    main.SwapContent(dummy);
}
