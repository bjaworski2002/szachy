#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"
#include "Player.h"

class Pawn : public Piece{
    public:
    Pawn(Color color);
    bool islegal(int x1, int y1, int x2, int y2);
};

#endif // PAWN_H
