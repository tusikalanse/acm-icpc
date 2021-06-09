#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, k, a[N];
priority_queue<int> pq;
char s[N];
long long ans;


int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	scanf("%s", s + 1);
	int j;
	for(int i = 1; i <= n; i = j + 1) {
		j = i;
		while(s[i] == s[j]) ++j;
		j--;
		while(!pq.empty()) pq.pop();
		for(int p = i; p <= j; ++p) 
			pq.push(a[p]);
		for(int p = 1; p <= k; ++p) {
			if(pq.empty()) break;
			ans += pq.top();
			pq.pop();
		}
	}
	printf("%lld\n", ans);
	return 0;
}