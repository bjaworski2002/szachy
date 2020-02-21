#include "Player.h"
#include "Constans.h"
class Piece;
Player::Player(Color color){
    this->color = color;
    this->isCheck=false;
    for(int i=0; i<8; i++){
        tab[i] = new Pawn(color);
        tab[i]->setX(i);
        if(color==WHITE)    tab[i]->setY(6);
        else    tab[i]->setY(1);
    }

    tab[8] = new Rook(color);
    tab[15] = new Rook(color);
    tab[9] = new Knight(color);
    tab[14] = new Knight(color);
    tab[10] = new Bishop(color);
    tab[13] = new Bishop(color);
    tab[11] = new Queen(color);
    tab[12] = new King(color);
    for(int i=8; i<16; i++){
        tab[i]->setX(i-8);
        if(color==WHITE)    tab[i]->setY(7);
        else    tab[i]->setY(0);
    }
    for(int i=0; i<16; i++){
        tab[i]->setChessboard(chessboard);
    }
}
void Player::setChessboard(Chessboard* chessboard){
    this->chessboard = chessboard;
}
void Player::setOpponent(Player* opponent){
    this->opponent = opponent;
}

Piece* Player::getKing(){
    return tab[12];
}
void Player::print(){
//       cout << color;
    for(int i=0; i<8; i++){
        tab[i]->print();
        cout << ' ';
    }
    cout << endl;
    for(int i=8; i<16; i++){
        tab[i]->print();
        cout << ' ';
    }
    cout << endl;
}
void Player::setIsCheck(bool isCheck){
    this->isCheck = isCheck;
}
bool Player::isAnyOneCheck(){

    Piece* k=opponent->getKing();
    int kx=k->getX();
    int ky=k->getY();
    int x2, y2;
    for(int i=0; i<16; i++){
        Piece*p=tab[i];
        x2=p->getX();
        y2=p->getY();
        if(tab[i]->islegal(x2,y2,kx,ky)){
            return true;
        }
    }
    return false;
}
int Player::move(Chessboard &chessboard, char cinx1, int ciny1, char cinx2, int ciny2){
    int x1, y1, x2, y2;
    convert(cinx1, ciny1, x1, y1);
    convert(cinx2, ciny2, x2, y2);
    Piece* p=chessboard.getPiece(x1, y1);
    Piece* p2=chessboard.getPiece(x2, y2);
    Piece* k=getKing();
    int kx=k->getX();
    int ky=k->getY();

//        TODO NIE PRZEDHOWUJEMY WSPAZNIKA DO CHESSBOARDA W KLASIE PIECE
//        nie obslugujemy w funkcji islegal przeskakiwania przez inne figury
//        zamiast tego robimy to w tym miejscu


    if (chessboard.isEmpty(x1, y1)){
        cout << "WYBRANE POLE JEST PUSTE";
        return -1;
    }
    else if (p2!=NULL and p!=NULL and p2->getColor()==p->getColor()){
        cout << "NA TYM POLU ZNAJDUJE SIE INNA BIERKA TEGO SAMEGO GRACZA" << endl;
        return -1;
    }
    else if (chessboard.isEmpty(x2, y2)){
        if (p->getColor()!=color){
            cout << "TA BIERKA NALEZY DO DRUGIEGO GRACZA" << endl;
            return -1;
        }

        //cout << "SUKCESYWNIE ZEBRANO INFORMACJE O FIGURZE" << endl;


//        cout << (p->islegal(x1, y1, x2, y2)) << " " << (p->isInChessboard(x1, y1, x2, y2)) << endl;
        else if(!(p->islegal(x1, y1, x2, y2)) or !(p->isInChessboard(x1, y1, x2, y2))){
           cout << "RUCH WYKONANY NIEPOPRAWNIE" << endl;
           return -1;
           }
        else if(p->getPieceType()!=KNIGHT and chessboard.isBetween(x1, y1, x2, y2)){
                cout << "POMIEDZY POLAMI ZNAJDUJE SIE INNA BIERKA" << endl;
               return -1;
            }
        else{
            chessboard.setPiece(x2, y2, p);
            chessboard.setPiece(x1, y1, NULL);
            if(isAnyOneCheck())
                setIsCheck(true);   //ktorakolwiek z naszych figur szachuje, a nie jestesmy szachowani
        }
    }
    else if (p2->getColor()!=color){        //zbijanie

        if (p->getColor()!=color){
            cout << "TA BIERKA NALEZY DO DRUGIEGO GRACZA" << endl;
            return -1;
        }
        if(!(p->islegal(x1, y1, x2, y2)) or !(p->isInChessboard(x1, y1, x2, y2))){
            cout << "RUCH WYKONANY NIEPOPRAWNIE" << endl;
            return -1;
            }
        else if(p->getPieceType()!=KNIGHT and chessboard.isBetween(x1, y1, x2, y2)){
                cout << "POMIEDZY POLAMI ZNAJDUJE SIE INNA BIERKA" << endl;
                return -1;
            }
        else{
            chessboard.setPiece(x2, y2, p);
            chessboard.setPiece(x1, y1, NULL);
            p2->setTakenDown(true);
        }
    }
    return 0;
}
bool Player::getColor(){
    return color;
}
Piece* Player::getPiece(int i){
    return tab[i];
}

