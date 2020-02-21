#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"
#include "Player.h"

class Rook : public Piece{
public:
    Rook(Color color);
    bool islegal(int x1, int y1, int x2, int y2);
};

#endif // ROOK_H
