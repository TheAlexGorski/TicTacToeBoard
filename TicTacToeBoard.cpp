#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  turnNum = 0;
  gameOver = false;
  maxTurns = BOARDSIZE*BOARDSIZE;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if (turn == X)
    turn = O;
  else
    turn = X;
  turnNum++;
  if (turnNum >= maxTurns - 1)
    gameOver = true;
  return turn;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  Piece placed = getPiece(row, column);
  if (placed != Blank)
    return placed;
  if (!gameOver)
  {
    board[row][column] = turn;
    toggleTurn();
  }
  return board[row][column];
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if ((row < 0 || row >= BOARDSIZE) || (column < 0 || column >= BOARDSIZE))
    return Invalid;
  return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  if (!gameOver)
    return Invalid;
  for (int i = 0; i < BOARDSIZE; i++)
  {
    int xCount = 0;
    int oCount = 0;
    for (int j = 0; j < BOARDSIZE; j++)
    {
      if (board[i][j] == X)
        xCount++;
      else
        oCount++;
    }
    if (xCount == BOARDSIZE)
      return X;
    if (oCount == BOARDSIZE)
      return O;
  }
  for (int i = 0; i < BOARDSIZE; i++)
  {
    int xCount = 0;
    int oCount = 0;
    for (int j = 0; j < BOARDSIZE; j++)
    {
      if (board[j][i] == X)
        xCount++;
      else
        oCount++;
    }
    if (xCount == BOARDSIZE)
      return X;
    if (oCount == BOARDSIZE)
      return O;
  }
  int xCount = 0;
  int oCount = 0;
  for (int i = 0; i < BOARDSIZE; i++)
  {
      if (board[i][i] == X)
        xCount++;
      else
        oCount++;
  }
  if (xCount == BOARDSIZE)
    return X;
  if (oCount == BOARDSIZE)
    return O;
  return Blank;
}
