#include <bits/stdc++.h>
using namespace std;

string s, t;
int n, ans = 1, tmp = 1;

int main() {
	cin >> s;
	s = s + s;
	t = s;
	reverse(t.begin(), t.end());
	n = s.size();
	n /= 2;
	for(int i = 1; i < n * 2; ++i) {
		if(s[i] != s[i - 1]) {
			tmp++;
			ans = max(ans, tmp);
			if(ans == n) {
				printf("%d\n", n);
				return 0;
			}
		}
		else
			tmp = 1;
	}
	tmp = 1;
	for(int i = 1; i < n * 2; ++i) {
		if(t[i] != t[i - 1]) {
			tmp++;
			ans = max(ans, tmp);
			if(ans == n) {
				printf("%d\n", n);
				return 0;
			}
		}
		else
			tmp = 1;
	}
	printf("%d\n", ans);
	return 0;
}