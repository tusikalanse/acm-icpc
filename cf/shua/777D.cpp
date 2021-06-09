#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

string s[N];
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> s[i];
	for(int i = n - 1; i; --i) {
		string t = "";
		int flag = 0;
		for(int j = 0; j < s[i].size(); ++j) {
			if(flag == 0 && s[i][j] > s[i + 1][j])
				break;
			if(j == s[i + 1].size() && flag == 0)
				break;
			if(j < s[i + 1].size() && s[i][j] < s[i + 1][j])
				flag = 1;
			t += s[i][j];
		}
		s[i] = t;
	}
	for(int i = 1; i <= n; ++i)
		cout << s[i] << endl;
	return 0;
}