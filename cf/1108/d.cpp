#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, ans;
char s[N];

int main() {
	scanf("%d%s", &n, s);
	for(int i = 1; i + 1 < n; ++i) {
		if(s[i] != s[i - 1])
			continue;
		ans++;
		if(s[i - 1] == 'R') {
			if(s[i + 1] != 'G')
				s[i] = 'G';
			else
				s[i] = 'B';
		}
		if(s[i - 1] == 'G') {
			if(s[i + 1] != 'R')
				s[i] = 'R';
			else
				s[i] = 'B';
		}
		if(s[i - 1] == 'B') {
			if(s[i + 1] != 'G')
				s[i] = 'G';
			else
				s[i] = 'R';
		}
	}
	if(n != 1) {
		if(s[n - 1] == s[n - 2]) {
			ans++;
			if(s[n - 2] != 'R')
				s[n - 1] = 'R';
			else
				s[n - 1] = 'B';
		}
	}
	printf("%d\n%s\n", ans, s);
	return 0;
}