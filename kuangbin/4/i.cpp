#include <cstdio>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

double mp[35][35];
int n;
int floyd(){
	for(int k = 0; k<n; k++){
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				mp[i][j] = max(mp[i][j], mp[i][k] * mp[k][j]);
			}
		}
	}
	for(int i = 0; i<n; i++)
		if(mp[i][i] > 1)
			return 1;
	return 0;
}

int main(){
	int m, a, b, cnt = 0;
	string s, s1, s2;
	double rate;
	while(~scanf("%d", &n) && n){
		memset(mp, 0, sizeof(mp));
		map<string, int> name;
		for(int i = 0; i<n; i++){
			cin >> s;
			name[s] = i;
			mp[i][i] = 1;
		}
		scanf("%d", &m);
		while(m--){
			cin >> s1 >> rate >> s2;
			mp[name[s1]][name[s2]] = rate;
		}
		printf("Case %d: ", ++cnt);
		puts(floyd()?"Yes":"No");
	}
	return 0;
}