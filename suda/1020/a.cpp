#include <bits/stdc++.h>
using namespace std;

int vis[505][5005];

struct node {
	int d, s;
	string str;
};

int d, s;

void bfs() {
	queue<node> q;
	q.push({0, 0, ""});
	vis[0][0] = 1;
	while(!q.empty()) {
		node u = q.front();
		q.pop();
		if(u.s > s) continue;
		if(u.d == 0 && u.s == s) {
			cout << u.str << endl;
			return;
		}
		for(int i = 0; i <= 9; ++i) {
			int fd = (u.d * 10 + i) % d;
			int fs = u.s + i;
			if(!vis[fd][fs]) {
				vis[fd][fs] = 1;
				q.push({fd, fs, u.str + (char)(i + '0')});
			}
		}
	}
	cout << "-1" << endl;
}

int main() {
	cin >> d >> s;
	bfs();
	return 0;
}