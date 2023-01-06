#include "Piece.h"

Piece::Piece(int pieceType)
{
    type = 0;
    isAlreadyUsed = false;

    /*
    each piece has four characteristics determined by bits set at 1 according to the below list:
    - color: dark (1st bit) or light (2nd bit),
    - shape: round (3rd bit) or square (4th bit),
    - height: tall (5th bit) or short (6th bit),
    - texture: solid (7th bit) or hollow (8th bit),
    */

    /*
    pieces are collected in table in object of class QuartoGame, in the below list given are piece types
    corresponding to each position in the table - position in table is equal to pieceType argument
    of Piece constructor
    - 0 - DRTS
    - 1 - DRTH
    - 2 - DRSS
    - 3 - DRSH
    - 4 - DSTS
    - 5 - DSTH
    - 6 - DSSS
    - 7 - DSSH
    - 8 - LRTS
    - 9 - LRTH
    - 10 - LRSS
    - 11 - LRSH
    - 12 - LSTS
    - 13 - LSTH
    - 14 - LSSS
    - 15 - LSSH
    */

    //color
    if (pieceType < 8)
    {
        type = type | 1 << 0;
    }
    else
    {
        type = type | 1 << 1;
    }

    //shape
    if (pieceType % 8 < 4)
    {
        type = type | 1 << 2;
    }
    else
    {
        type = type | 1 << 3;
    }

    //height
    if (pieceType % 4 < 2)
    {
        type = type | 1 << 4;
    }
    else
    {
        type = type | 1 << 5;
    }

    //texture
    if (pieceType % 2 < 1)
    {
        type = type | 1 << 6;
    }
    else
    {
        type = type | 1 << 7;
    }
}

/*
Piece::~Piece()
{
    cout << "piece destructor" << type << endl;
}
*/

void Piece::setPieceAsUsed()
{
    isAlreadyUsed = true;
}

void Piece::setPieceAsFree()
{
    isAlreadyUsed = false;
}

bool Piece::isPieceUsed()
{
    if (isAlreadyUsed) return true;
    else return false;
}

char Piece::getPieceType()
{
    return type;
}
