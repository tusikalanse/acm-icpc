#include <bits/stdc++.h>
using namespace std;

const int N = 505;

int d[N][N], n, m, T, ans, mx[N], mn[N];
int minn[N], maxx[N];
int h_mn, t_mn, h_mx, t_mx;

int main() {
	scanf("%d", &T);
	while(T--) {
		ans = 0;
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) 
				scanf("%d", &d[i][j]);
		}
		for(int up = 1; up <= n; ++up) {
			memset(mx, 0, sizeof(mx));
			memset(mn, 0x3f, sizeof(mn));
			for(int down = up; down <= n; ++down) {
				h_mn = t_mn = h_mx = t_mx = 0;
				for(int k = 1, left = 0; k <= n; ++k) {
					mx[k] = max(mx[k], d[down][k]);
					mn[k] = min(mn[k], d[down][k]);
					for(; h_mn != t_mn && mn[minn[t_mn - 1]] > mn[k]; ) t_mn--;
					minn[t_mn++] = k;
					for(; h_mx != t_mx && mx[maxx[t_mx - 1]] < mx[k]; ) t_mx--;
					maxx[t_mx++] = k;
					for(; h_mn != t_mn && h_mx != t_mx && mx[maxx[h_mx]] - mn[minn[h_mn]] > m;) {
						if(maxx[h_mx] < minn[h_mn])
							left = maxx[h_mx++];
						else
							left = minn[h_mn++];
					}
					ans = max(ans, (down - up + 1) * (k - left));
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
