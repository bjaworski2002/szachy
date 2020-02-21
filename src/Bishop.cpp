#include "Bishop.h"
#include "Constans.h"

class Piece;
Bishop::Bishop(Color color) : Piece(color){
    pieceType = BISHOP;
}
bool Bishop::islegal(int x1, int y1, int x2, int y2){
    return (x2+y2 == x1+y1 or x2-y2 == x1-y1);
}
