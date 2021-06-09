#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct Mouse {
	int weight, speed, id;
	bool operator < (const Mouse &rhs) const {
		return weight < rhs.weight;
	}
}mice[1005];

int dp[1005], pre[1005];

void output(int x) {
	if(x == -1) 
		return;
	output(pre[x]);
	printf("%d\n", mice[x].id);
}

int main() {
	int n = 1;
	while(~scanf("%d %d", &mice[n].weight, &mice[n].speed)) {
		mice[n].id = n;
		n++;
	}
	sort(mice + 1, mice + n);
	for(int i = 1; i < n; i++) {
		pre[i] = -1;
		dp[i] = 1;
	}
	for(int i = 2; i < n; i++) {
		for(int j = 1; j < i; j++) {
			if(mice[j].weight < mice[i].weight && mice[j].speed > mice[i].speed) {
				if(dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					pre[i] = j;
				}
			}
		}
	}
	int ans = 0, maxid;
	for(int i = 1; i < n; i++) {
		if(ans < dp[i]) {
			ans = dp[i];
			maxid = i;
		}
	}
	printf("%d\n", ans);
	output(maxid);
	return 0;
}