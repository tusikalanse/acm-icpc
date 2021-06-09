#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;
int main(){
	int n, m, k, ans = 0, t;
	char mp[MAXN][MAXN];
	scanf("%d %d %d", &m, &n, &k);
	getchar();
	for(int i = 0; i<m; i++){
		for(int j = 0; j<n; j++)
			mp[i][j] = getchar();
		getchar();
	}
	if(k!=1){
		for(int i = 0; i<m; i++){
			int j = 0;
			t = 0;
			while(j<n){
				while(j<n && mp[i][j] == '.')
					t++, j++;
				if(t >= k)
					ans += (t-k+1);
				t = 0;
				while(j<n && mp[i][j] == '*')
					j++;
			}
		}
		for(int j = 0; j<n; j++){
			int i = 0;
			t = 0;
			while(i<m){
				while(i<m && mp[i][j] == '.')
					t++, i++;
				if(t >= k)
					ans += (t-k+1);
				t = 0;
				while(i<m && mp[i][j] == '*')
					i++;
			}
		}
	}
	else{
		for(int i = 0; i<m; i++)
			for(int j = 0; j<n; j++)
				if(mp[i][j] == '.')
					ans++;
	}
	printf("%d\n", ans);
	return 0;
}