#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct flower {
	int x, y, z, num, cnt;
	bool operator<(const flower &rhs) const {
		if(y != rhs.y) return y < rhs.y;
		if(z != rhs.z) return z < rhs.z;
		return x < rhs.x;
	}
	bool operator!=(const flower &rhs) const {
		return x != rhs.x || y != rhs.y || z != rhs.z;
	}
}f[N], a[N], tmp[N];

bool cmp(flower &a, flower &b) {
	if(a.x != b.x) return a.x < b.x;
	if(a.y != b.y) return a.y < b.y;
	return a.z < b.z;
}

int ans[N], n, k, c[N << 1], tot;

void add(int i, int val) {
	for(; i <= k; i += i & -i)
		c[i] += val;
}

int sum(int i) {
	int ans = 0;
	for(; i; i -= i & -i)
		ans += c[i];
	return ans;
}

void CDQ(int l, int r) {
	if(l == r) return;
	int mid = l + r >> 1, p = l, i = l, j = mid + 1;
	CDQ(l, mid); CDQ(mid + 1, r);
	while(i <= mid && j <= r) {
		if(a[i].y <= a[j].y) {
			add(a[i].z, a[i].cnt);
			tmp[p++] = a[i++];
		}
		else {
			tmp[p] = a[j];
			tmp[p++].num += sum(a[j++].z);
		}
	}
	while(i <= mid) {
		add(a[i].z, a[i].cnt);
		tmp[p++] = a[i++];
	}
	while(j <= r) {
		tmp[p] = a[j];
		tmp[p++].num += sum(a[j++].z);
	}
	for(int i = l; i <= mid; ++i) 
		add(a[i].z, -a[i].cnt);
	for(int i = l; i <= r; ++i)
		a[i] = tmp[i];
}


int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &f[i].x, &f[i].y, &f[i].z);
	}
	f[0].x = -1;
	sort(f + 1, f + 1 + n, cmp);
	for(int i = 1; i <= n; ++i) {
		if(f[i] != f[i - 1])
			a[++tot] = f[i];
		a[tot].cnt++;
	}
	CDQ(1, tot);
	for(int i = 1; i <= tot; ++i)
		ans[a[i].cnt + a[i].num] += a[i].cnt;
	for(int i = 1; i <= n; ++i)
		printf("%d\n", ans[i]);
    return 0;
}