#include <bits/stdc++.h>
using namespace std;

map<string, int> vis;

string s[100010];
bool cmp(const string &a, const string &b) {
	return a.size() < b.size();
}

int main() {
	int n, ans = 0;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
		vis[s[i]] = 1;
	}
	sort(s, s + n, cmp);
	for(int i = 0; i < n; ++i) {
		vis[s[i]] = 0;
		ans += s[i].size();
		for(int j = 0; j < s[i].size(); ++j) {
			if(!vis[s[i].substr(0, j + 1)]) {
				ans -= s[i].size() - 1 - j;
				vis[s[i].substr(0, j + 1)] = 1;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}