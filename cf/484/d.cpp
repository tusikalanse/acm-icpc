#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
#define PLL pair<long long, long long>
int a[N], fa[N], sum[N], cntsum[N], cnt;
PLL b[N];

int Find(int x) {
	return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

void Unite(int x, int y) {
	x = Find(x);
	y = Find(y);
	fa[y] = x;
	cntsum[sum[x]]--, cntsum[sum[y]]--;
	sum[x] += sum[y];
	cntsum[sum[x]]++;
	cnt--;
}

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		b[i] = make_pair(a[i], i);
		fa[i] = i;
	}
	sort(b, b + n);
	int mx = 0, ans = 0;
	for(int i = 0; i < n; ++i) {
		int y = b[i].first;
		int x = b[i].second;
		cnt++;
		sum[x] = 1;
		cntsum[1]++;
		if(x != 0 && a[x - 1] < a[x])
			Unite(x - 1, x);
		if(x != n - 1 && a[x + 1] < a[x])
			Unite(x, x + 1);
		if(cnt == cntsum[sum[Find(x)]])
			if(cnt > mx) {
				mx = cnt;
				ans = y + 1;
			}
	}
	cout << ans << endl;
	return 0;
}