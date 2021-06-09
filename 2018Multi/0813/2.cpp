#include <bits/stdc++.h>
using namespace std;

const int N = 10010;


int s[N], ans[N], nxt[N], T, m, x, mx;
char a[10];


void getnext(int *s, int *nxt) {
	nxt[0] = -1;
	int k = -1, j = 0;
	while(s[j]) {
		if(k == -1 || s[j] == s[k] || s[j] == -1) 
			nxt[++j] = ++k;
		else
			k = nxt[k];
	}
}

bool judge(int l) {
	for(int i = 0; i < mx; ++i) {
		if(s[i] != -1) {
			if(ans[i % l] != 0 && ans[i % l] != s[i])
				return 0;
			ans[i % l] = s[i];
		}
	}
	int flag = 0;
	for(int i = 0; i < l; ++i) {
		if(ans[i] == 0)
			continue;
		if(ans[i] == 1) {
			if(flag != 0)
				return 0;
		}
		if(ans[i] == 2) {
			if(flag == 2)
				return 0;
			flag = 1;
		}
		if(ans[i] == 3)
			flag = 2;
	}
	return 1;
}

void print(int l) {
	int flag = 0, a = 0, b = 0, c = 0;
	for(int i = 0; i < l; ++i) {
		if(ans[i] == 0) {
			if(flag == 0)
				a++;
			else if(flag == 1)
				b++;
			else if(flag == 2)
				c++;
		}
		if(ans[i] == 1)
			a++;
		if(ans[i] == 2) {
			flag = 1;
			b++;
		}
		if(ans[i] == 3) {
			flag = 2;
			c++;
		}
	}
	printf("%d %d %d\n", a, b, c);

}

int main() {
	scanf("%d", &T);
	while(T--) {
		mx = 0;
		scanf("%d", &m);
		memset(nxt, 0, sizeof(nxt));
		memset(ans, 0, sizeof(ans));
		memset(s, -1, sizeof(s));
		while(m--) {
			scanf("%d%s", &x, a);
			s[x - 1] = a[0] - 'A' + 1;
			mx = max(x, mx);
		}
		s[mx] = 0;
		getnext(s, nxt);
		int l = mx - nxt[mx];
		if(judge(l)) {
			print(l);
		}
		else
			puts("NO");
	}
	return 0;
}