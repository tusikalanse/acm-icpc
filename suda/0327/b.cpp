#include <cstdio>
#define max(a,b) a > b ? a : b
using namespace std;

long long l[105];

int main() {
    long long n, m, t, a, b;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld %lld", &n, &m);
        for(long long i = 1; i<=n; i++)
            scanf("%lld", &l[i]);
        while(m--){
            scanf("%lld %lld", &a, &b);
            if(a==0)
                continue;
            if(a > 0)
                l[b] *= 2;
            else
                l[b] += 2;
        }
        long long ans = l[1];
        for(long long i = 2; i<= n; i++)
            ans = max(ans, l[b]);
        printf("%lld\n", ans);
    }


    return 0;
}
