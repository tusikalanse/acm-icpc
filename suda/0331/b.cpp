#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int vis[100006];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	queue<int> q;
	vis[n] = 1;
	q.push(n);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		if(u == k){
			printf("%d\n", vis[u] - 1);
			return 0;
		}
		if(u > 0 && !vis[u-1]) {
			vis[u-1] = vis[u] + 1;
			q.push(u-1);
		}
		if(u < 100000 && !vis[u+1]) {
			vis[u+1] = vis[u] + 1;
			q.push(u+1);
		}
		if(2 * u <= 100000 && !vis[2*u]) {
			vis[2*u] = vis[u] + 1;
			q.push(2*u);
		}
	}
	return 0;
}