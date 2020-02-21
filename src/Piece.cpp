#include <iostream>
#include "Piece.h"
#include "Constans.h"

using namespace std;

Piece::Piece(Color color){
    this->color = color;
}
bool Piece::isInChessboard(int x1, int y1, int x2, int y2){
    return((x1<=7 and x1>=0) and (y1<=7 and y1>=0) and (x2<=7 and x2>=0) and (y2<=7 and y2>=0));
}
Color Piece::getColor(){
    return color;
}
PieceType Piece::getPieceType(){
    return pieceType;
}
void Piece::setChessboard(Chessboard* chessboard){
    this->chessboard = chessboard;
}
void Piece::setTakenDown(bool takendown){
    this->takendown=true;
}
void Piece::setX(int x){
    this->x=x;
}
void Piece::setY(int y){
    this->y=y;
}
int Piece::getX(){
    return x;
}
int Piece::getY(){
    return y;
}
void Piece::print(){
    if(color==BLACK) cout << 'B';
    else cout << 'W';
    switch(pieceType){
        case KING : cout << 'K'; break;
        case QUEEN : cout << 'Q'; break;
        case BISHOP : cout << 'B'; break;
        case KNIGHT : cout << 'N'; break;
        case ROOK : cout << 'R'; break;
        case PAWN : cout << 'P'; break;
    }
}

