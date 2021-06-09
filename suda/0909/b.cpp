#include <bits/stdc++.h>
using namespace std;

int norm200(int a) {
	return a = min(200, max(a, -200));
}

int norm100(int a) {
	return a = min(100, max(a, -100));
}

int a[1010], b[1010], c[1010];
int n, m, k, l;
map<int, int> state[2];

int main() {
	scanf("%d%d%d%d", &n, &m, &k, &l);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
		a[i] = norm200(a[i]); b[i] = norm200(b[i]);
	}
	int t = 0;
	for(int i = -100; i <= l; ++i)
		state[t][i] = -1;
	for(int i = l + 1; i < k; ++i)
		state[t][i] = 0;
	for(int i = k; i <= 100; ++i)
		state[t][i] = 1;
	for(int i = n; i >= 1; --i) {
		t ^= 1;
		for(int j = -100; j <= 100; ++j) {
			state[t][j] = 2;
		}
		if(i & 1) {
			for(int j = -100; j <= 100; ++j) {
				if(a[i] != 0) {
					if(state[t][j] == 2) 
						state[t][j] = state[t ^ 1][norm100(j + a[i])];
					else if(state[t ^ 1][norm100(j + a[i])] != 2)
						state[t][j] = max(state[t][j], state[t ^ 1][norm100(j + a[i])]);
				}
				if(b[i] != 0) {
					if(state[t][j] == 2)
						state[t][j] = state[t ^ 1][norm100(j - b[i])];
					else if(state[t ^ 1][norm100(j - b[i])] != 2)
						state[t][j] = max(state[t][j], state[t ^ 1][norm100(j - b[i])]);
				}
				if(c[i] != 0) {
 					if(state[t][j] == 2)
 						state[t][j] = state[t ^ 1][-j];
 					else if(state[t ^ 1][-j] != 2)
 						state[t][j] = max(state[t][j], state[t ^ 1][-j]);
				}
			}
		}		
		else {
			for(int j = -100; j <= 100; ++j) {
				if(a[i] != 0) {
					if(state[t][j] == 2) 
						state[t][j] = state[t ^ 1][norm100(j + a[i])];
					else if(state[t ^ 1][norm100(j + a[i])] != 2)
						state[t][j] = min(state[t][j], state[t ^ 1][norm100(j + a[i])]);
				}
				if(b[i] != 0) {
					if(state[t][j] == 2)
						state[t][j] = state[t ^ 1][norm100(j - b[i])];
					else if(state[t ^ 1][norm100(j - b[i])] != 2)
						state[t][j] = min(state[t][j], state[t ^ 1][norm100(j - b[i])]);
				}
				if(c[i] != 0) {
 					if(state[t][j] == 2)
 						state[t][j] = state[t ^ 1][-j];
 					else if(state[t ^ 1][-j] != 2)
 						state[t][j] = min(state[t][j], state[t ^ 1][-j]);
				}
			}
		}
	}
	if(state[t][m] == 1)
		puts("Good Ending");
	else if(state[t][m] == 0)
		puts("Normal Ending");
	else if(state[t][m] == -1)
		puts("Bad Ending");
	return 0;
}