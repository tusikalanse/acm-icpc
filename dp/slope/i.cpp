#include <iostream>
#include <cstdio>
using namespace std;
#define LL long long

const int MAXN = 1000010;
int a[MAXN], que[MAXN];
LL sum[MAXN];
int n, k, head, tail;

inline int KX(int a, int b) {return a - b;}
inline int KY(int a, int b) {return sum[a] - sum[b];}

int main() {
	int n,k;
	while(~scanf("%d%d",&n,&k)) {
		sum[0] = head = tail = 0;
		for(int i = 1; i <= n; ++i) {
			scanf("%d",&a[i]);
			a[i] *= 1000;
			sum[i] = sum[i - 1] + a[i];
		}
		LL ans = 0;
		for(int i = k; i <= n; ++i) {
			while(head < tail - 1 && 1LL * KY(i - k, que[tail - 1]) * KX(que[tail - 1], que[tail - 2]) <= 1LL * KY(que[tail - 1], que[tail - 2]) * KX(i - k, que[tail - 1]))
				tail--;
			que[tail++] = i - k;
			while(head < tail - 1 && 1LL * KY(i, que[head + 1]) * KX(que[head + 1], que[head]) >= 1LL * KY(que[head + 1], que[head]) * KX(i, que[head + 1]))
				head++;
			ans = max(ans, (sum[i] - sum[que[head]]) * 1.0 / (i - que[head]));
		}
		printf("%lld\n", ans);
	}
	return 0;
}