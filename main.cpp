#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;

enum Color{WHITE, BLACK};
enum PieceType{KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN};
class Piece;
class Chessboard;
class Field;
class Player;
class King;

void convert(char cinx1, int ciny1, int &x1, int &y1){
    x1 = cinx1 - 'a';
    y1 = 8 - ciny1;
}

class Piece{
protected:
    bool takendown;
    Color color;
    PieceType pieceType;
    Chessboard* chessboard;
    int x;
    int y;
public:
    Piece(Color color);
    virtual bool islegal(int x1, int y1, int x2, int y2){};
    bool isInChessboard(int x1, int y1, int x2, int y2);
    Color getColor();
    PieceType getPieceType();
    void setChessboard(Chessboard* chessboard);
    void print();
    void setTakenDown(bool takendown);
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();


};

class Player{
    Color color;
    Piece *tab[16];
    Chessboard* chessboard;
    bool isCheck;
    Player* opponent;
public:
    Player(Color color);
    void print();
    int move(Chessboard& chessboard, char cinx1, int ciny1, char cinx2, int ciny2);
    bool getColor();
    Piece* getPiece(int i);
    void setChessboard(Chessboard* chessboard);
    void setIsCheck(bool isCheck);
    void setOpponent(Player* opponent);
    Piece* getKing();
    bool isAnyOneCheck();
};

class Pawn : public Piece{
    public:
    Pawn(Color color);
    bool islegal(int x1, int y1, int x2, int y2);
};
class Rook : public Piece{
public:
    Rook(Color color);
    bool islegal(int x1, int y1, int x2, int y2);
};
class Knight : public Piece{

public:
    Knight(Color color);
    bool islegal(int x1, int y1, int x2, int y2);
};
class Bishop : public Piece{

public:
    Bishop(Color color);
    bool islegal(int x1, int y1, int x2, int y2);
};
class Queen : public Piece{

public:
    Queen(Color color);
    bool islegal(int x1, int y1, int x2, int y2);

};
class King : public Piece{

public:
    King(Color color);
    bool islegal(int x1, int y1, int x2, int y2);
};
class Field{
    int x;
    int y;
    Piece*p;
public:
    Field();
    void setPiece(Piece * piece);
    void print();
    Piece* getPiece();
    bool isEmpty();
    bool isEmpty2();
};
class Chessboard{
    Field board[8][8];
public:
    void setPieces(Player* player);
    bool isEmpty(int x, int y);
    bool isEmpty2(int x, int y);
    bool isFieldOccupiedByOponent(int x, int y, Color color);
    bool isBetween(int x1, int y1, int x2, int y2);
    Piece* getPiece(int x, int y);
    void setPiece(int x, int y, Piece* p);
    void print();

};
struct movestr{
    char x1;
    int y1;
    char x2;
    int y2;
};

movestr getMove(Color color, Chessboard& chessboard, string output){

    movestr move1;
    int isWhite;
    int y2 = output.at(output.length()-1)-'0';
    char x2 = output.at(output.length()-2);
    int cx2, cy2;
    color==WHITE ? isWhite=1 : isWhite=-1;
    if(output=="O-O-O" and color==WHITE){
        move1.x2='c';
        move1.y2=1;
        move1.x1='e';
        move1.y1=1;

    }
    else if(output=="O-O" and color==WHITE){
        move1.x2='g';
        move1.y2=1;
        move1.x1='e';
        move1.y1=1;
    }
    else if(output=="O-O-O" and color==WHITE){
        move1.x2='c';
        move1.y2=8;
        move1.x1='e';
        move1.y1=8;
    }
    else if(output=="O-O" and color==WHITE){
        move1.x2='g';
        move1.y2=8;
        move1.x1='e';
        move1.y1=8;
    }                                                          //roszady
    else{
        if(output.at(0) >='A' and output.at(0) <='Z'){
            output=output.substr(1,(output.length())-1);
//            cout << output << endl;
        }                                                      //Skracanie notacji do pol
        else{
            if(output.at(1)!='x' && output.at(1)=='4'+color){  //Ruch pionkiem o dwa miejsca
                convert(x2, y2, cx2, cy2);
                cout << "CX2= "<< cx2 << " " << cy2<< endl;
                if(chessboard.isEmpty(cx2, cy2+(1*isWhite))){
                    cout << "ISEMPTY" << endl;
                    move1.x1=output.at(0);
                    move1.y1=output.at(1)-'0'-(2*isWhite);
                    move1.x2=x2;
                    move1.y2=y2;
                    cout << move1.x1 << move1.x2 << move1.y1 << move1.y2 << endl;
                }
                else{
                    move1.x1=output.at(0);
                    move1.y1=output.at(1)-'0'-(1*isWhite);
                    move1.x2=x2;
                    move1.y2=y2;
                }
            }                                                    //Ruch pionkiem o jedno miejsce
            else if(output.at(1)!='x'){
                move1.x1=output.at(0);
                move1.y1=output.at(1)-'0'-1*isWhite;
                move1.x2=x2;
                move1.y2=y2;
            }
            else{
                move1.x1=output.at(0);
                move1.y1=output.at(3)-'0'-1*isWhite;
                move1.x2=x2;
                move1.y2=y2;
            }

        }
    }
//        move1.x2=output.at(0);
//        move1.y2=output.at(1) - '0';
//        move1.x1='a';
//        move1.y1=1;
//    }
//    moves.push_back(move1);
    return move1;
}
movestr Symulator(Chessboard& chessboard, Player& playerWhite, Player& playerBlack){
//    vector<movestr> moves;
    ifstream notacja;
    movestr move1;
    notacja.open("partia1.pgn");



    string output="";
    if (notacja.is_open())
    {
        cout << output;

//         cout << "asdasdas" <<endl;
        while (output!="1/2-1/2")
        {
            notacja >> output;
            if(output=="1/2-1/2"){

//                cout << "sdfsfsdfsdf "<< endl;
                break;
            }

                //TODO - poprawic blad

                size_t found = output.find(".");
    //            cout << " poz=" << found << endl;
                output=output.substr(found+1, (output.length() - found) ); //Plik nie moze miec spacji miedzy kropka a ruchem
                cout << output << ' ';
                move1 = getMove(WHITE, chessboard, output);
                playerWhite.move(chessboard, move1.x1, move1.y1, move1.x2, move1.y2);
                chessboard.print();

                notacja >> output;
                if(output=="1/2-1/2"){
                    break;
                }
                cout << " ";
                cout<<output << endl;
                move1 = getMove(BLACK, chessboard, output);
                playerBlack.move(chessboard, move1.x1, move1.y1, move1.x2, move1.y2);
                chessboard.print();
//                movestr move1;

        }
        notacja.close();
    }
    else{
        cout << "blad odczytu!" << endl;
    }

}

int main()
{
    Player playerWhite(WHITE);
    Player playerBlack(BLACK);
    Chessboard chessboard;
    playerWhite.setChessboard(&chessboard);
    playerBlack.setChessboard(&chessboard);
    chessboard.setPieces(&playerWhite);
    chessboard.setPieces(&playerBlack);
    playerWhite.setOpponent(&playerBlack);
    playerBlack.setOpponent(&playerWhite);
    chessboard.print();
    char cinx1, cinx2;
    int ciny1, ciny2;


    Symulator(chessboard, playerWhite, playerBlack);


//    cout << "Zakonczono symulator" << endl;
//    while(true){
//        cin >> cinx1 >> ciny1 >> cinx2 >> ciny2;
//        cout << "  ";
//        while(playerWhite.move(chessboard, cinx1, ciny1, cinx2, ciny2)==-1){
//            cin >> cinx1 >> ciny1 >> cinx2 >> ciny2;
//        }
//        for(int i=0; i<8; i++){
//            cout << " " <<i;
//        }
//        cout << endl;
//        chessboard.print();
//
//
//
//        cin >> cinx1 >> ciny1 >> cinx2 >> ciny2;
//        while(playerBlack.move(chessboard, cinx1, ciny1, cinx2, ciny2)==-1){
//            cin >> cinx1 >> ciny1 >> cinx2 >> ciny2;
//        }
//        chessboard.print();
//    }

}









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

    Rook::Rook(Color color) : Piece(color){
        pieceType = ROOK;
    }
    bool Rook::islegal(int x1, int y1, int x2, int y2){
        return ((x2==x1) or (y2==y1));
    }

        Knight::Knight(Color color) : Piece(color){
        pieceType = KNIGHT;
    }
    bool Knight::islegal(int x1, int y1, int x2, int y2){
        return ((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))==5;
    }
    Bishop::Bishop(Color color) : Piece(color){
        pieceType = BISHOP;
    }
    bool Bishop::islegal(int x1, int y1, int x2, int y2){
        return (x2+y2 == x1+y1 or x2-y2 == x1-y1);
    }
    Queen::Queen(Color color) : Piece(color){
        pieceType = QUEEN;
    }
    bool Queen::islegal(int x1, int y1, int x2, int y2){
        return(((x2==x1) or (y2==y1)) or (x2+y2 == x1+y1 or x2-y2 == x1-y1));
    }
    King::King(Color color) : Piece(color){
        pieceType = KING;
    }
    bool King::islegal(int x1, int y1, int x2, int y2){
        return(abs(x2-x1)<=1 && abs(y2-y1)<=1);
    }





    Field::Field(){
        p=NULL;
    }
    void Field::setPiece(Piece * piece){
        p = piece;
    }
    void Field::print(){
        p->print();
    }
    Piece* Field::getPiece(){
        return p;
    }
    bool Field::isEmpty(){
        if(p==NULL)
            return true;
        else
            return false;
    }
    bool Field::isEmpty2(){
        cout << "ISEMPTY" << endl;
        if(p==NULL)
            return true;
        else
            return false;
    }







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
