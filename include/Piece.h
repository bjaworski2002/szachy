#ifndef PIECE_H
#define PIECE_H
#include "Player.h"
#include "Chessboard.h"
#include "Constans.h"

enum PieceType{KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN};
class Chessboard;
class Piece{
protected:
    bool takendown;
    Color color;
    PieceType pieceType;
    Chessboard* chessboard;
    int x;
    int y;
public:
    Piece(Color color);
    virtual bool islegal(int x1, int y1, int x2, int y2){};
    bool isInChessboard(int x1, int y1, int x2, int y2);
    Color getColor();
    PieceType getPieceType();
    void setChessboard(Chessboard* chessboard);
    void print();
    void setTakenDown(bool takendown);
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
};

#endif // PIECE_H
