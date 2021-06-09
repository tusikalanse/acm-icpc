#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, knd = 26;

char s[N];
int L[knd], R[knd], cnt[N][knd], c[knd], n, k, nxt[N][knd], pos, tmp, tot;
char ans[N];

bool check(int p, int now) {
	if(p < 0) return false;
	int x = s[p] - 'a', res = 0, ret = 1;
	if(c[x] == R[x]) return false;
	c[x]++;
	for(int i = 0; i < knd; ++i) {
		if(L[i] > c[i]) res += L[i] - c[i];
		if(cnt[p][i] - (x == i) < L[i] - c[i]) {
			ret = 0;
			break;
		}
	}
	if(res > k - now) 
		ret = 0;
	c[x]--;
	return ret;
}

int main() {
	while(~scanf("%s%d", s, &k)) {
		tot = 0;
		n = strlen(s);
		for(int i = 0; i < knd; ++i) {
			scanf("%d%d", &L[i], &R[i]);
			tot += R[i];
		}
		memset(nxt[n], -1, sizeof(nxt[n]));
		memset(cnt[n], 0, sizeof(cnt[n]));
		memset(c, 0, sizeof(c));
		for(int i = n - 1; ~i; --i) {
			memcpy(nxt[i], nxt[i + 1], sizeof(nxt[i + 1]));
			memcpy(cnt[i], cnt[i + 1], sizeof(cnt[i + 1]));
			nxt[i][s[i] - 'a'] = i;
			cnt[i][s[i] - 'a']++;
		}
		pos = -1;
		for(int i = 0; i < knd; ++i) {
			if(check(nxt[0][i], 1)) {
				c[i]++;
				pos = nxt[0][i] + 1;
				ans[0] = 'a' + i;
				break;
			}
		}
		if(pos == -1 || tot < k) {
			puts("-1");
			continue;
		}
		for(int i = 1; i < k; ++i) {
			for(int j = 0; j < knd; ++j) {
				if(c[j] == R[j]) continue;
				if(check(nxt[pos][j], i + 1)) {
					c[j]++;
					pos = nxt[pos][j] + 1;
					ans[i] = 'a' + j;
					break;
				}
			}
		}
		ans[k] = '\0';
		printf("%s\n", ans);
	}
	return 0;
}