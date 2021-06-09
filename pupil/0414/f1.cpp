#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, k = 0;
	int a[110];
	cin >> n >> m;
	for(int i = 1; i <= n; i++) 
		scanf("%d", &a[i]);
	vector<int> temp;
	vector<int> ans;
	for(int i = 0; i <= m; i++) {
		temp.push_back(0);
		ans.push_back(0);
	}
	for(int i = 1; i <= m; i++) {
		scanf("%d", &ans[i]);
		k += ans[i];
	}
	for(int i = 1; i <= k; i++)
		temp[a[i]]++;
	if(temp == ans) {
		puts("YES");
		return 0;
	}
	for(int i = k + 1; i <= n; i++) {
		temp[a[i]]++;
		temp[a[i-k]]--;
		if(temp == ans) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}