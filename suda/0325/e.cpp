#include <bits/stdc++.h>
using namespace std;

int a1[105], a2[105], b[105], s1[105], s2[105];

int main() {
	int ans = 0, n, mmin, id;
	scanf("%d", &n);
	for(int i = 2; i <= n; i++) {
		scanf("%d", &a1[i]);
	}
	for(int i = 1; i < n; i++) {
		scanf("%d", &a2[i]);
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
	}
	for(int i = 2; i <= n; i++) {
		s1[i] = s1[i-1] + a1[i];
	}
	for(int i = n-1; i > 0; i--) {
		s2[i] = s2[i+1] + a2[i];
	}
	mmin = 0x3f3f3f3f;
	for(int i = 1; i <= n; i++) {
		if(mmin > s1[i]+s2[i]+b[i]){
			mmin = s1[i]+s2[i]+b[i];
			id = i;
		}
	}
	ans += mmin;
	mmin = 0x3f3f3f3f;
	b[id] = 0x3f3f3f3f;
	for(int i = 1; i <= n; i++) {
		if(mmin > s1[i]+s2[i]+b[i]){
			mmin = s1[i]+s2[i]+b[i];
		}
	}
	ans += mmin;
	printf("%d\n", ans);
	return 0;
}