#include <bits/stdc++.h>
using namespace std;

int l, s, mm = -1, mmm = 30;
char lst[100006];
char ans[100006];
int vis[26];


int main(){
	memset(lst, '\0', sizeof(lst));
	scanf("%d %d %s", &l, &s, lst);
	memset(ans, '\0', sizeof(ans));
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i<l; i++){
		vis[lst[i] - 'a'] = 1;
		mm = max(mm, lst[i] - 'a');
		mmm = min(mmm, lst[i] - 'a');
	}
	if(s <= l){
		int i;
		for(i = s-1; i>=0; i--){
			if(lst[i] - 'a' == mm)
				ans[i] = 'a' + mmm;
			else{
				for(int j = lst[i] - 'a' + 1; ; j++){
					if(vis[j]){
						ans[i] = 'a' + j;
						i--;
						break;
					}
				}
				break;
			}
		}
		for(;i>=0; i--)
			ans[i] = lst[i];
	}
	else{
		strcpy(ans, lst);
		for(int i = l; i<s; i++)
			ans[i] = 'a' + mmm;
	}
	printf("%s\n", ans);
	return 0;
}