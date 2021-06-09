#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(void){
    long long ax,ay,bx,by,cx,cy, SS;
    while(cin >> ax >> ay >> bx >> by >> cx >> cy){
        SS = abs(bx * cy + ax * by + cx * ay - cx * by - bx * ay - ax * cy);
        cout << SS * 11 << endl;
    }
    return 0;
}