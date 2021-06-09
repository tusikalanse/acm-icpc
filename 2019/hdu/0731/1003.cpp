#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int T, n, k, a, sum;

vector<int> ans[N];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &k);
		if(n == k && k == 1) {
			puts("yes\n1");
			continue;
		}
		if(n == k) {
			puts("no");
			continue;
		}
		a = n / k;
		if(a % 2 == 0) {
			puts("yes");
			int l = 1, r = n;
			for(int i = 0; i < k; ++i) {
				for(int _ = 0; _ < a / 2; ++_)
					ans[i].push_back(l++);
				for(int _ = 0; _ < a / 2; ++_)
					ans[i].push_back(r--);
			}
			for(int i = 0; i < k; ++i) {
				for(int j = 0; j < a; ++j) 
					printf("%d%c", ans[i][j], " \n"[j + 1 == a]);
				ans[i].clear();
			}
		}
		else if(k % 2 == 1) {
			puts("yes");
			int p = n, q = k / 2;
			while(p > 3 * k) {
				for(int i = 0; i < k; ++i)
					ans[i].push_back(p--);
				for(int i = k - 1; ~i; --i)
					ans[i].push_back(p--);
			}
			for(int i = 0; i < k; ++i)
				ans[i].push_back(p--);
			for(int i = 0; i < k; ++i) 
				ans[(q + i) % k].push_back(p--);
			p = 1;
			for(int i = q; i < k; ++i)
				ans[i].push_back(p), p += 2;
			p = 2;
			for(int i = 0; i < q; ++i)
				ans[i].push_back(p), p += 2;
			for(int i = 0; i < k; ++i) {
				for(int j = 0; j < a; ++j) 
					printf("%d%c", ans[i][j], " \n"[j + 1 == a]);
				ans[i].clear();
			}
		}
		else 
			puts("no");
	}

	return 0;
}