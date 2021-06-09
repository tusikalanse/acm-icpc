#include <bits/stdc++.h>
using namespace std;

vector< vector<string> > v(26);
string s;

int main(){
	int n, ans = 0;
	cin >> s;
	n = s.size();
	s = s + s;
	for(int i = 0; i < n; i++){
		string s1 = s.substr(i, n);
		v[s1[0] - 'a'].push_back(s1);
	}
	for(int i = 0; i<26; i++){
		int mx = 0;
		for(int j = 1; j < n && v[i].size(); j++){
			int cnt[26] = {};
			for(int k = 0; k < v[i].size(); k++){
				char c = v[i][k][j];
				cnt[c - 'a']++;
			}
			int cur = 0;
			for(int k = 0; k < 26; k++){
				if(cnt[k] == 1)
					cur++;
			}
			mx = max(mx, cur);
		}
		ans += mx;
	}
	printf("%.15lf\n", ans/(double)n);
	return 0;
}