#include <bits/stdc++.h>
using namespace std;

int n;

vector< pair<int, int> > fac;
set<int> p;
vector<long long> ans;

void foo(int n) {
	int i = 2;
	while(i * i <= n) {
		if(n % i == 0) {
			pair<int, int> t(i, 0);
			while(n % i == 0) {
				n /= i;
				t.second++;
			}
			fac.push_back(t);
		}
		i++;
	}
	if(n != 1) {
		fac.push_back(make_pair(n, 1));
	}
}

void gao(int now, int pos) {
	p.insert(now);
	if(pos + 1 == fac.size()) 
		return;
	gao(now, pos + 1);
	for(int i = 0; i < fac[pos + 1].second; ++i) {
		now *= fac[pos + 1].first;
		gao(now, pos + 1);
	}
}

int main() {
	scanf("%d", &n);
	foo(n);
	gao(1, -1);
	for(auto it = p.begin(); it != p.end(); it++) {
		if(*it != 1) {
			long long tmp = 0, i = 0;
			tmp = n / *it;
			tmp += *it * 1LL * tmp * (tmp - 1) / 2;
			ans.push_back(tmp);
		}
	}
	ans.push_back(1LL * n * (n + 1) / 2);
	sort(ans.begin(), ans.end());
	printf("%lld", ans[0]);
	for(int i = 1; i < ans.size(); ++i)
		printf(" %lld", ans[i]);
	puts("");
	return 0;
}