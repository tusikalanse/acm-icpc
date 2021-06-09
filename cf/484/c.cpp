#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int nxt[N << 1], pnt[N << 1], head[N], cnt = 0;

void add(int x, int y) {
	pnt[cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt++;
}

bool dfs(int u, int v, int &b) {
	bool ans = true;
	for(int i = head[u]; ~i; i = nxt[i])
		if(pnt[i] != v) {
			ans ^= dfs(pnt[i], u, b);
		}
	b += ans == false;
	return ans;
}


int main() {
	int n;
	cin >> n;
	if(n & 1) {
		cout << "-1" << endl;
		return 0;
	}
	int a, b;
	memset(head, -1, sizeof(head));
	while(--n) {
		cin >> a >> b;
		add(a, b);
		add(b, a);
	}
	int ans = 0;
	dfs(a, b, ans);
	dfs(b, a, ans);
	if(dfs(a, b, n) == false)
		ans--;
	cout << ans << endl;
	return 0;
}