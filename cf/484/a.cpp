#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, flag = 1;
	string s;
	cin >> n >> s;
	for(int i = 0; i < n - 1; ++i) {
		if(s[i] == '1' && s[i + 1] == '1')
			flag = 0;
	}
	for(int i = 1; i < n - 1; ++i) {
		if(s[i - 1] == '0' && s[i] == '0' && s[i + 1] == '0')
			flag = 0;
	}
	if(n == 1 && s[0] == '0')
		flag = 0;
	if(n >= 2 && s[0] == '0' && s[1] == '0')
		flag = 0;
	if(n >= 2 && s[n - 1] == '0' && s[n - 2] == '0')
		flag = 0;
	puts(flag ? "Yes" : "No");

	return 0;
}