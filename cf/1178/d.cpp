#include <bits/stdc++.h>
using namespace std;

int n, x;

bool isp(int x) {
	for(int i = 2; i * i <= x; ++i) {
		if(x % i == 0)
			return false;
	}
	return true;
}

vector<pair<int, int>> ans;


int main() {
	cin >> n;
	x = n;
	while(!isp(x)) x++;
	for(int i = 0; i < n; ++i) {
		ans.push_back({i, (i + 1) % n});
		x--;
	}
	for(int i = 0; i < n / 2; ++i) {
		if(x == 0) break;
		ans.push_back({i, i + n / 2});
		x--;
	}
	printf("%d\n", (int)ans.size());
	for(auto f: ans) {
		printf("%d %d\n", f.first + 1, 1 + f.second);
	}
	return 0;
}