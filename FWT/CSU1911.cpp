#include <bits/stdc++.h>
using namespace std;

const int N = 10 + (1 << 18);

int n, m, T, tot, q, cas;
long long a[N], b[N];
long long x;


void FWT(long long a[],int n) {  
    for(int d=1;d<n;d<<=1)  
        for(int m=d<<1,i=0;i<n;i+=m)  
            for(int j=0;j<d;j++) {  
                long long x=a[i+j],y=a[i+j+d];  
                a[i+j+d]=(x+y);  
                //xor:a[i+j]=x+y,a[i+j+d]=(x-y);  
                //and:a[i+j]=x+y;  
                //or:a[i+j+d]=x+y;  
            }  
}  

void IFWT(long long a[],int n)   {  
    for(int d=1;d<n;d<<=1)  
        for(int m=d<<1,i=0;i<n;i+=m)  
            for(int j=0;j<d;j++) {  
                long long x=a[i+j],y=a[i+j+d];  
                a[i+j+d]=y-x; 
                //rev表示2在模mod下的逆元 
                //xor:a[i+j]=(x+y)/2,a[i+j+d]=(x-y)/2;  
                //and:a[i+j]=x-y;  
                //or:a[i+j+d]=y-x;  
            }  
} 

void solve(long long a[],long long b[],int n) {  
    FWT(a,n);  
    FWT(b,n);  
    for(int i=0;i<n;i++) a[i]=a[i]*b[i];  
    IFWT(a,n);  
}  

int calc(long long val) {
    int res = 0;
    for(int i = 0; i < m; ++i) {
        res += (val % 10) << i;
        val /= 10;
    }
    return res;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        tot = 1 << m;
        memset(a, 0, sizeof(long long) * (tot + 10));
        memset(b, 0, sizeof(long long) * (tot + 10));
        for(int i = 1; i <= n; ++i) {
            scanf("%lld", &x);
            a[calc(x)]++;
        }
        for(int i = 1; i <= n; ++i) {
            scanf("%lld", &x);
            b[calc(x)]++;
        }
        solve(a, b, tot);
        scanf("%d", &q);
        printf("Case #%d:\n", ++cas);
        while(q--) {
            scanf("%lld", &x);
            printf("%lld\n", a[calc(x)]);
        }
    }
    return 0;
}