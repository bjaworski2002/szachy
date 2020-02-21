#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include "Player.h"
#include "Piece.h"
#include "Field.h"
#include "Constans.h"
class Piece;
class Player;
class Field;
class Chessboard{
    Field board[8][8];
public:
    void setPieces(Player* player);
    bool isEmpty(int x, int y);
    bool isEmpty2(int x, int y);
    bool isFieldOccupiedByOponent(int x, int y, Color color);
    bool isBetween(int x1, int y1, int x2, int y2);
    Piece* getPiece(int x, int y);
    void setPiece(int x, int y, Piece* p);
    void print();

};

#endif // CHESSBOARD_H
