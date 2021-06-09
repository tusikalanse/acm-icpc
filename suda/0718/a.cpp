#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <cstring>
#include <vector>
using namespace std;

const int KIND = 26;
const int MAXN = 5000010;

vector<string> s;
map<string, int> vis;
string tmp;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string ss;
	int n = 0;
	while(cin >> ss) {
		s.push_back(ss);
		vis[ss] = 1;
		n++;
	}
	tmp.clear();
	for(int i = 0; i < n; ++i) {
		tmp.clear();
		for(int j = 0; j < s[i].size(); ++j) {
			tmp += s[i][j];
			if(vis[tmp] && vis[s[i].substr(j + 1)]) {
				cout << s[i] << endl;
				break;
			}
		}
	}
	return 0;
}