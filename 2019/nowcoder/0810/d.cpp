#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m, h, q, op, x, y, z;

struct BIT {
	static int lowbit(int x) {return x & -x;}
	static void mmax(int &x, int y) {x = (x > y ? x : y);}
	static int index(int i, int j, int k) {return (i - 1) * m * h + (j - 1) * h + k;}
	int c[N];
	void init() {memset(c, 0xc0, sizeof(c));}
	void update(int x, int y, int z, int val) {
		for(int i = x; i <= n; i += lowbit(i)) 
			for(int j = y; j <= m; j += lowbit(j))
				for(int k = z; k <= h; k += lowbit(k))
					mmax(c[index(i, j, k)], val);
	} 
	int query(int x, int y, int z) {
		int res = -1e9;
		for(int i = x; i; i -= lowbit(i))
			for(int j = y; j; j -= lowbit(j))
				for(int k = z; k; k -= lowbit(k))
					res = max(res, c[index(i, j, k)]);
		return res;
	}
}T[8];


int main() {
	scanf("%d%d%d%d", &n, &m, &h, &q);
	for(int i = 0; i < 8; ++i) T[i].init();
	while(q--) {
		scanf("%d%d%d%d", &op, &x, &y, &z);
		if(op == 1) {
			for(int mask = 0; mask < 8; ++mask) {
				int tx = x, ty = y, tz = z, vx = x, vy = y, vz = z;
				if(mask & 1) tx = n - tx + 1, vx = -vx;
				if(mask & 2) ty = m - ty + 1, vy = -vy;
				if(mask & 4) tz = h - tz + 1, vz = -vz;
				T[mask].update(tx, ty, tz, vx + vy + vz);
			}
		}
		else {
			int res = 1e9;
			for(int mask = 0; mask < 8; ++mask) {
				int tx = x, ty = y, tz = z, vx = x, vy = y, vz = z;
				if(mask & 1) tx = n - tx + 1, vx = -vx;
				if(mask & 2) ty = m - ty + 1, vy = -vy;
				if(mask & 4) tz = h - tz + 1, vz = -vz;
				res = min(res, vx + vy + vz - T[mask].query(tx, ty, tz));
			}
			printf("%d\n", res);
		}
	}
	return 0;
}