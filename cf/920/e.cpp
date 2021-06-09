#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200006;

set<int> mp[MAXN], s;
vector<int> ans;

int dfs(int id){
	int res = 1;
	for(set<int>::iterator it = s.begin(); it != s.end();){
		if(mp[id].find(*it) == mp[id].end()){
			int x = *it;
			s.erase(x);
			res += dfs(x);
			it = s.lower_bound(x);
		}
		else it++;
	}
	return res;
}

int main(){
	int n, m, x, y, t;
	scanf("%d %d", &n, &m);
	for(int i = 1; i<=m; i++){
		scanf("%d %d", &x, &y);
		mp[x].insert(y);
		mp[y].insert(x);
	}
	for(int i = 1; i<=n; i++){
		s.insert(i);
	}
	while(!s.empty()){
		t = *s.begin();
		s.erase(t);
		ans.push_back(dfs(t));
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", (int)ans.size());
	for(vector<int>::iterator it = ans.begin(); it != ans.end(); it++){
		printf("%d ", *it);
	}
	puts("");
	return 0;
}
