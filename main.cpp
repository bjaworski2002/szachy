#include <iostream>

using namespace std;

int dodaj(int a, int b){
    return a+b;
}

int podziel(int a, int b){
    return a/b;
}


int main()
{
    int a = 5;
    int b= 10;
    cout <<  dodaj(a,b) <<endl;
    cout << podziel(a,b);

    return 0;
}
