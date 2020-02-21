#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"
#include "Player.h"



class Bishop : public Piece{

public:
    Bishop(Color color);
    bool islegal(int x1, int y1, int x2, int y2);
};
#endif // BISHOP_H
