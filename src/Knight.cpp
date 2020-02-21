#include "Knight.h"
#include "Constans.h"
class Piece;
Knight::Knight(Color color) : Piece(color){
pieceType = KNIGHT;
}
bool Knight::islegal(int x1, int y1, int x2, int y2){
return ((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))==5;
}
