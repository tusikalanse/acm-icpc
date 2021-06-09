#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;

const int MAXN = 100010;
char s[MAXN], t[MAXN];
int nxt[MAXN], extend[MAXN];

void getnext() {
	int len = strlen(t), po, i = 0, j;
	nxt[0] = len;
	while(t[i] == t[i+1] && i + 1  < len) 
		++i;
	nxt[1] = i;
	po = 1;
	for(i = 2; i < len; ++i) {
		if(nxt[i - po] + i < po + nxt[po])
			nxt[i] = nxt[i - po];
		else {
			j = po + nxt[po] - i;
			if(j < 0) j = 0;
			while(i + j < len && t[j] == t[i + j])
				++j;
			nxt[i] = j;
			po = i;
		}
	}
}

void exkmp() {
	memset(nxt, 0, sizeof(nxt));
	memset(extend, 0, sizeof(extend));
	getnext();
	int len = strlen(s), po, i = 0, j, l2 = strlen(t);
	while(t[i] == s[i] && i < len && i < l2) 
		++i;
	extend[0] = i;
	po = 0;
	for(i = 1; i < len; ++i) {
		if(nxt[i - po] + i < po + extend[po])
			extend[i] = nxt[i - po];
		else {
			j = po + extend[po] - i;
			if(j < 0) j = 0;
			while(i + j < len && j < l2 && t[j] == s[i + j])
				++j;
			extend[i] = j;
			po = i;
		}
	}
}

int main() {
	int T;
	char tab[30];
	map<char, char> q;
	scanf("%d", &T);
	while(T--) {
		scanf("%s%s", tab, s);
		int l = strlen(s);
		for(int i = 0; i < 26; ++i)
			q[tab[i]] = 'a' + i;
		for(int i = 0; i < l; ++i) 
			t[i] = q[s[i]];
		t[l] = s[l];
		exkmp();
		int i;
		for(i = 0; i < l; ++i) {
			if(i + extend[i] >= l && i >= extend[i]) {
				break;
			}
		}
		for(int j = 0; j < i; ++j)
				putchar(s[j]);
		for(int j = 0; j < i; ++j)
			putchar(t[j]);
		puts("");
	}
	return 0;
}