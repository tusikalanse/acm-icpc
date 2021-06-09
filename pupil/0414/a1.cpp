#include <bits/stdc++.h>
using namespace std;

char mp[12][12], mp2[12][12];

int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		scanf("%s", &mp[i][1]);
	for(int i = 1; i <= n; i++)
		scanf("%s", &mp2[i][1]);
	int flag = 0, f = 1;
	for(int i = 1; i <= n; i++) {
		f = 1;
		for(int j = 1; j <= n; j++) {
			if(mp[i][j] != mp2[i][j]) {
				f = 0;
				break;
			}
		}
		if(f == 0) {
			break;
		}
	}
	flag |= f;
	for(int i = 1; i <= n; i++) {
		f = 1;
		for(int j = 1; j <= n; j++) {
			if(mp[i][j] != mp2[i][n+1-j]) {
				f = 0;
				break;
			}
		}
		if(f == 0) {
			break;
		}
	}
	flag |= f;
	for(int i = 1; i <= n; i++) {
		f = 1;
		for(int j = 1; j <= n; j++) {
			if(mp[i][j] != mp2[j][i]) {
				f = 0;
				break;
			}
		}
		if(f == 0) {
			break;
		}
	}
	flag |= f;
	for(int i = 1; i <= n; i++) {
		f = 1;
		for(int j = 1; j <= n; j++) {
			if(mp[i][j] != mp2[j][n+1-i]) {
				f = 0;
				break;
			}
		}
		if(f == 0) {
			break;
		}
	}
	flag |= f;
	for(int i = 1; i <= n; i++) {
		f = 1;
		for(int j = 1; j <= n; j++) {
			if(mp[i][j] != mp2[n+1-i][j]) {
				f = 0;
				break;
			}
		}
		if(f == 0) {
			break;
		}
	}
	flag |= f;
	for(int i = 1; i <= n; i++) {
		f = 1;
		for(int j = 1; j <= n; j++) {
			if(mp[i][j] != mp2[n+1-i][n+1-j]) {
				f = 0;
				break;
			}
		}
		if(f == 0) {
			break;
		}
	}
	flag |= f;
	for(int i = 1; i <= n; i++) {
		f = 1;
		for(int j = 1; j <= n; j++) {
			if(mp[i][j] != mp2[n+1-j][i]) {
				f = 0;
				break;
			}
		}
		if(f == 0) {
			break;
		}
	}
	flag |= f;
	for(int i = 1; i <= n; i++) {
		f = 1;
		for(int j = 1; j <= n; j++) {
			if(mp[i][j] != mp2[n+1-j][n+1-i]) {
				f = 0;
				break;
			}
		}
		if(f == 0) {
			break;
		}
	}
	flag |= f;
	puts(flag?"YES":"NO");
	return 0;
}