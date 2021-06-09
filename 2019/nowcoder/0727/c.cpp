#include <bits/stdc++.h>
#define LL long long
#define MAXN 3000000
 
using namespace std;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int n;
LL arr[MAXN + 4];
LL brr[MAXN + 4];
int l[MAXN + 4], r[MAXN + 4];
LL presum[MAXN + 4];
LL sufsum[MAXN + 4];
 
LL premx[(MAXN << 2) + 4], sufmx[(MAXN << 2) + 4], premn[(MAXN << 2) + 4], sufmn[(MAXN << 2) + 4];
 
void pushupmx(LL tre[], int rt)
{
    tre[rt] = max(tre[rt << 1], tre[rt << 1 | 1]);
}
 
void buildmx(LL tre[], LL src[], int rt, int l, int r)
{
    if (l >= r)
    {
        tre[rt] = src[l];
        return;
    }
    int mid = (l + r) >> 1;
    buildmx(tre, src, rt << 1, l, mid);
    buildmx(tre, src, rt << 1 | 1, mid + 1, r);
    pushupmx(tre, rt);
}
 
LL querymx(LL tre[], int rt, int l, int r, int L, int R)
{
    if (l > r)
        return -INF;
    if (L <= l && r <= R)
    {
        return tre[rt];
    }
    int mid = (l + r) >> 1;
    LL ret = -INF;
    if (L <= mid)
        ret = max(ret, querymx(tre, rt << 1, l, mid, L, R));
    if (mid + 1 <= R)
        ret = max(ret, querymx(tre, rt << 1 | 1, mid + 1, r, L, R));
    return ret;
}
 
void pushupmn(LL tre[], int rt)
{
    tre[rt] = min(tre[rt << 1], tre[rt << 1 | 1]);
}
 
void buildmn(LL tre[], LL src[], int rt, int l, int r)
{
    if (l >= r)
    {
        tre[rt] = src[l];
        return;
    }
    int mid = (l + r) >> 1;
    buildmn(tre, src, rt << 1, l, mid);
    buildmn(tre, src, rt << 1 | 1, mid + 1, r);
    pushupmn(tre, rt);
}
 
LL querymn(LL tre[], int rt, int l, int r, int L, int R)
{
    if (l > r)
        return INF;
    if (L <= l && r <= R)
    {
        return tre[rt];
    }
    int mid = (l + r) >> 1;
    LL ret = INF;
    if (L <= mid)
        ret = min(ret, querymn(tre, rt << 1, l, mid, L, R));
    if (mid + 1 <= R)
        ret = min(ret, querymn(tre, rt << 1 | 1, mid + 1, r, L, R));
    return ret;
}
stack<int> sta;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &arr[i]);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &brr[i]);
        presum[i] = presum[i - 1] + brr[i];
    }
    for (int i = n; i >= 1; --i)
        sufsum[i] = sufsum[i + 1] + brr[i];
    arr[0] = -INF;
    sta.push(0);
    for (int i = 1; i <= n; ++i)
    {
        while (arr[sta.top()] >= arr[i])
        {
            sta.pop();
        }
        l[i] = sta.top() + 1;
        sta.push(i);
    }
    while (!sta.empty())
        sta.pop();
    arr[n + 1] = -INF;
    sta.push(n + 1);
    for (int i = n; i >= 1; --i)
    {
        while (arr[sta.top()] >= arr[i])
        {
            sta.pop();
        }
        r[i] = sta.top() - 1;
        sta.push(i);
    }
    buildmx(premx, presum, 1, 1, n);
    buildmn(premn, presum, 1, 1, n);
    buildmx(sufmx, sufsum, 1, 1, n);
    buildmn(sufmn, sufsum, 1, 1, n);
    LL ans = -INF;
    for (int i = 1; i <= n; ++i)
    {
        if (arr[i] >= 0)
        {
            ans = max(ans, (querymx(sufmx, 1, 1, n, l[i], i) + querymx(premx, 1, 1, n, i, r[i]) - sufsum[i] - presum[i] + brr[i]) * arr[i]);
        }
        else
        {
            ans = max(ans, (querymn(sufmn, 1, 1, n, l[i], i) + querymn(premn, 1, 1, n, i, r[i]) - sufsum[i] - presum[i] + brr[i]) * arr[i]);
        }
    }
    printf("%lld\n", ans);
}