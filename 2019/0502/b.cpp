#include <bits/stdc++.h>
#define pii pair<int,int>
#define LL long long
#define MAXN 100000
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



int T;
int n;

LL a[MAXN + 8];
LL xa, xb, ya, yb;
LL cnt[MAXN + 8];
map<int, map<int, bool>> mp;
int main()
{
    read(T);
    while (T--)
    {
        read(n);
        read(xa);
        read(ya);
        for (int i = 1; i <= n; ++i)
        {
            read(a[i]);
            mp[a[i]][i] = true;
            cnt[a[i]]++;
            xb += i * a[i];
            yb += i * a[i] * a[i];
        }
        if (xb == xa)
        {
            if (yb == ya)
            {
                LL res = 0;
                for (int i = 1; i <= n; ++i)
                {
                    if (cnt[a[i]])
                    {
                        res += cnt[a[i]] * (cnt[a[i]] - 1) / 2;
                        cnt[a[i]] = 0;
                    }
                }
                printf("%lld\n", res);
            }
            else
            {
                printf("0\n");
            }
        }
        else if ((yb - ya) % (xb - xa))
            printf("0\n");
        else
        {
            LL p = (yb - ya) / (xb - xa);
            LL q = xb - xa;
           // printf("p = %I64d  q = %I64d\n", p, q);
            int ans = 0;
            for (int i = 1; i <= n; ++i)
            {
                cnt[a[i]] = 0;
                if (p - 2 * a[i] == 0 || q % (p - 2 * a[i]))
                    continue;
                int j = i + q / (p - 2 * a[i]);
                if (j <= i)
                    continue;
                if (p <= a[i])
                    continue;
                if (mp[p - a[i]][j])
                    ans++;
            }
            printf("%d\n", ans);
        }
        xb = yb = 0;
        mp.clear();
    }
    return 0;
}
