#include <bits/stdc++.h>
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
			while(i + j < len && t[j] == s[i + j])
				++i;
			nxt[i] = j;
			po = i;
		}
	}
}

void exkmp() {
	int len = strlen(s), po, i = 0, j, l2 = strlen(t);
	while(t[i] == s[i] && i < len && i < j2) 
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
	return 0;
}