#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int T, n, m;
int a[1000010], b[10010], nxt[10010];

void getnext() {
	int k = -1, j = 0;
	memset(nxt, 0, sizeof(nxt));
	nxt[0] = -1;
	while(j < m) {
		if(k == -1 || b[j] == b[k])
			nxt[++j] = ++k;
		else
			k = nxt[k];
	}
}

void kmp() {
	int i = 0, j = 0;
	getnext();
	while(i < n) {
		if(j == -1 || a[i] == b[j]) {
			++i;
			++j;
		}
		else
			j = nxt[j];
		if(j == m) {
			printf("%d\n", i - j + 1);
			return;
		} 
	}
	printf("-1\n");
	return;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &n, &m);
		for(int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		for(int i = 0; i < m; ++i)
			scanf("%d", &b[i]);
		kmp();
	}
	return 0;
}