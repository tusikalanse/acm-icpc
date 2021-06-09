#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <numeric>
using namespace std;

const int KIND = 256;
const int MAXN = 512 * 64 + 100;

int mp[256], queue[MAXN], vis[60000];
unsigned char buf[5000];
char str[5000];

void init() {
	for(int i = 0; i < 26; ++i) mp[i + 'A'] = i;
	for(int i = 0; i < 26; ++i) mp[i + 'a'] = i + 26;
	for(int i = 0; i < 10; ++i) mp[i + '0'] = i + 52;
	mp['+'] = 62;
	mp['/'] = 63;
}

int convert(char *s) {
	int x = 0, cnt = 0, len = 0;
	for(int i = 0; s[i] != '\0' && s[i] != '='; i++) {
		x = (x << 6) | mp[s[i]];
		len += 6;
		if(len >= 8) {
			len -= 8;
			buf[cnt++] = 0xff & (x >> len);
		}
	}
	return cnt;
}

struct AC_automation {
	int root, L;
	int fail[MAXN], type[MAXN], nxt[MAXN][KIND], cnt[MAXN];

	AC_automation() : L(0) {}

	void init() {
		L = 0;
		root = newnode();
	}

	int newnode() {
		for(int i = 0; i < KIND; ++i)
			nxt[L][i] = -1;
		fail[L] = -1;
		type[L] = -1;
		cnt[L] = 0;
		return L++;
	}

	void insert(unsigned char *s, int len, int id) {
		int p = root;
		for(int i = 0; i < len; ++i) {
			if(nxt[p][s[i]] == -1)
				nxt[p][s[i]] = newnode();
			p = nxt[p][s[i]];
		}
		type[p] = id;
		cnt[p]++;
	}

	void getfail() {
		int head = 0, tail = 0;
		queue[head++] = root;
		while(head != tail) {
			int tmp = queue[tail++], p = -1;
			for(int i = 0; i < KIND; ++i) {
				if(nxt[tmp][i] == -1)
					continue;
				if(tmp == root) {
					fail[nxt[tmp][i]] = root;
				}
				else {
					p = fail[tmp];
					while(p != -1) {
						if(nxt[p][i] != -1) {
							fail[nxt[tmp][i]] = nxt[p][i];
							break;
						}
						p = fail[p];
					}
					if(p == -1)
						fail[nxt[tmp][i]] = root;
				}
				queue[head++] = nxt[tmp][i];
			}
		}
	}

	int match(unsigned char *s, int len) {
		memset(vis, 0, sizeof(vis));
		int p = root, ans = 0;
		for(int i = 0; i < len; ++i) {
			while(nxt[p][s[i]] == -1 && p != root)
				p = fail[p];
			p = nxt[p][s[i]];
			if(p == -1)
				p = root;
			int tmp = p;
			while(tmp != -1) {
				if(type[tmp] == -1) {}
				else if(type[tmp] > 0 && vis[type[tmp]] == 0) {
					vis[type[tmp]] = 1;
					ans += cnt[tmp];
				}
				else 
					break;
				tmp = fail[tmp];
			}
		}
		return ans;
	}
}AC;

int main() {
	init();
	int n, m;
	while(~scanf("%d", &n)) {
		AC.init();
		for(int i = 1; i <= n; ++i) {
			scanf("%s", str);
			int len = convert(str);
			AC.insert(buf, len, i);
		}
		AC.getfail();
		scanf("%d", &m);
		while(m--) {
			scanf("%s", str);
			int len = convert(str);
			printf("%d\n", AC.match(buf, len));
		}
		puts("");
	}

	return 0;
}