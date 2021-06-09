#include <bits/stdc++.h>
#define LL long long
using namespace std;

const LL N = 1e6 + 10;

char s[N];
LL nxt[N], n, k;

void getnext() {
	memset(nxt, 0, sizeof(nxt));
	nxt[0] = -1;
	LL j = 0, k = -1;
	while(j < n) {
		if(k == -1 || s[j] == s[k])
			nxt[++j] = ++k;
		else
			k = nxt[k];
	}
}

bool judge(LL i) {
	LL l = i - nxt[i];
	if(i % (l * k) == 0) return true;
	LL res = i - i / (l * k) * (l * k);
	return res <= (i - res) / k;
}

int main() {
	scanf("%lld%lld%s", &n, &k, s);
	getnext();
	for(int i = 1; i <= n; ++i)
		printf("%d", judge(i));
	puts("");
	return 0;
}