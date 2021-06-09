#include <bits/stdc++.h>
using namespace std;

int mod[1005], vis[1005][1005];


int main() {
	memset(mod, 0, sizeof(mod));
	memset(vis, 0, sizeof(vis));
	int n, m, t;
	scanf("%d %d", &n, &m);
	if(n >= m) {
		puts("YES");
		return 0;
	}
	while(n--) {
		scanf("%d", &t);
		mod[t % m]++;
	}
	if(mod[0]) {
		puts("YES");
		return 0;
	}
	for(int i = 1; i < m; i++) {
		for(int j = 1; j <= mod[i]; j++) {
			vis[i][(i*j)%m] = 1;
		}
		for(int j = 0; j < m; j++) {
			if(vis[i-1][j]) {
				for(int k = 0; k <= mod[i]; k++)
					vis[i][(j+k*i)%m] = 1;
			}
		}
	}
	puts(vis[m-1][0]?"YES":"NO");
	return 0;
}