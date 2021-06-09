#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
	int a[4][4] =  {0};
	char ch;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			cin >> ch;
			if(ch == '+') {
				for(int t = 0; t < 4; t++) {
					a[t][j] ^= 1;
					a[i][t] ^= 1;
				}
				a[i][j] ^= 1;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) 
			ans += a[i][j];
	}
	printf("%d\n", ans);
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			if(a[i][j])
				printf("%d %d\n", i+1, j+1);
		}
	}
	return 0;
}