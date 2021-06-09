#include<bits/stdc++.h>
using namespace std;


namespace fastIO{    
    #define BUF_SIZE 100000    
    #define OUT_SIZE 100000    
    #define ll long long    
    //fread->read    
    bool IOerror=0;    
    inline char nc(){    
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;    
        if (p1==pend){    
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);    
        if (pend==p1){IOerror=1;exit(0);return -1;}    
        //{printf("IO error!\n");system("pause");for (;;);exit(0);}    
    }    
    return *p1++;    
}    
inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}    
inline void read(int &x){    
    bool sign=0; char ch=nc(); x=0;    
    for (;blank(ch);ch=nc());    
    if (IOerror)return;    
    if (ch=='-')sign=1,ch=nc();    
    for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';    
    if (sign)x=-x;    
}    
inline void read(ll &x){    
    bool sign=0; char ch=nc(); x=0;    
    for (;blank(ch);ch=nc());    
    if (IOerror)return;    
    if (ch=='-')sign=1,ch=nc();    
    for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';    
    if (sign)x=-x;    
}    
inline void read(double &x){    
    bool sign=0; char ch=nc(); x=0;    
    for (;blank(ch);ch=nc());    
    if (IOerror)return;    
    if (ch=='-')sign=1,ch=nc();    
    for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';    
    if (ch=='.'){    
        double tmp=1; ch=nc();    
        for (;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0');    
    }    
    if (sign)x=-x;    
}    
inline void read(char *s){    
    char ch=nc();    
    for (;blank(ch);ch=nc());    
    if (IOerror)return;    
    for (;!blank(ch)&&!IOerror;ch=nc())*s++=ch;    
    *s=0;    
}    
inline void read(char &c){    
    for (c=nc();blank(c);c=nc());    
    if (IOerror){c=-1;return;}    
}   
#undef OUT_SIZE    
#undef BUF_SIZE    
}; using namespace fastIO;  

long long n,L,mid,topa,topb,ans,T;
int a[2000005],b[2000005],rd[1000005];
bool check(){
    topb=0;int i,j;
    for(i=1;i<=n;i++)if(rd[i]>=mid)    b[++topb]=rd[i];
    for(i=1;i<=n;i++)if(rd[i]<L-mid)b[++topb]=rd[i]+L;
    for(i=1,j=1;i<=topb;i++,j++){
        for(;j<=topa&&abs(a[j]-b[i])>mid;j++);
        if(j>topa)break;
    }
    return i>topb;
}
int main(){
    read(T);
    while(T--) {
        read(n),topa=n<<1,read(L);
        for(int i=1;i<=n;i++)read(a[i]);
        for(int i=1;i<=n;i++)read(rd[i]);
        sort(a+1,a+1+n);sort(rd+1,rd+1+n);
        for(int i=1;i<=n;i++)a[i+n]=a[i]+L;
        for(long long l=0,r= n * L;l<=r;){
            mid=(l+r)>>1;
            check()?ans=mid,r=mid-1:l=mid+1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}