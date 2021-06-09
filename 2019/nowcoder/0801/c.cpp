#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL x0, a, b, mod, n, sz;
 
LL qp(LL a, LL b, LL p = mod)
{
    LL ret = 1;
    while (b)
    {
        if (b & 1)
            ret = ret * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ret;
}
 
LL inv(LL a)
{
    return qp(a, mod - 2, mod);
}
vector<pair<LL,LL>> vec;
LL bsgs(LL x,LL y,LL p)
{
    x%=p;y%=p;
    if(!x&&!y) return 1;
    if(y==1) return 0;
    if(!x) return -1;
    LL m=sz;
    LL tmp=qp(x,m,p);
    LL o=tmp;
    LL invy = inv(y);
    for(int i=1;i*sz<=p;++i,o=o*tmp%p)
    {
        int x = lower_bound(vec.begin(), vec.end(), make_pair(invy*o%p, 0LL)) - vec.begin();
        if (x < (int)vec.size() && vec[x].first == invy*o%p)
            return ((i*m-vec[x].second)%p+p)%p;
    }
    return -1;
}
 
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld %lld %lld %lld %lld", &n, &x0, &a, &b, &mod);
        vec.clear();
 
        int Q;
        scanf("%d", &Q);
        sz = sqrt(mod * Q + 0.5);
        //cout << "SZ = " << sz << endl;
        sz = min(sz, mod);
        LL o = 1;
        for (int i = 0; i <= sz; ++i,o=o*a%mod)
            vec.push_back(make_pair(o, i));
        sort(vec.begin(), vec.end());
        while (Q--)
        {
            LL v;
            scanf("%lld", &v);
            if (a == 0)
            {
                if (v == x0)
                    printf("0\n");
                else if (v == b)
                    printf("1\n");
                else
                    printf("-1\n");
            }
            else if (a == 1)
            {
                if (v == x0)
                    printf("0\n");
                else
                {
                    if (b == 0)
                    {
                        printf("-1\n");
                    }
                    else
                    {
                        LL ans = (v - x0 + mod) % mod * inv(b) % mod;
                        if (ans >= n)
                            ans = -1;
                        printf("%lld\n", ans);
                    }
                }
            }
            else // a >= 2
            {
                LL inva1 = inv(a - 1);
                LL y0 = (x0 + b * inva1 % mod) % mod;
                LL u = (v + b * inva1 % mod) % mod;
                LL Y = u * inv(y0) % mod;
                LL X = a;
                LL ans = bsgs(X, Y, mod);
                if (ans >= n)
                    ans = -1;
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}
