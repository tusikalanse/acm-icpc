#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

bool all[110], any;

int x[110], y[110];
double dis[110];

int main() {
	int n, T, R, r;
	scanf("%d", &T);
	while(T--) {
		double mmin = 1e10;
		memset(all, 0, sizeof(all));
		any = 0;
		scanf("%d %d %d", &n, &R, &r);
		for(int i = 1; i <= n; ++i) {
			scanf("%d %d", &x[i], &y[i]);
			dis[i] = hypot((double)x[i], (double)y[i]);
			if(dis[i] + R <= r * 2 || dis[i] + 2 * r <= R) {
				all[i] = 1;
				any = 1;
			}
			mmin = min(dis[i], mmin);
		}
		vector<int> out;
		if(any) {
			for(int i = 1; i <= n; ++i) {
				if(all[i]) 
					out.push_back(i);
			}
		}
		else {
			for(int i = 1; i <= n; ++i)
				if(dis[i] == mmin)
					out.push_back(i);
		}
		printf("%d\n", (int)out.size());
		printf("%d", out[0]);
		for(int i = 1; i < out.size(); ++i)
			printf(" %d", out[i]);
		puts("");
	}
	return 0;
}