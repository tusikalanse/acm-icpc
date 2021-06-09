#include <bits/stdc++.h>
using namespace std;

int n, m, t;
string a, tmp, b;
map<string, int> mp;
int f[210][210], cnt;

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> a >> tmp >> tmp >> tmp >> b;
		if(mp.count(a) == 0) 
			mp[a] = ++cnt;
		if(mp.count(b) == 0)
			mp[b] = ++cnt;
		f[mp[a]][mp[b]] = 1;
		f[mp[b]][mp[a]] = -1;
	}
	t = mp.size();
	for(int k = 1; k <= t; ++k) {
		for(int i = 1; i <= t; ++i) {
			for(int j = 1; j <= t; ++j) {
				if(f[i][k] * f[k][j] == 0) continue;
				if(f[i][k] != f[k][j]) continue;
				assert(f[i][j] == 0 || f[i][j] == f[i][k]);
				f[i][j] = f[i][k];
			}
		}
	}
	for(int i = 1; i <= m; ++i) {
		cin >> a >> tmp >> tmp >> tmp >> b;
		if(mp.count(a) == 0 || mp.count(b) == 0) {
			cout << "Pants on Fire" << endl;
			continue;
		}
		int x = mp[a], y = mp[b];
		if(f[x][y] == 1) {
			cout << "Fact" << endl;
		}
		else if(f[x][y] == -1) {
			cout << "Alternative Fact" << endl;
		}
		else {
			cout << "Pants on Fire" << endl;
		}
	}
	return 0;
}