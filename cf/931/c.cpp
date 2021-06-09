#include <bits/stdc++.h>
using namespace std;

int lst[100005];
int mn = 100005, mx = -100005;
int n, ans;

int main(){
	scanf("%d", &n);
	ans = n;
	for(int i = 0; i < n; i++){
		scanf("%d", &lst[i]);
		mn = min(mn, lst[i]);
		mx = max(mx, lst[i]);
	}
	if(mx - mn == 2){
		int cnt[3] = {0, 0, 0};
		for(int i = 0; i < n; i++){
			if(lst[i] == mn) cnt[0]++;
			else if(lst[i] == mx) cnt[2]++;
			else cnt[1]++;
		}
		if(cnt[1]/2 > min(cnt[0], cnt[2])){
			int cnt1 = cnt[1]/2, cnt2 = cnt[1]/2, mid = mn + 1;
			for(int i = 0; i < n; i++){
				if(lst[i] == mid){
					if(cnt1){
						lst[i]--;
						cnt1--;
						ans--;
					}
					else if(cnt2){
						lst[i]++;
						cnt2--;
						ans--;
					}
				}
			}
		}
		else{
			int a, b;
			a = b = min(cnt[0], cnt[2]);
			for(int i = 0; i < n; i++){
				if(lst[i] == mn){
					if(a){
						a--;
						ans--;
						lst[i]++;
					}
				}
				else if(lst[i] == mx){

					if(b){
						b--;
						ans--;
						lst[i]--;
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	for(int i = 0; i < n; i++)
		printf("%d ", lst[i]);
	puts("");
	return 0;
}