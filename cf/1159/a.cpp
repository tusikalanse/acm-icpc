#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, mn = 0, ls = 0;
	string s;
	cin >> n >> s;
	for(int i = 0; i < n; ++i) {
		if(s[i] == '-')
			ls--;
		else
			ls++;
		mn = min(mn, ls);
	}
	cout << ls - mn << endl;
	return 0;
}