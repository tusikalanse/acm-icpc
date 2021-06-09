#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int a[N][N], d[N][N], s[N][N], s2[N][N], mx, mx2, n, m, vis[N][N];

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j)
			scanf("%1d", &a[i][j]);
	}
	for(int j = 1; j <= m; ++j) {
		for(int i = 1; i <= n; ++i) {
			if(a[i][j] == 0)
				d[i][j] = 0;
			else
				d[i][j] = d[i - 1][j] + 1;
		}
	}
	for(int i = 1; i <= n; ++i) {
		stack<int> st;
		while(!st.empty()) st.pop();
		d[i][m + 1] = -1;
		st.push(m + 1);
		for(int j = m; j; --j) {
			while(d[i][st.top()] >= d[i][j]) st.pop();
			s[i][j] = st.top();
			st.push(j);
		}
	}
	for(int i = 1; i <= n; ++i) {
		stack<int> st;
		while(!st.empty()) st.pop();
		d[i][0] = -1;
		st.push(0);
		for(int j = 1; j <= m; ++j) {
			while(d[i][st.top()] >= d[i][j]) st.pop();
			s2[i][j] = st.top();
			st.push(j);
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(a[i][j] == 0) continue;
			int r = s[i][j], l = s2[i][j];
			if(vis[l][r] == i) continue;
			vis[l][r] = i;
			mx2 = max(mx2, d[i][j] * (r - l - 1));
			if(mx2 > mx) swap(mx2, mx);
			mx2 = max(mx2, d[i][j] * (r - l - 2));
			if(mx2 > mx) swap(mx2, mx);
			mx2 = max(mx2, (d[i][j] - 1) * (r - l - 1));
			if(mx2 > mx) swap(mx2, mx);
		}
	}
	printf("%d\n", mx2);
	return 0;
}