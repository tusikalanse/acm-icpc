#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char DNA[12][66];
int nxt[66];

void getnext(char *s, int n) {
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

bool kmp(char *s, char *ls, int n) {
	int i = 0, j = 0;
	while(i < 60) {
		if(j == -1 || ls[i] == s[j]) {
			++i;
			++j;
		}
		else
			j = nxt[j];
		if(j == n)
			return true;
	}
	return false;
}

int main() {
	int T, n, pted;
	scanf("%d", &T);
	while(T--) {
		pted = 0;
		scanf("%d", &n);
		char ans[66] = "a";
		for(int i = 0; i < n; ++i)
			scanf("%s", DNA[i]);
		for(int len = 60; len > 2; --len) {
			for(int i = 0; i <= 60 - len; ++i) {
				char sub[66] = {'\0'};
				strncpy(sub, &DNA[0][i], len);
				getnext(sub, len);
				int flag = 1;
				for(int j = 1; j < n; ++j) {
					if(!kmp(sub, DNA[j], len)) {
						flag = 0;
						break;
					}
				}
				if(flag == 1 && strcmp(ans, sub) > 0) {
					strcpy(ans, sub);
				}
			}
			if(ans[0] != 'a') {
				printf("%s\n", ans);
				pted = 1;
				break;
			}
		}
		if(pted == 0) {
			puts("no significant commonalities");
		}
	}
	return 0;
}