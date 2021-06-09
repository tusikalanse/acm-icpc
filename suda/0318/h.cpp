#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int ans[1005];
	memset(ans, 0, sizeof(ans));
	ans[1] = 2;
	for(int i = 2; i<=1000; i++){
		ans[i] = ans[i-1] + 4*2*(i-1);
	}
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}

	return 0;
}