#include "QuartoGame.h"

QuartoGame::QuartoGame(bool gameDifficultyLevel)
    : DIFFICULTY_LEVEL(gameDifficultyLevel)
{
    playerActive = 0;
    numberOfUsedPieces = 0;
}

/*
QuartoGame::~QuartoGame()
{
    cout << "game destructor"<<endl;
}
*/

void QuartoGame::putPieceOnBoard(int row, int column, int pieceNumber)
{
    board[row][column] = pieces[pieceNumber].getPieceType();
    pieces[pieceNumber].setPieceAsUsed();
    numberOfUsedPieces++;
}

void QuartoGame::changePlayer()
{
    playerActive = !playerActive;
}

bool QuartoGame::isGameFinishedInEasyVersion(int row, int column)
{
    if ((board[row][0]&board[row][1]&board[row][2]&board[row][3]) != 0)
    {
        winningPattern[row][0] = 1;
        winningPattern[row][1] = 1;
        winningPattern[row][2] = 1;
        winningPattern[row][3] = 1;
        return true;
    }
    else if ((board[0][column]&board[1][column]&board[2][column]&board[3][column]) != 0)
    {
        winningPattern[0][column] = 1;
        winningPattern[1][column] = 1;
        winningPattern[2][column] = 1;
        winningPattern[3][column] = 1;
        return true;
    }
    else if ((board[0][0]&board[1][1]&board[2][2]&board[3][3]) != 0)
    {
        winningPattern[0][0] = 1;
        winningPattern[1][1] = 1;
        winningPattern[2][2] = 1;
        winningPattern[3][3] = 1;
        return true;
    }
    else if ((board[3][0]&board[2][1]&board[1][2]&board[0][3]) != 0)
    {
        winningPattern[3][0] = 1;
        winningPattern[2][1] = 1;
        winningPattern[1][2] = 1;
        winningPattern[0][3] = 1;
        return true;
    }
    else return false;
}

bool QuartoGame::isGameFinishedInHardVersion(int row, int column)
{
    if (column < 3 && row < 3)
    {
        if ((board[row][column]&board[row][column+1]&board[row+1][column+1]&board[row+1][column]) != 0)
        {
            winningPattern[row][column] = 1;
            winningPattern[row][column+1] = 1;
            winningPattern[row+1][column+1] = 1;
            winningPattern[row+1][column] = 1;
            return true;
        }
    }
    if (column > 0 && row < 3)
    {
        if ((board[row][column]&board[row+1][column]&board[row+1][column-1]&board[row][column-1]) != 0)
        {
            winningPattern[row][column] = 1;
            winningPattern[row+1][column] = 1;
            winningPattern[row+1][column-1] = 1;
            winningPattern[row][column-1] = 1;
            return true;
        }
    }
    if (column > 0 && row > 0)
    {
        if ((board[row][column]&board[row][column-1]&board[row-1][column-1]&board[row-1][column]) != 0)
        {
            winningPattern[row][column] = 1;
            winningPattern[row][column-1] = 1;
            winningPattern[row-1][column-1] = 1;
            winningPattern[row-1][column] = 1;
            return true;
        }
    }
    if (column < 3 && row > 0)
    {
        if ((board[row][column]&board[row-1][column]&board[row-1][column+1]&board[row][column+1]) != 0)
        {
            winningPattern[row][column] = 1;
            winningPattern[row-1][column] = 1;
            winningPattern[row-1][column+1] = 1;
            winningPattern[row][column+1] = 1;
            return true;
        }
    }
    return false;
}

int QuartoGame::makeMove(int row, int column, int pieceNumber)
{
    putPieceOnBoard(row,column,pieceNumber);
    bool isFinished;
    int result = 0;

    if (DIFFICULTY_LEVEL)
    {
        isFinished = isGameFinishedInHardVersion(row,column);
    }
    else
    {
        isFinished = isGameFinishedInEasyVersion(row,column);
    }

    if (isFinished)
    {
        if (playerActive)
        {
            result = 2;
        }
        else
        {
            result = 1;
        }
    }
    else if (numberOfUsedPieces == 16)
    {
        result = 3;
    }
    else
    {
        changePlayer();
    }
    return result;
}

bool QuartoGame::isPieceUsed(int numberOfPiece)
{
    return pieces[numberOfPiece].isPieceUsed();
}

bool QuartoGame::isBoardFieldFree(int row, int column)
{
    if (board[row][column] == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool QuartoGame::getWinningPatternField(int row, int column)
{
    return winningPattern[row][column];
}

char QuartoGame::getPieceType(int numberOfPiece)
{
    return pieces[numberOfPiece].getPieceType();
}

bool QuartoGame::getPlayerActive()
{
    return playerActive;
}

char QuartoGame::getPieceTypeFromBoardField(int row, int column)
{
    return board[row][column];
}

int QuartoGame::findPieceNumber(char typeOfPiece)
{
    int pieceNumber = 100;
    for (int i = 0; i < 16; i++)
    {
        if (pieces[i].getPieceType() == typeOfPiece)
        {
            if (pieces[i].isPieceUsed() == false)
            {
                pieceNumber = i;
            }
            break;
        }
    }
    return pieceNumber;
}



