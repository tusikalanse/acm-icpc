#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e7;
int prime = 980321;
int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%d %d\n", prime, prime);
	for(int i = 1; i<n; i++){
		if(i != n-1){
			printf("%d %d 2\n", i, i+1);
			prime -= 2;
		}
		else
			printf("%d %d %d\n", i, i+1, prime);
	}
	int k = 1, j = 3;
	for(int i = 0; i< m-(n-1); i++){
		if(j > n){
			k++;
			j = k + 2;
		}
		printf("%d %d %d\n", k, j, MAXN);
		j++;
	}
	return 0;
}