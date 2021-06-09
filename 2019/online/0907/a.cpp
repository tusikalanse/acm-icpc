#include <bits/stdc++.h>
#define LL long long
#define MAXN 1000000
using namespace std;
vector<LL> vec;
int k;
LL n;

LL exgcd(LL a, LL b, LL &p, LL &q)
{
    if (a == 0 && b == 0) return -1;
    if (b == 0)
    {
        p = 1; q = 0; return a;
    }
    LL d = exgcd(b, a % b, q, p);
    q -= a / b * p;
    return d;
}

LL m[12], a[12];
bool crt()
{
    LL lcm = m[1], ret = a[1], flag = 0;
    for (int i = 2; i <= k; ++i)
    {
        LL x, y;
        a[i] = ((a[i] - ret) % m[i] + m[i]) % m[i];
        LL d = exgcd(lcm, m[i], x, y);
        if(a[i] % d == 0)
        {
            x = x * (a[i] / d) % m[i];
        }
        else
            return false;
        ret += x * lcm;
        lcm = lcm / d * m[i];
        ret = (ret % lcm + lcm) % lcm;
    }
    n = ret;
    if (n <= 0)
        n += lcm;
    return true;
}

bool in(LL n)
{
    for (auto x: vec)
        if (n == x)
            return true;
    return false;
}

int main()
{
    cin >> k;
    LL p = 0, q = 1;
    vec.push_back(p);
    vec.push_back(q);
    while (q <= 1e15)
    {
        LL t = q;
        q = p + q;
        if (q <= 1e15)
            vec.push_back(q);
        p = t;
    }
    for(auto f: vec)
        cout << f << " ";
    cout << endl;
    cin >> m[1] >> a[1];
    for (int i = 2; i <= k; ++i)
    {
        cin >> m[i] >> a[i];
    }
    if (!crt() || n > 1e15)
        printf("Tankernb!\n");
    else
    {
        if (in(n))
            printf("Lbnb!\n");
        else
            printf("Zgxnb!\n");
    }
    return 0;
}