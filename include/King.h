#ifndef KING_H
#define KING_H
#include "Piece.h"
#include "Player.h"

class King : public Piece{

public:
    King(Color color);
    bool islegal(int x1, int y1, int x2, int y2);
};

#endif // KING_H
