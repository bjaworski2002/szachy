#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include "Piece.h"
#include "Chessboard.h"
#include "Player.h"
#include "Constans.h"
using namespace std;


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
                    move1.x1=output.at(0);                      //'d'
                    move1.y1=output.at(1)-'0'-(2*isWhite);
                    move1.x2=x2;                             //'d'
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
//        cout << output;

//         cout << "asdasdas" <<endl;
        while (output!="1/2-1/2")
        {
            notacja >> output;
            cout << "Numer ruchu " << output << endl;
            notacja >> output;


            if(output=="1/2-1/2"){

//                cout << "sdfsfsdfsdf "<< endl;
                break;
            }

                //TODO - poprawic blad
//
//                size_t found = output.find(".");
//                cout << " poz=" << found << endl;
//                for (int i=0; i<found; i++){
//                    cout << output[i];
//                }
//                cout << endl;
//
//                output=output.substr(found+1, (output.length() - found) ); //Plik nie moze miec spacji miedzy kropka a ruchem
//                cout << "Output= " << output << ' ';




                move1 = getMove(WHITE, chessboard, output);
                cout << "Przed move1" << endl;
                playerWhite.move(chessboard, move1.x1, move1.y1, move1.x2, move1.y2);
                cout << "Po move1" << endl;
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




