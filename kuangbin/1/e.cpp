#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int flag, n;

void dfs(unsigned long long x, int k){
	if(flag)
		return;
	if(x % n == 0){
		printf("%llu\n", x);
		flag = 1;
		return;
	}
	if(k == 19)
		return;
	dfs(x * 10, k + 1);
	dfs(x * 10 + 1, k + 1);
}




int main(){
	while(~scanf("%d", &n) && n){
		flag = 0;
		dfs(1, 0);
	}
	return 0;
}