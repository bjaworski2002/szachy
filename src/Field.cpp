#include "Field.h"
#include <iostream>
class Piece;
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
        std::cout << "ISEMPTY" << std::endl;
        if(p==NULL)
            return true;
        else
            return false;
    }
