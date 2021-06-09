#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int T, n, pre, now, id, cas = 0;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		pre = -3;
		for(int i = 1; i<=n; i++){
			scanf("%d", &now);
			if(pre + 1 != now)
				id = i;
			pre = now;
		}
		printf("Case #%d: %d\n", ++cas, id);
	}
	return 0;
}