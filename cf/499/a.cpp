#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
	LL n, k, p = 0, tmp = -2;
	LL cnt = 0;
	string a;
	cin >> n >> k >> a;
	LL lis[50] = {0};
	if(k > 13) {
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < a.size(); ++i)
		lis[i] = a[i] - 'a' + 1;
	sort(lis, lis + a.size());
	lis[a.size()] = 5000;
	for(int i = 0; i < k; ++i) {
		p = lower_bound(lis + p, lis + a.size(), tmp + 2) - lis;
	//	cout << lis[p] << endl;
		cnt += lis[p];
		tmp = lis[p];
	}
	if(cnt >= 5000)
		cout << -1 << endl;
	else
		cout << cnt << endl;
	return 0;
}