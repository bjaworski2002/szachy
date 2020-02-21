#ifndef FIELD_H
#define FIELD_H
#include "Piece.h"

class Piece;
class Field{
    int x;
    int y;
    Piece* p;
public:
    Field();
    void setPiece(Piece * piece);
    void print();
    Piece* getPiece();
    bool isEmpty();
    bool isEmpty2();
};
#endif // FIELD_H
