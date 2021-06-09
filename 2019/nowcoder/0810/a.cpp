#include <bits/stdc++.h>
using namespace std;

const int N = 3010;

char a[N][N];
int d[N][N], s[N][N], s2[N][N], n, m, vis[N][N], ans;
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%s", a[i] + 1);
	}
	for(int j = 1; j <= m; ++j) {
		for(int i = 1; i <= n; ++i) {
			if(a[i][j] == '0')
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
			s[i][j] = st.top() - 1;
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
			s2[i][j] = st.top() + 1;
			st.push(j);
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(a[i][j] == '0') continue;
			int r = s[i][j], l = s2[i][j];
			if(vis[l][r] == i) continue;
			if(vis[l][r] != i - 1 && vis[l][r]) ans++;
			vis[l][r] = i;
		}
	}
	for(int i = 1; i <= m; ++i) 
		for(int j = i; j <= m; ++j) 
			ans += vis[i][j] != 0;
	printf("%d\n", ans);
	return 0;
}