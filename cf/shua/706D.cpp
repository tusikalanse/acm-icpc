#include <bits/stdc++.h>
using namespace std;

int cnt[6000010], nxt[6000010][2], root, n, num, x;
char com[5];

void insert(int x) {
	int p = root;
	for(int i = 29; ~i; --i) {
		int op = (x >> i) & 1;
		if(nxt[p][op] == 0) {
			nxt[p][op] = ++num;
		}
		p = nxt[p][op];
		cnt[p]++;
	}
}

void del(int x) {
	int p = root;
	for(int i = 29; ~i; --i) {
		int op = (x >> i) & 1;
		p = nxt[p][op];
		cnt[p]--;
	}
}

int query(int x) {
	int p = root, ans = 0;
	for(int i = 29; ~i; --i) {
		int op = (x >> i) & 1;
		if(nxt[p][op ^ 1] != 0 && cnt[nxt[p][op ^ 1]] != 0) {
			ans += 1 << i;
			p = nxt[p][op ^ 1];
		}
		else
			p = nxt[p][op];
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	root = 0;
	insert(0);
	while(n--) {
		scanf("%s%d", com, &x);
		if(com[0] == '+') 
			insert(x);
		else if(com[0] == '-')
			del(x);
		else
			printf("%d\n", query(x));
	}
	return 0;
}