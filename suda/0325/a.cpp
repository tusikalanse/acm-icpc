#include <bits/stdc++.h>
using namespace std;

char mp[100][100];
int a = 100, b = 100;
int main() {
	for(int i = 1; i <= 8; i++) {
		scanf("%s", &mp[i][1]);
	}
	for(int i = 1; i <= 8; i++) {
		for(int j = 1; j <= 8; j++) {
			if(mp[j][i] == 'B')
				break;
			else if(mp[j][i] == 'W'){
				a = min(a, j - 1);
				break;
			}
		}
	}
	for(int i = 1; i <= 8; i++) {
		for(int j = 8; j >= 1; j--) {
			if(mp[j][i] == 'W')
				break;
			else if(mp[j][i] == 'B'){
				b = min(b, 8 - j);
				break;
			}
		}
	}
	if(a <= b)
		puts("A");
	else
		puts("B");

	return 0;
}