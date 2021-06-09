#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char W[400010];
int nxt[400010], ans[400010];
int m;

void getnext() {
	memset(nxt, 0, sizeof(nxt));
	nxt[0] = -1;
	int k = -1, j = 0;
	while(j < m) {
		if(k == -1 || W[k] == W[j])
			nxt[++j] = ++k;
		else
			k = nxt[k];
	}
}

int main() {
	while(~scanf("%s", W)) {
		int cnt = 0;
		m = strlen(W);
		getnext();
		ans[cnt++] = m;
		while(nxt[m] > 0) {
			ans[cnt++] = nxt[m];
			m = nxt[m];
		}
		sort(ans, ans + cnt);
		for(int i = 0; i < cnt; ++i)
			printf("%d%c", ans[i], " \n"[i == cnt - 1]);
	}
	return 0;
}
