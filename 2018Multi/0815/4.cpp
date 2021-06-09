#include<iostream>
#include<cstdio>

using namespace std;
char board[202][202]; 
int h,w;
void printl1(int ish){
    //cout << h<<" "<<w << endl;
    if (ish) {
        
        for (int c=1;c<=w/2;c++) {
            board[1][c]='(';board[h][c]=')';
            for (int r=2;r<=h-1;r++) {
                if (!(r%2))board[r][c]='(';
                else board[r][c]=')';
            }
        }
        for (int c=w/2+1;c<=w;c++) {
            board[1][c]='(';board[h][c]=')';
            for (int r=2;r<=h-1;r++) {
                if (!(r%2))board[r][c]=')';
                else board[r][c]='(';
            }
        }
    } else {

        for (int r=1;r<=h/2;r++) {
            board[r][1]='(';board[r][w]=')';
            for (int c=2;c<=w-1;c++) {
                if (!(c%2))board[r][c]='(';
                else board[r][c]=')';
            }
        }
        for (int r=h/2+1;r<=h;r++) {
            board[r][1]='(';board[r][w]=')';
            for (int c=2;c<=w-1;c++) {
                if (!(c%2))board[r][c]=')';
                else board[r][c]='(';
            }
        }
    }
}

void printl2(int ish) {
    for (int r=1;r<=h;r++) board[r][1]='(',board[r][w]=')';
    for (int c=1;c<=w;c++) board[1][c]='(',board[h][c]=')';
    for (int r=2;r<=h-1;r++) {
        if (r%2==0){
            for (int c=2;c<=w-1;c++) {
                if (c%2==0) board[r][c]=')';
                else board[r][c]='(';
            }
        }else{
            for (int c=2;c<=w-1;c++) {
                if (c%2==0) board[r][c]='(';
                else board[r][c]=')';
            }
        }
    }
}



int main(void) {
    int T;
    scanf("%d",&T);
    while(T--) {
        //int h,w;
        int ish=0;
        int flag1=0,flag2=0;
        scanf("%d%d",&h,&w);
        int s=h<w?h:w;if (s==h) ish=1; 
        int b=h+w-s;
        if (s%2==0) flag1=1;
        if (b%2==0)    flag2=1;
        if (flag1==0) ish=!ish;
        
        if (flag1&&flag2) {
            int res1=b+s/2-1;
            int res2=b-2+s-2;
            if (res1>=res2)printl1(ish);
            else printl2(ish);
        }else printl1(ish);
        
        for (int r=1;r<=h;r++) {
            for (int c=1;c<=w;c++) {
                printf("%c",board[r][c]);
            }
            printf("\n");
        }


    }




}