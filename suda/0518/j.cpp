#include <cstdio>
#include <algorithm>
using namespace std;

double mat[128][128];
int arr[128];
double ans[128];

int M,N;

int main() {
	while (scanf("%d",&M) != EOF) {
		M = M * (M - 1) * (M - 2) / 6;
		for (int l = 0; l < M; ++l)
		{
			for (int c = 0; c < M; ++c)
			{
				scanf("%lf",&mat[l][c]);
			}
		}
		scanf("%d",&N);
		for (int i = 0; i < N; ++i)
		{
			scanf("%d",&arr[i]);
		}
		for(int i = 0; i < M; ++i) {
			ans[i] = 1;
		}
		for (int i = 0; i < N; ++i) {
			for(int j = 0; j < M; ++j) {
				ans[j] = ans[j] * mat[j][arr[i]];
			}
			for(int j = 0; j < M; ++j)
				ans[arr[i]] = max(ans[arr[i]], ans[j]);
		}
		double res = -1;
		for(int i = 0; i < M; ++i)
			res = max(res, ans[i]);
		printf("%.10lf\n",res);
	}
	return 0;
}
