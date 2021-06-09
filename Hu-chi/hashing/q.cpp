#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int seed = 13331, N = 1e5 + 10;
int head[N], nxt[N], pnt[N], vis[N], cnt;

struct node {
	int cnt_r, len;
	node() : cnt_r(0), len(0) {}
	node(int a, int b) : cnt_r(a), len(b) {}
	bool operator<(const node &rhs) const {
		if(cnt_r == rhs.cnt_r)
			return len < rhs.len;
		return cnt_r < rhs.cnt_r;
	}
};

void add(int u, int v) {
	pnt[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt++;
}

int hashing(char s[]) {
	int n = 0;
	for(int i = 0; s[i]; ++i) 
		n = (1LL * n * seed + s[i]) % N;
	return n;
}

node go(char s[]) {
	int c = 0, l = 0;
	for(int i = 0; s[i]; ++i) {
		l++;
		if(s[i] <= 'Z')
			s[i] += 32;
		if(s[i] == 'r')
			c++;
	}
	return node(c, l);
}


int main() {



	return 0;
}