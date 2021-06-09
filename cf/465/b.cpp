#include <bits/stdc++.h>
using namespace std;

char lst[100006];

int main(int argc, char const *argv[])
{
	int n, ans = 0, x = 0, y = 0, flag = 0;
	scanf("%d %s", &n, lst);
	for(int i = 0; i<n; i++){
		if(lst[i] == 'U'){
			y++;
			if(x-y){
				if(flag*(x-y) < 0) ans++;
				if(x-y<0) flag = -1;
				else flag = 1;
			}
		}
		else{
			x++;
			if(x-y){
				if(flag*(x-y) < 0) ans++;
				if(x-y<0) flag = -1;
				else flag = 1;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}