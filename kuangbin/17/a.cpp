#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN = 10010*50;
const int KIND = 26;
const int MAXM = 1000010;

char str[MAXM];

struct AC_automation {
	int L, root;
	int nxt[MAXN][KIND], fail[MAXN], end[MAXN];
	AC_automation() : L(0) {}
	void init() {
		L = 0;
		root = newnode();
	}

	int newnode() {
		for(int i = 0; i < KIND; ++i) 
			nxt[L][i] = -1;
		fail[L] = -1;
		end[L] = 0;
		return L++;
	}

	void insert(char *s) {
		int p = root;
		for(int i = 0; s[i]; ++i) {
			if(nxt[p][s[i]-'a'] == -1)
				nxt[p][s[i]-'a'] = newnode();
			p = nxt[p][s[i]-'a'];
		}
		end[p]++;
	}

	void build() {
		queue<int> Q;
		fail[root] = root;
		for(int i = 0; i < KIND; ++i) {
			if(nxt[root][i] == -1)
				nxt[root][i] = root;
			else {
				fail[nxt[root][i]] = root;
				Q.push(nxt[root][i]);
			}
		}
		while(!Q.empty()) {
			int now = Q.front();
			Q.pop();
			for(int i = 0; i < KIND; ++i) {
				if(nxt[now][i] == -1) {
					nxt[now][i] = nxt[fail[now]][i];
				}
				else {
					fail[nxt[now][i]] = nxt[fail[now]][i];
					Q.push(nxt[now][i]);
				}
			}
		}
	}

	int match(char *s) {
		int now = root, res = 0;
		for(int i = 0; s[i]; ++i) {
			now = nxt[now][s[i] - 'a'];
			int tmp = now;
			while(tmp != root) {
				res += end[tmp];
				end[tmp] = 0;
				tmp = fail[tmp];
			}
		}
		return res;
	}
}AC;


int main() {
	int T, n;
	scanf("%d", &T);
	while(T--) {
		AC.init();
		scanf("%d", &n);
		while(n--) {
			scanf("%s", str);
			AC.insert(str);
		}
		AC.build();
		scanf("%s", str);
		printf("%d\n", AC.match(str));
	}
	return 0;
}