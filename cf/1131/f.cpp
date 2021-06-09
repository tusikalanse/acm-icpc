#include <bits/stdc++.h>
using namespace std;

const int N = 150010;

int fa[N], n, x, y;
vector<int> v[N];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		fa[i] = i;
		v[i].push_back(i);
	}
	for(int i = 1; i < n; ++i) {
		scanf("%d%d", &x, &y);
		int fx = v[find(x)].size(), fy = v[find(y)].size();
		if(fx > fy) {
			for(int it: v[find(y)])
				v[find(x)].push_back(it);
			fa[find(y)] = find(x);
		}
		else {
			for(int it: v[find(x)])
				v[find(y)].push_back(it);
			fa[find(x)] = find(y);
		}
	}
	int f = find(1);
	for(int i = 0; i < n; ++i) {
		printf("%d%c", v[f][i], " \n"[i == n - 1]);
	}
	return 0;
}