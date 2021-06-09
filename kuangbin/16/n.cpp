#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 220;

int nxt[MAXN];
char lst[4100][MAXN];

void getnext(char *s) {
	memset(nxt, 0, sizeof(nxt));
	nxt[0] = -1;
	int k = -1, j = 0, l = strlen(s);
	while(j < l) {
		if(k == -1 || s[k] == s[j])
			nxt[++j] = ++k;
		else
			k = nxt[k];
	}
}

bool kmp(char *s, char *ls) {
	getnext(s);
	int i = 0, j = 0, l = strlen(ls), len = strlen(s);
	while(i < l) {
		if(j == -1 || ls[i] == s[j]) {
			++i;
			++j;
		}
		else
			j = nxt[j];
		if(j == len)
			return true;
	}
	return false;
}

int main() {
	int n, mmin, id;
	while(~scanf("%d", &n) && n) {
		mmin = 311;
		for(int i = 1; i <= n; ++i) {
			scanf("%s", lst[i]);
			if(strlen(lst[i]) < mmin) {
				mmin = strlen(lst[i]);
				id = i;
			} 
		}
		if(id != 1) 
			swap(lst[1], lst[id]);
		int len = strlen(lst[1]);
		for(int l = len; l >= 1; --l) {
			char ans[220] = "#";
			for(int i = 0; i + l - 1 < len; ++i) {
				char tmp[220];
				strncpy(tmp, &lst[1][i], l);
				tmp[l] = '\0';
				bool flag = 1;
				for(int j = 2; j <= n; ++j) {
					if(!kmp(tmp, lst[j])) {
						flag = 0;
						break;
					}
				}
				if(flag && (ans[0] == '#' || strcmp(ans, tmp) > 0)) {
					strcpy(ans, tmp);
				}
			}
			if(ans[0] != '#') {
				printf("%s\n", ans);
				goto out;
			}
		}
		puts("IDENTITY LOST");
		out:;
	}
	return 0;
}
