#include <bits/stdc++.h>
using namespace std;

int T, n;
char s[110];

bool judge(char a, char b) {
	if(a == b) return 1;
	if(a == b - 2 || b == a - 2) return 1;
	return 0;
}

int main() {
	cin >> T;
	while(T--) {
		cin >> n >> s;
		bool flag = true;
		for(int i = 0; i < n / 2; ++i) {
			flag &= judge(s[i], s[n - 1 - i]);
		}
		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}



	return 0;
}