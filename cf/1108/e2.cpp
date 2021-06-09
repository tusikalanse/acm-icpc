#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 310;

int n, a[N], b[N], ans, l[M], r[M], m, rec, cnt;
set<int> key;


int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) 
		scanf("%d", &a[i]);
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d", &l[i], &r[i]);
		key.insert(l[i]);
		key.insert(r[i] + 1);
	}
	ans = *max_element(a + 1, a + n + 1) - *min_element(a + 1, a + n + 1);	
	for(auto it = key.begin(); it != key.end(); ++it) {
		int i = *it; ++cnt;
		memset(b, 0, sizeof(b));
		int mx = -1e9, mn = 1e9, sum = 0;
		for(int j = 1; j <= m; ++j) {
			if(l[j] <= i && i <= r[j]) continue;
			b[l[j]]--, b[r[j] + 1]++;
		}
		for(int j = 1; j <= n; ++j) {
			sum += b[j];
			mx = max(mx, a[j] + sum);
			mn = min(mn, a[j] + sum);
		}
		if(mx - mn > ans) {
			rec = i;
			ans = mx - mn;
		}
	}	
	printf("%d\n", ans);
	if(rec) {
		vector<int> res;
		for(int i = 1; i <= m; ++i) {
			if(l[i] <= rec && rec <= r[i]) continue;
			res.push_back(i);
		}
		printf("%d\n", (int)res.size());
		for(int i = 0; i < res.size(); ++i)
			printf("%d%c", res[i], " \n"[i == res.size() - 1]);
	}
	else
		puts("0\n");
	return 0;
}