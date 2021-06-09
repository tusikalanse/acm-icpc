#include <bits/stdc++.h>
using namespace std;

char s[100010];

int main() {
	vector<int> id[26];
	vector<int> ans[26];
	scanf("%s", s);
	int l = strlen(s);
	for(int i = 0; i < 26; i++)
		id[i].push_back(-1);
	for(int i = 0; i < l; i++) {
		id[s[i] - 'a'].push_back(i);
	}
	for(int i = 0; i < 26; i++)
		id[i].push_back(l);
	int mmin = 1e7;
	for(int i = 0; i < 26; i++) {
		for(int j = 0; j < id[i].size() - 1; j++)
			ans[i].push_back(id[i][j + 1] - id[i][j]);
		sort(ans[i].begin(), ans[i].end());
		mmin = min(mmin, *(ans[i].rbegin()));
	}
	cout << mmin << endl;
	return 0;
}