#include <cmath>
#include "King.h"
#include "Constans.h"
using namespace std;
class Piece;
King::King(Color color) : Piece(color){
    pieceType = KING;
}
bool King::islegal(int x1, int y1, int x2, int y2){
    return(abs(x2-x1)<=1 && abs(y2-y1)<=1);
}
