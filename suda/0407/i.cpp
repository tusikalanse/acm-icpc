#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;


int a[100006], b[100005];
long long d[3];

int main() {
	int n;
	long long ans[3] = {0, 0, 0};
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) 
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		d[i%3] += b[i];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 3; j++) {
			ans[(i+j)%3] += a[i]*d[j];
		}
	}
	printf("%lld %lld %lld\n", ans[0], ans[1], ans[2]);
	return 0;
}