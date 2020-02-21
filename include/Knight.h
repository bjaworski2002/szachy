#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"
#include "Player.h"

class Knight : public Piece{

public:
    Knight(Color color);
    bool islegal(int x1, int y1, int x2, int y2);
};

#endif // KNIGHT_H
