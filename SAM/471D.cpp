#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

struct {
	map<int, int> nxt;
	int link, len;
}SAM[N << 1];

int n, w, a[N], b[N], ans, p, sz, last, l;

int newnode(int l) {
	SAM[sz].len = l;
	SAM[sz].nxt.clear();
	return sz++;
}

void init() {
	sz = last = 0;
	SAM[sz].link = -1;
	newnode(0);
}

void add(int x) {
	int p = last, np = newnode(SAM[p].len + 1);
	for(; ~p && !SAM[p].nxt[x]; p = SAM[p].link)
		SAM[p].nxt[x] = np;
	if(p == -1) {
		SAM[np].link = 0;
	}
	else {
		int q = SAM[p].nxt[x];
		if(SAM[q].len == SAM[p].len + 1)
			SAM[np].link = q;
		else {
			int nq = newnode(SAM[p].len + 1);
			SAM[nq].nxt = SAM[q].nxt;
			SAM[nq].link = SAM[q].link;
			SAM[np].link = SAM[q].link = nq;
			for(; ~p && SAM[p].nxt[x] == q; p = SAM[p].link)
				SAM[p].nxt[x] = nq;
		}
	}
	last = np;
}


int main() {
	init();
	scanf("%d%d", &n, &w);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= w; ++i) {
		scanf("%d", &b[i]);
	}
	if(w == 1) {
		printf("%d\n", n);
		return 0;
	}
	for(int i = 1; i < w; ++i) {
		b[i] = b[i + 1] - b[i];
		add(b[i]);
	}
	p = l = 0;
	for(int i = 1; i < n; ++i) {
		a[i] = a[i + 1] - a[i];
		if(SAM[p].nxt.count(a[i])) 
			l++, p = SAM[p].nxt[a[i]];
		else {
			while(~p && !SAM[p].nxt.count(a[i]))
				p = SAM[p].link;
			if(p == -1) 
				p = l = 0;
			else 
				l = SAM[p].len + 1, p = SAM[p].nxt[a[i]];
		}
		if(l == w - 1)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}