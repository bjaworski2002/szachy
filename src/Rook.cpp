#include "Rook.h"
#include "Constans.h"
class Piece;
Rook::Rook(Color color) : Piece(color){
    pieceType = ROOK;
}
bool Rook::islegal(int x1, int y1, int x2, int y2){
    return ((x2==x1) or (y2==y1));
}
