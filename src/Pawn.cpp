#include <iostream>
#include "Pawn.h"
#include "Constans.h"
using namespace std;
class Piece;
Pawn::Pawn(Color color) : Piece(color){
    pieceType = PAWN;
}
bool Pawn::islegal(int x1, int y1, int x2, int y2){
    if (color==WHITE){


//            cout << x1 << y1 << x2 << y2 << endl;
//            cout << (x2==x1 and y2-y1==-1) << endl;
        if(y2-y1==-1 && x2==x1) return true;
        else if (y2==4 && y1==6 && x2==x1) return true;
        else {
                cout << chessboard->isEmpty2(x2, y2) << endl;
                if (y2-y1==-1 and (x2-x1==1 or x2-x1==-1) and !(chessboard->isEmpty2(x2, y2)) and chessboard->isFieldOccupiedByOponent(x2, y2, color)) return true;
        else return false;
        }
    }
    else {
        if(y2-y1==1 and x2==x1) return true;
        else if (y2==3 and y1==1 and x2==x1) return true;
        else if (y2-y1==1 and (x2-x1==1 or x2-x1==-1) and !(chessboard->isEmpty2(x2, y2)) and chessboard->isFieldOccupiedByOponent(x2, y2, color)) return true;
        else return false;
    }


}

