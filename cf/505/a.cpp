#include <bits/stdc++.h>
using namespace std;

int n, vis[300];

string s;

int main() {
	cin >> n >> s;
	if(n > 26 || n == 1) {
		cout << "Yes" << endl;
		return 0;
	}
	for(int i = 0; i < n; ++i) {
		if(vis[s[i]]) {
			cout << "Yes" << endl;
			return 0;
		}
		vis[s[i]] = 1;
	}
	cout << "No" << endl;
	return 0;
}