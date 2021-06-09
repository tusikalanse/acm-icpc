#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int ret = 0;
	int f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-')
			f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}



int n, sum[200010];

inline int lowbit(int x) {
	return x & (-x);
}

void update(int x, int val) {
	for(int i = x; i <= n; i += lowbit(i)) 
		sum[i] += val;
}

int getsum(int x) {
	int ret = 0;
	for(int i = x; i; i -= lowbit(i))
		ret += sum[i];
	return ret;
}

pair<int, int> data[200010];
int a[200010];

int main() {
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		data[i] = make_pair(a[i], i);
		update(i, 1);
	}
	sort(data + 1, data + n + 1);
	long long ans = 0;
	int p = 1;
	for(int i = 1; i <= n; i++) {
		while(p <= n && data[p].first < i) {
			update(data[p].second, -1);
			p++;
		}
		ans += getsum(min(a[i], n));
		if(a[i] >= i)
			ans--;
	}
	printf("%lld\n", ans/2);
	return 0;
}