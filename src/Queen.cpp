#include "Queen.h"
#include "Constans.h"
class Piece;
Queen::Queen(Color color) : Piece(color){
    pieceType = QUEEN;
}
bool Queen::islegal(int x1, int y1, int x2, int y2){
    return(((x2==x1) or (y2==y1)) or (x2+y2 == x1+y1 or x2-y2 == x1-y1));
}
