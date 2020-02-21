#include "Chessboard.h"
#include "Constans.h"
#include <iostream>
using namespace std;
class Piece;
void Chessboard::setPieces(Player* player){
        if(player->getColor()==WHITE){
            for(int i=0; i<8; i++)
                board[6][i].setPiece(player->getPiece(i));
        }
        else{
            for(int i=0; i<8; i++)
                board[1][i].setPiece(player->getPiece(i));
        }
        if(player->getColor()==WHITE){
            for(int i=8; i<16; i++)
                board[7][i-8].setPiece(player->getPiece(i));
        }
        else{
            for(int i=8; i<16; i++)
                board[0][i-8].setPiece(player->getPiece(i));
        }

    }
    bool Chessboard::isEmpty(int x, int y){
        return board[y][x].isEmpty();
    }
    bool Chessboard::isEmpty2(int x, int y){
        return board[y][x].isEmpty();
    }
    bool Chessboard::isFieldOccupiedByOponent(int x, int y, Color color){
        cout << "ISFIELDOCCUPIED" << endl;
        return getPiece(x, y)->getColor()!=color;
    }
    bool Chessboard::isBetween(int x1, int y1, int x2, int y2){
        if(x1==x2 or y1==y2){
            if(y2-y1>0) swap(y1,y2);
            else if(x2-x1>0){
                swap(y2, x1);
                swap(y1, x2);
            }
            else if(x2-x1<0){
                swap(x1, y1);
                swap(x2, y2);
            }
            for(int i=y2+1; i<y1; i++){
                if(!(isEmpty(x1, i))) return true;
            }
            return false;
        }
        else{
            if(x2-x1<0 and y2-y1>0){
                swap(x1,x2);
                swap(y1,y2);
                cout << "LEWO DOL" << endl;
            }
            else if(x2-x1<0 and y2-y1<0){
                swap(x1,x2);
                cout << "LEWO GORA" << endl;
            }
            else if(x2-x1>0 and y2-y1>0){
                swap(y1, y2);
                cout << "PRAWO DOL" << endl;
            }
            for(int i=1; i<x2-x1; i++){
                if(!(isEmpty(x1+i, y1-i))) return true;
            }
            return false;
        }
    }
    Piece* Chessboard::getPiece(int x, int y){
        return board[y][x].getPiece();
    }
    void Chessboard::setPiece(int x, int y, Piece* p){
        board[y][x].setPiece(p);
    }
    void Chessboard::print(){
        cout << "  ";
        for(int i=0; i<8; i++){
            char n = i+65;
            cout << " " <<n;
        }
        cout << endl;
        for(int i=0; i<8; i++){
            cout << 8-i << " ";

            for (int j=0; j<8; j++){
                if(board[i][j].isEmpty()){
                    if((i+j)%2 == 0) cout << char(176) << char(176);
                    else cout << char(177) << char(177);
                }
                else board[i][j].print();
            }
            cout << " " << 8-i;
            cout << endl;
        }
        cout << "  ";
        for(int i=0; i<8; i++){
            char n = i+65;
            cout << " " <<n;
        }
        cout << endl;
    }
