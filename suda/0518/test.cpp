#include <stdio.h>
#include <algorithm>
using namespace std;

double mat[128][128];
int arr[10008];

int M,N;

double dfs(int i, int c)
{
	if (c == N)
	{
		return mat[i][arr[N - 1]];
	}
	return max(dfs(i,c + 1),dfs(arr[c - 1],c + 1)) * mat[i][arr[c - 1]];
}

int main()
{
	while (scanf("%d",&M) != EOF)
	{
		M = M * (M - 1) * (M - 2) / 3 / 2;
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
		double res = -1;
		for (int i = 0; i < M; ++i)
		{
			res = max(dfs(i,1),res);
		}
		printf("%lf\n",res);
	}
}