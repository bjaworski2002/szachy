#ifndef PLAYER_H
#define PLAYER_H
#include "Chessboard.h"
#include "Piece.h"
class Chessboard;
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

#endif // PLAYER_H
