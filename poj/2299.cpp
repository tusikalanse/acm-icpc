#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

inline int read(void) {
	char ch = getchar();
	int x = 0, f = 1;
	while(ch < '0' || ch > '9') {
		if(ch == '-') 
			f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

int n, c[500010], b[500010];

inline int lowbit(int x) {
	return x & (-x);
}

void update(int k, int x) {
	for(int i = k; i < n + 5; i += lowbit(i))
		c[i] += x;
}

int getsum(int x) {
	int ans = 0;
	for(int i = x; i; i -= lowbit(i))
		ans += c[i];
	return ans;
}

struct node {
	int id, x;
	bool operator < (const node &rhs) const {
		return x < rhs.x;
	}
}a[500010];

int main() {
	while(n = read()) {
		for(int i = 1; i <= n; i++) {
			a[i].x = read();
			a[i].id = i;
			c[i] = 0;
		}
		sort(a + 1, a + n + 1);
		for(int i = 1; i <= n; i++) {
			b[a[i].id] = i;
		}
		long long res = 0;
		for(int i = n; i > 0; i--) {
			res += getsum(b[i]);
			update(b[i], 1);
		}
		printf("%lld\n", res);
	}
	return 0;
}