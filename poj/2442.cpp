#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

struct node {
	int *a, *b;
	int i, j;
	bool flag;
	node(int *x, int *y, int _i, int _j, bool _f) : a(x), b(y), i(_i), j(_j), flag(_f) {}
	int getval() const {
		return a[i] + b[j];
	}
	bool operator<(const node &rhs) const {
		return getval() > rhs.getval();
	}
};

int lis[2][2010], arr[110][2010];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		priority_queue<node> Q;
		int n, m, now = 0;
		scanf("%d %d", &m, &n); 
		for(int i = 0; i < m; ++i)
			for(int j = 0; j < n; ++j)
				scanf("%d", &arr[i][j]);
		if(m == 1) {
			sort(arr[0], arr[0] + n);
			for(int i = 0; i < n; ++i)
				printf("%d%c", arr[0][i], " \n"[i == n - 1]);
			continue;
		}
		for(int i = 0; i < m; ++i)
			sort(arr[i], arr[i] + n);
		Q.push(node(arr[0], arr[1], 0, 0, false));
		for(int i = 0; i < n; ++i) {
			node u = Q.top();
			Q.pop();
			lis[now][i] = u.getval();
			Q.push(node(arr[0], arr[1], u.i, u.j + 1, true));
			if(u.flag == false)
				Q.push(node(arr[0], arr[1], u.i + 1, u.j, false));
		}
		for(int i = 2; i < m; ++i) {
			now ^= 1;
			while(!Q.empty()) Q.pop();
			Q.push(node(arr[i], lis[now ^ 1], 0, 0, false));
			for(int j = 0; j < n; ++j) {
				node u = Q.top();
				Q.pop();
				lis[now][j] = u.getval();
				Q.push(node(arr[i], lis[now ^ 1], u.i, u.j + 1, true));
				if(u.flag == false)
					Q.push(node(arr[i], lis[now ^ 1], u.i + 1, u.j, false));
			}
		}
		for(int i = 0; i < n; ++i)
			printf("%d%c", lis[now][i], " \n"[i == n - 1]);
	}
	return 0;
}