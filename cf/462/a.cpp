#include <bits/stdc++.h>
using namespace std;

long long a[60], b[60], mp[60][60], s[60];


int main(){
	int n, m;
	long long Max;
	scanf("%d %d", &n, &m);
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(mp, 0, sizeof(mp));
	memset(s, 0, sizeof(s));
	for(int i = 0; i<n; i++){
		scanf("%lld", &a[i]);
	}
	for(int i = 0; i<m; i++){
		scanf("%lld", &b[i]);
	}
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++)
			mp[i][j] = a[i]*b[j];
	}
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++)
			if(j == 0) Max = mp[i][j];
			else Max = max(Max, mp[i][j]);
		s[i] = Max;
	}
	sort(s, s+n);
	printf("%lld\n", s[n-2]);

	return 0;
}