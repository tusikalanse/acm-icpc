#include <bits/stdc++.h>
using namespace std;



int sn[200010], sw[200010], nxt[200010], n, w;

void getnext() {
	memset(nxt, 0, sizeof(nxt));
	nxt[0] = -1;
	int j = 0, k = -1;
	while(j < w) {
		if(k == -1 || sw[j] == sw[k])
			nxt[++j] = ++k;
		else
			k = nxt[k];
	}
}

int kmp() {
	int i = 0, j = 0, cnt = 0;
	getnext();
	while(i < n) {
		if(j == -1 || sw[j] == sn[i]) 
			++i, ++j;
		else
			j = nxt[j];
		if(j == w)
			++cnt, j = nxt[j];
	}
	return cnt;
}

int main() {
	scanf("%d%d", &n, &w);
	if(w == 1) {
		printf("%d\n", n);
		return 0;
	}
	for(int i = 0; i < n; ++i)
		scanf("%d", &sn[i]);
	for(int i = 0; i < w; ++i)
		scanf("%d", &sw[i]);
	n--;
	w--;
	for(int i = 0; i < n; ++i) 
		sn[i] = sn[i + 1] - sn[i];
	sn[n] = 0;
	for(int i = 0; i < w; ++i) 
		sw[i] = sw[i + 1] - sw[i];
	sw[w] = 0;
	printf("%d\n", kmp());
	return 0;
}