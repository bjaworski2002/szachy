#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"
#include "Player.h"

class Queen : public Piece{

public:
    Queen(Color color);
    bool islegal(int x1, int y1, int x2, int y2);

};

#endif // QUEEN_H
