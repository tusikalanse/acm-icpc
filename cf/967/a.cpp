#include <bits/stdc++.h>
using namespace std;

int hou[110];

int main() {
	int n, s, h, m;
	cin >> n >> s;
	s++;
	for(int i = 0; i < n; ++i) {
		scanf("%d %d", &h, &m);
		hou[i] = h * 60 + m;
	}
	sort(hou, hou + n);
	int ans;
	if(s <= hou[0]) {
		ans = 0;
	}
	else {
		for(int i = 0; i < n; ++i) {
			ans = hou[i] + s;
			if(i != n-1) {
				if(ans + s <= hou[i+1]) {
					break;
				}
			}
		}
	}
	printf("%d %d\n", ans/60, ans%60);
	return 0;
}