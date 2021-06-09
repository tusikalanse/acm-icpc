#include <bits/stdc++.h>
using namespace std;

int nxt1[100010], nxt2[100010];
char s1[100010], s2[100010];
int l1, l2;

void getnext(int nxt[], char s[], int l) {
	nxt[0] = -1;
	int k = -1, j = 0;
	while(j < l) {
		if(k == -1 || s[k] == s[j])
			nxt[++j] = ++k;
		else
			k = nxt[k];
	}
}

bool cmp(int s) {
	for(int i = 0; i < s; ++i) {
		if(s1[i] != s2[i])
			return false;
	}
	return true;
}

int main() {
	scanf("%s%s", s1, s2);
	l1 = strlen(s1);
	l2 = strlen(s2);
	getnext(nxt1, s1, l1);
	getnext(nxt2, s2, l2);
	int g1 = l1 - nxt1[l1], g2 = l2 - nxt2[l2];
	if(l1 % g1)
		g1 = l1;
	if(l2 % g2)
		g2 = l2;
	if(g1 != g2 || cmp(g1) == 0) {
		printf("0\n");
		return 0;
	}
	l1 /= g1;
	l2 /= g2;
	int ans = 0, mm = min(l1, l2);
	for(int i = 1; i <= mm; ++i) {
		if(l1 % i == 0 && l2 % i == 0)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}