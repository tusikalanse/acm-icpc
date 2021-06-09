#include <bits/stdc++.h>
using namespace std;

set<string> ans;
char s[10010];
int vis[10010][4], n;

bool dfs(int pos, const string &ss) {
	bool res = 0, val;
	if(vis[pos][ss.size()] != -1)
		return vis[pos][ss.size()];
	if(pos == n)
		return vis[pos][ss.size()] = 1;
	if(pos + 1 >= n)
		return vis[pos][ss.size()] = 0;
	string t = "";
	t += s[pos];
	t += s[pos + 1];
	if(t != ss) {
		if(val = dfs(pos + 2, t))
			ans.insert(t);
		res |= val;
	}
	if(pos + 2 < n) {
		t += s[pos + 2];
		if(t != ss) {
			if(val = dfs(pos + 3, t))
				ans.insert(t);
			res |= val;
		}
	}
	return vis[pos][ss.size()] = res;
}

int main() {
	memset(vis, -1, sizeof(vis));
	scanf("%s", s);
	n = strlen(s);
	for(int i = 5; i + 1 < n; ++i) {
		string t;
		t += s[i];
		t += s[i + 1];
		if(dfs(i + 2, t))
			ans.insert(t);
		if(i + 2 < n) {
			t += s[i + 2];
			if(dfs(i + 3, t))
				ans.insert(t);
		}
	}
	cout << ans.size() << endl;
	for(auto it: ans)
		cout << it << endl;
	return 0;
}