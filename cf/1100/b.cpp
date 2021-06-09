#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int cnt[N];
char ans[N];
int flag[N];
int n, m, a;

int main() {
	int now = 1;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i) {
		scanf("%d", &a);
		cnt[a]++;
		flag[cnt[a]]++;
		if(flag[now] == n) {
			ans[i] = '1';
			now++;
		}
		else
			ans[i] = '0';
	}
	printf("%s\n", ans);
	return 0;
}