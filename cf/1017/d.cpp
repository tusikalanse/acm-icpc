#include <bits/stdc++.h>
using namespace std;

int sum[4096][110];
int w[15];
int cnt[4096], n, mm, m, q, k;
char s[20];

int go(char s[]) {
	int ans = 0;
	for(int i = 0; i < n; ++i) 
		ans += (s[i] - '0') << i;
	return ans;
}

void pre() {
	mm = (1 << n) - 1;
	for(int i = 0; i <= mm; ++i) {
		for(int j = 0; j <= mm; ++j) if(cnt[j]) {
			int ans = 0;
			for(int k = 0; k < n; ++k) {
				if(((1 << k) & i) == ((1 << k) & j)){
					ans += w[k]; 
				}
			}
			if(ans <= 100)
				sum[i][ans] += cnt[j];
		}
	}
	for(int i = 0; i <= mm; ++i) {
		for(int j = 1; j < 101; ++j)
			sum[i][j] += sum[i][j - 1];
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 0; i < n; ++i)
		scanf("%d", &w[i]);
	for(int i = 0; i < m; ++i) {
		scanf("%s", s);
		cnt[go(s)]++;
	} 
	pre();
	while(q--) {
		scanf("%s%d", s, &k);
		printf("%d\n", sum[go(s)][k]);
	}
	return 0;
}