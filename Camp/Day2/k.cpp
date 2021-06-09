#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

int a[15], T, vis[15];
int cnt, cas = 0, mx, nt = 0;
int mp[5000];
int zggg[15];
int valid[(1 << 12) + 10];
int pos1[4][15] = {0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};


inline int lowbit(int x) {
	return x & -x;
}

int stk[5], ans[5];

void dfs(int tmp, int stp, int mask) {
	if(4 + tmp - stp <= mx)
		return;
	if(stp == 4) {
		if(tmp > mx) {
			mx = tmp;
			for(int i = 1; i <= mx; ++i)
				ans[i] = stk[i];
		}
		return;
	}
	if(stp == 3) {
		if(valid[mask]) {
			stk[++cnt] = mask;
			dfs(tmp + 1, stp + 1, 0);
			--cnt;
		}
		else {
			dfs(tmp, stp + 1, 0);
		}
		return;
	}
	int *pos, num = 0;
	if(stp == 0) {
		pos = pos1[0];
		num = 12;
	}
	else {
		pos = pos1[stp];
		int ss = mask;
		while(ss) {
			pos[++num] = mp[lowbit(ss)];
			ss ^= lowbit(ss);
		}
	}
	int fi = pos[1], se, tri;
	mask ^= zggg[fi];
	for(int i = 2; i <= num; ++i) {
		se = pos[i];
		mask ^= zggg[se];
		for(int j = i + 1; j <= num; ++j) {
			//nt++;
			tri = pos[j];
			mask ^= zggg[tri];
			if(a[fi] + a[se] > a[tri]) {
				stk[++cnt] = zggg[fi] ^ zggg[se] ^ zggg[tri];
				dfs(tmp + 1, stp + 1, mask);
				--cnt;
			}
			else {
				dfs(tmp, stp + 1, mask);
			}
			mask ^= zggg[tri];
		}
		mask ^= zggg[se];
	}
	mask ^= zggg[fi];
}

void print() {
	for(int i = 1; i <= mx; ++i) {
		int fi = mp[lowbit(ans[i])];
		ans[i] ^= zggg[fi];
		int se = mp[lowbit(ans[i])];
		ans[i] ^= zggg[se];
		int tri = mp[ans[i]];
		printf("%d %d %d\n", a[fi], a[se], a[tri]);
	}
}

int main() {
	int tot = (1LL << 12) - 1;
	int len = 1;
	mp[len] = 0;
	zggg[0] = len;
	for(int i = 1; i <= 11; ++i) {
		len *= 2;
		mp[len] = i;
		zggg[i] = len;
	}
	for(int i = 0; i <= tot; ++i) {
		int cnt = 0, s = i;
		while(s) {
			s -= lowbit(s);
			cnt++;
		}
		if(cnt != 3)
			valid[i] = -1;
	}
	scanf("%d", &T);
	while(T--) {
		mx = 0;
		for(int i = 0; i < 12; ++i) {
			scanf("%d", &a[i]);
		}
		sort(a, a + 12);
		for(int i = 0; i < tot; ++i) if(valid[i] != -1) {
			int s = i;
			int fi = mp[lowbit(s)];
			s ^= zggg[fi];
			int se = mp[lowbit(s)];
			s ^= zggg[se];
			int tri = mp[s];
			valid[i] = a[fi] + a[se] > a[tri];
		}
		dfs(0, 0, tot);
		printf("Case #%d: %d\n", ++cas, mx);
		print();
	}
	//cout << "cnt = " << nt << endl;
	return 0;
}