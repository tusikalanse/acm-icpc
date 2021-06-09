#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 110;

int nxt[MAXN];
char lst[MAXN][MAXN];

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
	int T, n, mmin, id;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		mmin = 111;
		for(int i = 1; i <= n; ++i) {
			scanf("%s", lst[i]);
			if(strlen(lst[i]) < mmin) {
				mmin = strlen(lst[i]);
				id = i;
			} 
		}
		if(n == 1) {
			printf("%d\n", (int)strlen(lst[1]));
			continue;
		}
		if(id != 1) 
			swap(lst[1], lst[id]);
		int len = strlen(lst[1]);
		for(int l = len; l >= 1; --l) {
			for(int i = 0; i + l - 1 < len; ++i) {
				char tmp[2][110];
				strncpy(tmp[1], &lst[1][i], l);
				strncpy(tmp[0], &lst[1][i], l);
				tmp[0][l] = tmp[1][l] = '\0';
				reverse(tmp[0], &tmp[0][l]);
				bool flag = 1;
				for(int j = 2; j <= n; ++j) {
					if(kmp(tmp[0], lst[j]) == 0 && kmp(tmp[1], lst[j]) == 0) {
						flag = 0;
						break;
					}
				}
				if(flag) {
					printf("%d\n", l);
					goto out;
				}
			}
		}
		puts("0");
		out:;
	}
	return 0;
}
