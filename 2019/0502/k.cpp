#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;
char s[N], t[N];
int n, T, l, r;
long long ans;
char ss[N << 1], tt[N << 1];

long long Manacher() {
	ans = 0;
	int cnt = 0, tnt = 0;
	ss[cnt++] = '$';
	ss[cnt++] = '#';
	tt[tnt++] = '$';
	tt[tnt++] = '#';
	for(int i = 0; i < n; ++i) {
		ss[cnt++] = s[i];
		ss[cnt++] = '#';
		tt[tnt++] = t[i];
		tt[tnt++] = '#';
	}
	ss[cnt] = tt[tnt] = 0;
	l = tnt;
	r = -1;
	for(int i = 0; i < tnt; ++i) {
		if(ss[i] != tt[i]) {
			l = min(l, i);
			r = max(r, i);
		}
	}
	vector<int> p(cnt, 0);
	int mx = 0, id = 0, reslen = 0, resid = 0;
	for(int i = 0; i < tnt; ++i) {
		p[i] = mx > i ? min(p[2 * id - i], mx - i) : 0;
		while(ss[i + p[i]] == tt[i - p[i]] && ss[i - p[i]] == tt[i + p[i]])
			++p[i];
		if(mx < i + p[i]) {
			mx = i + p[i];
			id = i;
		}
		if(reslen < p[i]) {
			reslen = p[i];
			resid = i;
		}
		if(l == tnt && r == -1) {
			if(p[i])
				ans += p[i] / 2;
		}
		else {
			if(i - p[i] <= l && i + p[i] >= r && p[i]) {
				ans += min((i + p[i] - r + 1) / 2, (l - i + p[i] + 1) / 2);
			}
		}
	}
	return ans;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%s%s", s, t);
		n = strlen(s);
		printf("%lld\n", Manacher());
	}
	return 0;
}