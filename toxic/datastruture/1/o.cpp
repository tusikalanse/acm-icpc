#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 5e5 + 10;
int cnt[N], n, a[N], k, mx, id, nxt;
const int nums[] = {1, 2, 4, 6, 12, 24, 36, 48, 60, 120, 180, 240, 360, 720, 840, 1260, 1680, 2520, 5040, 7560, 10080, 15120, 20160, 25200, 27720, 45360, 50400, 55440, 83160, 110880, 166320, 221760, 277200, 332640, 498960, 554400};
const int fac[] = {1, 2, 3, 4, 6, 8, 9, 10, 12, 16, 18, 20, 24, 30, 32, 36, 40, 48, 60, 64, 72, 80, 84, 90, 96, 100, 108, 120, 128, 144, 160, 168, 180, 192, 200, 216};

char name[N][12];

int sum[N << 2];

void build(int rt, int l, int r) {
	sum[rt] = r - l + 1;
	if(l == r)
		return;
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
}

int update(int rt, int l, int r, int p) {
	sum[rt]--;
	if(l == r) 
		return l;
	int mid = l + r >> 1;
	if(sum[rt << 1] >= p)
		return update(rt << 1, l, mid, p);
	else
		return update(rt << 1 | 1, mid + 1, r, p - sum[rt << 1]);
}

int main() {
	while(~scanf("%d%d", &n, &k)) {
		for(int i = 1; i <= n; ++i) 
			scanf("%s%d", name[i], &a[i]);
		build(1, 1, n);
		id = 0;
		while(nums[id] <= n)
			id++;
		id--;
		mx = fac[id];
		for(int i = n; i; --i) {
			if(nxt > 0)
				nxt--;
			k = 1 + ((k - 1 + nxt) % i + i) % i;
			nxt = update(1, 1, n, k);
			if(n + 1 - i == nums[id]) {
				id = nxt;
				break;
			}
			nxt = a[nxt];
		}
		printf("%s %d\n", name[id], mx);
	}
	return 0;
}