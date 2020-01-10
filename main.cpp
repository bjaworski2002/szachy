#include <iostream>

using namespace std;

int dodaj(int a, int b){
    return a+b;
}
int odejmij (int a, int b){
    return a-b;
}

int main()
{
    int a = 5;
    int b= 10;
    cout<<  dodaj(a,b);
    cout << endl << odejmij (a,b);
    return 0;
}
