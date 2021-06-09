#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int fa[1010], pre[1010], vis[1010], sum[1010], size[1010], val[1010];
int N, R, v1, v2;

int Find(int x) {
	return x == pre[x] ? x : pre[x] = Find(pre[x]);
}

int Find_max() {
	int num;
	double mmax = 0;
	for(int i = 1; i <= N; i++) {
		int fi = Find(i);
		if(i != R && !vis[i] && (double)sum[fi]/(double)size[fi] > mmax) {
			mmax = (double)sum[fi]/(double)size[fi];
			num = i;
		}
	}
	return num;
}

int main() {
	while(~scanf("%d %d", &N, &R) && N) {
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= N; i++) {
			scanf("%d", &val[i]);
			pre[i] = i;
			size[i] = 1;
			sum[i] = val[i];
		}
		for(int i = 1; i < N; i++) {
			scanf("%d %d", &v1, &v2);
			fa[v2] = v1;
		}
		int ans = 0;
		for(int i = 1; i < N; i++) {
			int num = Find_max();
			int fi = Find(num), fs = Find(fa[num]);
			pre[fi] = fs;
			ans += size[fs]*sum[fi];
			vis[num] = 1;
			size[fs] += size[fi];
			sum[fs] += sum[fi];
		}
		ans += sum[R];
		printf("%d\n", ans);
	}
	return 0;
}
