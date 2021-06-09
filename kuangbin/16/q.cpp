#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1e6+10;
char s[MAXN];
int nxt[MAXN], ans[MAXN];

void getnext() {
	int len = strlen(s);
	nxt[0] = len;
	int i = 0, po;
	while(i + 1 < len && s[i] == s[i+1])
		i++;
	nxt[1] = i;
	po = 1;
	for(i = 2; i < len; ++i) {
		if(nxt[i - po] + i < nxt[po] + po) {
			nxt[i] = nxt[i - po];
		}
		else {
			int j = nxt[po] + po - i;
			if(j < 0)
				j = 0;
			while(i + j < len && s[j] == s[i + j])
				++j;
			nxt[i] = j;
			po = i;
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; ++cas) {
		int cnt = 0;
		scanf("%s", s);
		int len = strlen(s);
		getnext();
		for(int i = 1; i < len; ++i) {
			if(i + nxt[i] >= len)
				ans[cnt++] = i;
		}
		ans[cnt++] = len;
		printf("Case #%d: %d\n", cas, cnt);
		for(int i = 0; i < cnt; ++i)
			printf("%d%c", ans[i], " \n"[i == cnt - 1]);
	}
	return 0;
}