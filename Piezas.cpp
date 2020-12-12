#include "Piezas.h"
#include <vector>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
    for(int i = 0; i < BOARD_ROWS; i++)
    {
        for(int j = 0; j < BOARD_COLS; j++)
        {
            board[i][j] = Blank;
        }
    }
    turn = X;//X first Turn
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
    for(int i = 0; i < BOARD_ROWS; i++)
    {
        for(int j = 0; j < BOARD_COLS; j++)
        {
            board[i][j] = Blank;//Blank Board
        }
    }
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. 
 * dropPiece does NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column)
{
    if(column < 0 || column >= BOARD_COLS)
    {
        return Invalid;
    }

    auto current_turn = turn;
    
    if(turn == O)
    {
        turn = X;//toggle X turn
    }
    
    else
    {
        turn = O;//toggle O turn
    }

    for(int row = 0; row < BOARD_ROWS; row++)
    {
        if(board[row][column] == Blank)
        {
            board[row][column] = current_turn;//Placing current element on blank place
            return current_turn;//returning placed element
        }

        if(row == BOARD_ROWS-1 && column == BOARD_COLS-1 && board[row][column]!=Blank)
        {
            return Blank;//column is full return Blank
        }
    }
    return Blank;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{   
    if(column < 0 || row < 0 || row >= BOARD_ROWS || column >= BOARD_COLS)
    {
        return Invalid;
    }
    if(board[row][column]==Blank)
    {
        return Blank;//Blank pieces 
    }
    else
    {
        return board[row][column];
    }
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
    int X_count = 0;
    int O_count = 0;

    for(int i = 0; i < BOARD_ROWS; i++)
    {
        int Row_X_count = 0;
        int Row_O_count = 0;
        for(int j = 0; j < BOARD_COLS; j++)
        {
            if(board[i][j] == X)
            {
                Row_X_count ++;
                if(Row_X_count > X_count)
                {
                    X_count = Row_X_count;
                }
            }
            else if(board[i][j] == O)
            {
                Row_O_count++;
                if(Row_O_count > O_count)
                {
                    O_count = Row_O_count;
                }
            }
            else
            {
                return Invalid;
            }
        }
    }

    for(int j = 0; j < BOARD_COLS; j++)
    {
        int Column_X_count= 0;
        int Column_O_count = 0;
        
        for(int i = 0; i < BOARD_ROWS; i++)
        {
            if(board[i][j] == X)
            {
                Column_X_count++;
                if(Column_X_count>X_count)
                {
                    X_count= Column_X_count;
                }
            }
            else if(board[i][j] == O)
            {
                Column_O_count++;
                if(Column_O_count>O_count)
                {
                    O_count= Column_O_count;   
                }
            }
            else
            {
                return Invalid;
            }
        }
    }


    if(X_count > O_count)
    {
        return X;
    }
    else if(X_count < O_count)
    {
        return O;
    }
    else if(X_count == O_count)
    {
        return Blank;
    }
    else
    {
        return Blank;
    }
    
}