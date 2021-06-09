#include <bits/stdc++.h>
using namespace std;

const int N = 5010;
int n, w, ans, dis[N];

vector<int> e[N];

struct node {
	int eyes, horns;
	bool operator<(const node &rhs) const {
		if(horns == rhs.horns)
			return eyes < rhs.eyes;
		return horns < rhs.horns;
	}
}a[N];

int main() {
	scanf("%d%d", &n, &w);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i].horns);
		a[i].eyes = i;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i) {
		for(int j = i + 1; j <= n; ++j) {
			if(a[i].horns < a[j].horns && abs(a[i].eyes - a[j].eyes) <= w) {
				e[i].push_back(j);
			}
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int &j: e[i])
			dis[j] = max(dis[j], dis[i] + 1);
		ans = max(dis[i], ans);
	}
	printf("%d\n", ans);
	return 0;
}