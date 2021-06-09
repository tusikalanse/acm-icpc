#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int arr[30010], opt[30010];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &arr[i]);
	for(int i = 1; i <= m; ++i)
		scanf("%d", &opt[i]);
	priority_queue<int, vector<int>, greater<int> > tobe;
	priority_queue<int> used;
	for(int i = 1; i <= opt[1]; ++i)
		tobe.push(arr[i]);
	printf("%d\n", tobe.top());
	used.push(tobe.top());
	tobe.pop();
	for(int i = 2; i <= m; ++i) {
		for(int j = opt[i - 1] + 1; j <= opt[i]; ++j) {
			if(arr[j] > used.top())
				tobe.push(arr[j]);
			else {
				tobe.push(used.top());
				used.pop();
				used.push(arr[j]);
			}
		}
		printf("%d\n", tobe.top());
		used.push(tobe.top());
		tobe.pop();
	}
	return 0;
}