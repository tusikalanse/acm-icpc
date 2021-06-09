#include <bits/stdc++.h>
using namespace std;

char s[100010], b[10][12];
int n, len, a[10];

bool check(int l, int r) {
	for(int i = 0; i < n; ++i) {
		bool flag = 1;
		if(r - a[i] + 1 < l)
			continue;
		for(int j = 0; j < a[i]; ++j) 
			if(s[r - a[i] + j + 1] != b[i][j]) {
				flag = 0;
				break;
			}
		if(flag)
			return 0;
	}
	return 1;
}


int main() {
	scanf("%s %d", s, &n);
	len = strlen(s);
	for(int i = 0; i < n; ++i) {
		scanf("%s", b[i]);
		a[i] = strlen(b[i]);
	}
	int l = 0, r = 0, ans = 0, id = 0;
	while(l < len && r < len) {
		if(check(l, r)) {
			if(r - l + 1 > ans) {
				id = l;
				ans = r - l + 1;
			}
			r++;
		}
		else 
			l++;
	}
	printf("%d %d\n", ans, id);
	return 0;
}