#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int n, k;
long long ans, tmp;
int lenth, beauty;

vector<int> BB[1000010];

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d", &lenth, &beauty);
		BB[beauty].push_back(lenth);
	}
	multiset<int> st;
	for(int mx = 1000000; mx >= 1; --mx) {
		for(int i = 0; i < BB[mx].size(); ++i) {
			st.insert(BB[mx][i]);
			tmp += BB[mx][i];
		}
		while(st.size() > k) {
			tmp -= *st.begin();
			st.erase(st.begin());
		}
		ans = max(ans, tmp * mx);
	}
	printf("%lld\n", ans);
	return 0;
}