#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
double w,H,a,b,c,a0,b0,c0;
double XA,YA,XB,YB,XC,YC;
double x,sinx,cosx,p,h,h2;
double Xx,Yx,Xy,Yy,Xz,Yz;
bool eps(double x,double y){
    return (abs(x-y)<=1e-3);
}
void check(){
    double ab=sqrt((XA-XB)*(XA-XB)+(YA-YB)*(YA-YB)) ; double ac=sqrt((XA-XC)*(XA-XC)+(YA-YC)*(YA-YC)); double cb=sqrt((XC-XB)*(XC-XB)+(YC-YB)*(YC-YB));
    if (eps(ab,a0)){
        Xz=XC;Yz=YC;
        if (eps(ac,b0)){
            Xy=XB;Yy=YB;
            Xx=XA;Yx=YA;
        }else{
            Xy=XA;Yy=YA;
            Xx=XB;Yx=YB;
        }
    }else if (eps(ab,b0)){
        Xy=XC;Yy=YC;
        if (eps(ac,a0)){
            Xz=XB;Yz=YB;
            Xx=XA;Yx=YA;
        }else{
            Xz=XA;Yz=YA;
            Xx=XB;Yx=YB;
        }
    }else{
        Xx=XC;Yx=YC;
        if (eps(ac,a0)){
            Xz=XB;Yz=YB;
            Xy=XA;Yy=YA;
        }else{
            Xz=XA;Yz=YA;
            Xy=XB;Yy=YB;
        }
    }
    //cout << "check:->"<<sqrt((Xx-Xy)*(Xx-Xy)+(Yx-Yy)*(Yx-Yy)) << " " << sqrt((Xx-Xz)*(Xx-Xz)+(Yx-Yz)*(Yx-Yz)) << " " <<sqrt((Xy-Xz)*(Xy-Xz)+(Yy-Yz)*(Yy-Yz)) << endl;
}
bool judge(){
    bool res= (0<=XC)&&(XC<=w)&&(0<=YC)&&(YC<=H);
 
    return res;
}
void calc(){
    XB=YB=0;
    if (c<=w) XA=c,YA=0;
    else XA=w,YA=sqrt(c*c-w*w);
    x=sqrt(a*a-h*h);
    sinx=YA/c;
    cosx=XA/c;
    XC=x*cosx - h*sinx;
    YC=x*sinx + h*cosx;
}
 
 
int main(void){
    int T;cin >> T;
    while (T--){
        cin >> w >>H >>a >>b >> c;
        a0=a,b0=b,c0=c;
        if (a>c) swap(a,c);
        if (b>c) swap(b,c);
        if (a>b) swap(a,b);
        // --- 1
        p=(a+b+c)/2;
        h2=4*(p*(p-a)*(p-b)*(p-c))/c/c;h=sqrt(p*(p-a)*(p-b)*(p-c))*2/c;
        calc();
        if (judge()){
            check();
            printf("%.15f %.15f %.15f %.15f %.15f %.15f\n",Xx,Yx,Xy,Yy,Xz,Yz);
            continue;
        }
        swap(a,b);
        calc();
        if (judge()){
            check();
            printf("%.15f %.15f %.15f %.15f %.15f %.15f\n",Xx,Yx,Xy,Yy,Xz,Yz);
            continue;
        }
        swap(w,H);
        calc();
        if (judge()){
            swap(XA,YA);swap(XB,YB);swap(XC,YC);
            check();
            printf("%.15f %.15f %.15f %.15f %.15f %.15f\n",Xx,Yx,Xy,Yy,Xz,Yz);
            continue;
        }
        swap(a,b);
        calc();
        if (judge()){
            swap(XA,YA);swap(XB,YB);swap(XC,YC);
            check();
            printf("%.15f %.15f %.15f %.15f %.15f %.15f\n",Xx,Yx,Xy,Yy,Xz,Yz);
            continue;
        }
     
 
    }
}