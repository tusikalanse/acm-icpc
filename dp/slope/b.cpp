#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 400010;
LL a[N], sum[N], ans, dp[N];
int n, t, head, tail, que[N];

void print() {
	// cout << "que: " << "head: " << head << " tail: " << tail << " eles: ";
	// for(int i = head; i < tail; ++i)
	// 	cout << que[i] << " ";
	// cout << endl;
}

inline LL X(int i) {return a[i + 1];}
inline LL Y(int i) {return i * a[i + 1] + dp[i] - sum[i];}
inline LL KX(int a, int b) {return X(a) - X(b);}
inline LL KY(int a, int b) {return Y(a) - Y(b);}

int main() {
	while(~scanf("%d%d", &n, &t)) {
		dp[0] = a[0] = ans = sum[0] = head = tail = 0;
		for(int i = 1; i <= n; ++i)
			scanf("%lld", &a[i]);
		sort(a + 1, a + n + 1);
		for(int i = 1; i <= n; ++i)
			sum[i] = sum[i - 1] + a[i];
		for(int i = t; i <= n; ++i) {
			print();
			if(i - t == 0 || i - t >= t) {
				while(head < tail - 1 && KY(que[tail - 1], que[tail - 2]) * KX(i - t, que[tail - 1]) >= KX(que[tail - 1], que[tail - 2]) * KY(i - t, que[tail - 1]))
					tail--;
				que[tail++] = i - t;
			}
			print();
			while(head < tail - 1 && KY(que[head + 1], que[head]) <= KX(que[head + 1], que[head]) * i)
				head++;
			print();
			dp[i] = -i * X(que[head]) + Y(que[head]) + sum[i];
		//	cout << i << 'd' << dp[i] << endl;
		}
		printf("%lld\n", dp[n]);
	}
	return 0;
}