#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int nxt[200010], n, ans, mod = 10007;
char s[200010];

void getnext() {
	memset(nxt, 0, sizeof(nxt));
	nxt[0] = -1;
	int k = -1, j = 0;
	while(j < n) {
		if(k == -1 || s[j] == s[k]) 
			nxt[++j] = ++k;
		else
			k = nxt[k];
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		ans = n % mod;
		scanf("%s", s);
		getnext();
		for(int i = 1; i <= n; ++i) {
			int cnt = 0, j = i;
			while(nxt[j] > 0) {
				++cnt;
				j = nxt[j];
			}
			ans = (ans + cnt) % mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}