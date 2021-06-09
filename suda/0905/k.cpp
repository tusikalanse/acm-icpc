#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;


long long hell(long long i) {
	return sqrt(3LL * i * i * (i * i - 4) / 16 + 0.5);
}

int main() {
	vector<long long> ans;
	vector<long long> area;
	for(int i = 1; i <= 10000; ++i) {
		long long t = 1LL * i * (3 * i + 2);
		long long frac = sqrt(t + 0.5);
		if(frac * frac == t) {
			ans.push_back(6 * i + 2);
			area.push_back(hell(6 * i + 2));
		}
	}	
	for(int i = 0; i < ans.size(); ++i)
		cout << ans[i] << " ";
	cout << endl;
	ans.clear();
	for(int i = 0; i <= 10000; ++i) {
		long long t = 1LL * (i + 1) * (3 * i + 1);
		long long frac = sqrt(t + 0.5);
		if(frac * frac == t) {
			ans.push_back(6 * i + 4);
			area.push_back(hell(6 * i + 4));
		}
	}	
	for(int i = 0; i < ans.size(); ++i)
		cout << ans[i] << " ";
	cout << endl;
	sort(area.begin(), area.end());
	for(int i = 0; i < area.size(); ++i)
		cout << area[i] << " ";
	cout << endl;	
	return 0;
}