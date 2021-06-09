#include <bits/stdc++.h>
using namespace std;

int l[5005], r[5005], ans[5005];
int T, n, tim;

int main(){
	scanf("%d", &T);
	while(T--){
		tim = 1;
		scanf("%d", &n);
		memset(l, 0, sizeof(l));
		memset(r, 0, sizeof(r));
		memset(ans, 0, sizeof(ans));
		for(int i = 1; i<=n; i++){
			scanf("%d %d", &l[i], &r[i]);
		}
		int i = 1;
		while(i<=n){
			if(tim >= l[i]){
				if(tim <= r[i]){
					ans[i] = tim++;
				}
				else ans[i] = 0;
				i++;
			}
			else tim = l[i];
		}
		printf("%d", ans[1]);
		for(int i = 2; i<=n; i++){
			printf(" %d", ans[i]);
		}
		puts("");
	}
	return 0;
}
