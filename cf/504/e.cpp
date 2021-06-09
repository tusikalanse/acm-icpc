#include <bits/stdc++.h>
using namespace std;

struct node {
	int r, c;
	bool operator<(const node &rhs) const {
		if(r == rhs.r)
			return c < rhs.c;
		return r < rhs.r;
	}
	bool operator==(const node &rhs) const {
		return r == rhs.r && c == rhs.c;
	}
}ans[550];

bool vis[550][550][3];

string YES = "YES";
int cnt = 0, n;


bool query(int x, int y, int f) {
	vis[x][y][f] = 1;
	if(f == 0)
		vis[x][y][1] = vis[x][y][2] = 1;
	string flag;
	if(f == 0) {
		cout << "? 1 1 " << x << " " << y << endl;
		cin >> flag;
		if(flag != YES)
			return false;
		cout << "? " << x << " " << y << " " << n << " " << n << endl;
		cin >> flag;
		return flag == YES; 
	}
	if(f == 1) {
		cout << "? " << x << " " << y << " " << n << " " << n << endl;
		cin >> flag;
		return flag == YES;	
	}
	if(f == 2) {
		cout << "? 1 1 " << x << " " << y << endl;
		cin >> flag;
		return flag == YES;
	}
}

void solve(int x1, int y1, int x2, int y2, int f) {
	//cout << x1 << y1 << x2 << y2 << endl;
	if(x1 == x2) {
		for(int i = y1; i <= y2; ++i)
			ans[cnt++] = {x1, i};
		return;
	}
	if(y1 == y2) {
		for(int i = x1; i <= x2; ++i)
			ans[cnt++] = {i, y1};
		return;
	}
	int x = y2 - y1 >= x2 - x1 ? x2 : x1 + y2 - y1;
	int y = ((x1 + y1 + x2 + y2) >> 1) - x;
	for(;x1 <= x && x <= x2 && y1 <= y && y <= y2;) {
		if(!vis[x][y][f] && query(x, y, f)) {
			ans[cnt++] = {x, y};
			if(f == 0) {
				solve(x, y, n, n, 2);
				solve(1, 1, x, y, 1);
			}
			else if(f == 1) {
				solve(x, y, x2, y2, 1);
				solve(1, 1, x, y, 1);
			}
			else {
				solve(x, y, n, n, 2);
				solve(x1, y1, x, y, 2);
			}
			return;
		}
		x--, y++;
	}
}

int main() {
	cin >> n;
	ans[cnt++] = {1, 1};
	ans[cnt++] = {n, n};
	solve(1, 1, n, n, 0);
	sort(ans, ans + cnt);
	cnt = unique(ans, ans + cnt) - ans;
	//for(int i = 0; i < cnt; ++i) 
	//	cout << ans[i].r << " " << ans[i].c << endl;
	cout << "! ";
	for(int i = 1; i < cnt; ++i) {
		if(ans[i].r == ans[i - 1].r)
			cout << "R";
		else
			cout << "D";
	}
	cout << endl;
	return 0;
}