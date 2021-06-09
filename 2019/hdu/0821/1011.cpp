#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int T, a[N], n, k, l[N], r[N], isl[N], isr[N];
int stk[N], top;
int cnt[N];
long long ans;

long long calc(long long v, long long L, long long R) {
    if(v <= 1)
        return (L + 1) * (R + 1);
    if(L + R + 1 < v) return 0;
    v--;
    long long l1 = max(v - R, 0LL), l2 = L;
    long long l3 = min(v, l2);
    return (l3 + l1) * (l3 - l1 + 1) / 2 + (l3 - l1 + 1) * (R - v + 1) + max(0LL, l2 - v) * (R + 1);
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &k);
        ans = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]); cnt[a[i]] = 0;
        }
        top = 0;
        a[0] = a[n + 1] = 1e9;
        stk[top++] = 0;
        for(int i = 1, j = 0; i <= n; ++i) {
            while(a[stk[top - 1]] < a[i]) top--;
            l[i] = stk[top - 1] + 1;
            stk[top++] = i;
            while(j < n && cnt[a[j + 1]] == 0) cnt[a[++j]]++;
        	isl[i] = j;
        	cnt[a[i]]--;
        }
        for(int i = 1; i <= n; ++i) cnt[a[i]] = 0;
        top = 0;
        stk[top++] = n + 1;
        for(int i = n, j = n + 1; i >= 1; --i) {
            while(a[stk[top - 1]] < a[i]) top--;
            r[i] = stk[top - 1] - 1;
            stk[top++] = i;
            while(j > 1 && cnt[a[j - 1]] == 0) cnt[a[--j]]++;
            isr[i] = j;
            cnt[a[i]]--;
        }
        for(int i = 1; i <= n; ++i) {
            int len = a[i] - k;
            l[i] = max(l[i], isr[i]);
            r[i] = min(r[i], isl[i]);
            if(l[i] + r[i] > i * 2) {
            	int le = l[i], ri = min(r[i], isl[le]), pre = ri;
            	ans += calc(len, i - le, ri - i);
            	for(le++; le <= i; ++le) {
            		ri = min(r[i], isl[le]);
            		ans += calc(len, i - le, ri - i);
            		ans -= calc(len, i - le, pre - i);
            		pre = ri;
            	}
            }
            else {
            	int ri = r[i], le = max(l[i], isr[ri]), pre = le;
            	ans += calc(len, i - le, ri - i);
            	for(ri--; ri >= i; --ri) {
            		le = max(l[i], isr[ri]);
            		ans += calc(len, i - le, ri - i);
            		ans -= calc(len, i - pre, ri - i);
            		pre = le;
            	} 
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}