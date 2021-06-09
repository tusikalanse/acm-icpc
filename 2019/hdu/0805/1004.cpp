#include <bits/stdc++.h>
#define MAXN 7000000
#define LL long long
using namespace std;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
LL gcd(LL a, LL b)
{
    a = abs(a), b = abs(b);
    return b?gcd(b,a%b):a;
}
LL lcm(LL a, LL b)
{
    return a/gcd(a,b)*b;
}
struct Fs
{
    LL a, b;
    Fs(){a = 0, b = 1;}
    Fs(LL _a, LL _b)
    {
        a = _a; b = _b;
    }
    void yuefen()
    {
        LL g = gcd(a, b);
        a /= g, b /= g;
    }
    Fs operator+(const LL& d) const
    {
        return Fs(a+b*d, b);
    }
    Fs operator-(const LL& d) const
    {
        return Fs(a-b*d, b);
    }
    Fs operator*(const LL& d) const
    {
        return Fs(d*a, b);
    }
    Fs operator+(const Fs& f) const
    {
        LL l = lcm(b, f.b);
        return Fs(l/b*a+l/f.b*f.a, l);
    }
    Fs operator-(const Fs& f) const
    {
        LL l = lcm(b, f.b);
        return Fs(l/b*a-l/f.b*f.a, l);
    }
    Fs operator*(const Fs& f) const
    {
        return Fs(a*f.a, b*f.b);
    }
    bool operator==(const Fs& f) const
    {
        return a*f.b==b*f.a;
    }
    bool operator!=(const Fs& f) const
    {
        return a*f.b!=b*f.a;
    }
    bool operator<(const Fs& f) const
    {
        if (*this != f)
            return 1.0*a/b<1.0*f.a/f.b;
        else
            return false;
    }
    bool operator<=(const Fs& f) const
    {
        if (*this != f)
            return 1.0*a/b<=1.0*f.a/f.b;
        else
            return true;
    }
};

struct Line
{
    LL a, b;
    Line(){}
    Line(LL _a, LL _b)
    {
        a = _a; b = _b;
    }
    Fs crossy(LL y)
    {
        return Fs(y - b, a);
    }
};

LL n, C;
Line arr[100008];
Fs crx[100008];
LL suma[100008], sumb[100008];
vector<Line> vec;
vector<Fs> ans;
vector<Fs> fans;
bool cmp(Line x, Line y)
{
    return x.crossy(0) < y.crossy(0);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        vec.clear();
        ans.clear();
        fans.clear();
        scanf("%lld %lld", &n, &C);
        for (int i = 1; i <= n; ++i)
        {
            LL t, tt;
            scanf("%lld %lld", &t, &tt);
            arr[i] = Line(t, tt);
        }
        sort(arr + 1, arr + n + 1, cmp);
        for (int i = 1; i <= n; ++i)
            crx[i] = arr[i].crossy(0);
        crx[0] = Fs(-INF, 1);
        crx[n + 1] = Fs(INF, 1);
        for (int i = 1; i <= n; ++i)
        {
            suma[i] = arr[i].a + suma[i - 1];
            sumb[i] = arr[i].b + sumb[i - 1];
        }
        for (int i = 0; i <= n; ++i)
            vec.push_back(Line(2 * suma[i] - suma[n], 2 * sumb[i] - sumb[n]));   //vec[i].l = crx[i] ~ crx[i + 1];
        bool infflag = false;
        for (int i = 0; i <= n; ++i)
        {
            if (vec[i].a == 0 && vec[i].b == C)
            {
                infflag = true;
                break;
            }
            else if (vec[i].a == 0)
            {
                continue;
            }
            Fs f = vec[i].crossy(C);
            f.yuefen();
            if (crx[i] <= f && f <= crx[i + 1])
                ans.push_back(f);
        }
        for (int i = 0; i < (int)ans.size(); ++i)
        {
            int j;
            for (j = i + 1; j < (int)ans.size(); ++j)
            {
                if (ans[i] == ans[j])
                    break;
            }
            if (j >= (int)ans.size())
            {
                fans.push_back(ans[i]);
            }
        }
        if (infflag)
            printf("-1\n");
        else
        {
            printf("%d ", (int)fans.size());
            for (auto f: fans)
            {
                if (f.b < 0)
                {
                    f.a = -f.a;
                    f.b = -f.b;
                }
                f.yuefen();
                printf("%lld/%lld ", f.a, f.b);
            }
            printf("\n");
        }
    }
    return 0;
}