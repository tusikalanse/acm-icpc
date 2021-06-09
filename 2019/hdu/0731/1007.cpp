#include <bits/stdc++.h>
using namespace std;

int T, d[5][5], ex, ey, tot, vis[20];

int main() {
	scanf("%d", &T);
	while(T--) {
		tot = 0;
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= 4; ++i) {
			for(int j = 1; j <= 4; ++j) {
				scanf("%d", &d[i][j]);
				if(d[i][j] == 0) 
					ex = i, ey = j;
			}
		}
		while(ex < 4) {
			swap(d[ex][ey], d[ex + 1][ey]);
			ex++;
		}
		while(ey < 4) {
			swap(d[ex][ey + 1], d[ex][ey]);
			ey++;
		}
		for(int i = 1; i <= 4; ++i) {
			for(int j = 1; j <= 4; ++j) {
				if(i == j && i == 4) break;
				int val = d[i][j];
				for(int k = val + 1; k <= 15; ++k)
					tot += vis[k];
				vis[val] = 1;
			}
		}
		puts(tot % 2 ? "No" : "Yes");
	}	
	return 0;
}