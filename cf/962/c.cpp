#include <bits/stdc++.h>
using namespace std;

struct node
{
	string s;
	int stp;
	bool judge() {
		int n = atoi(s.c_str());
		int t = sqrt(n);
		return t*t == n;
	}
}temp;


int main() {
	string s;
	cin >> s;
	queue<node> bfs;
	map<string, bool> vis;
	temp.stp = 0;
	temp.s = s;
	bfs.push(temp);
	vis[s] = true;
	while(!bfs.empty()) {
		node u = bfs.front();
		bfs.pop();
		if(u.judge()) {
			printf("%d\n", u.stp);
			return 0;
		}
		if(u.s.size() > 1) {
			if(u.s[1] != '0') {
				string str(u.s.begin() + 1, u.s.end());
				temp.s = str;
				temp.stp = u.stp + 1;
				if(!vis[str]) {
					vis[str] = true;
					bfs.push(temp);
				}
			}
			for(int i = 1; i < u.s.size(); i++) {
				string str = "";
				for(int j = 0; j < u.s.size(); j++) {
					if(j != i)
						str += u.s[j];
				}
				temp.s = str;
				temp.stp = u.stp + 1;
				if(!vis[str]) {
					vis[str] = true;
					bfs.push(temp);
				}
			}
		}
	}
	printf("-1\n");
	return 0;
}