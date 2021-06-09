#include <bits/stdc++.h>
using namespace std;

struct p{
	int a, t, id;
	bool operator < (const p &rhs)const{
		return t<rhs.t;
	}
}problem[200005];

int n, T, cnt;

bool check(int num){
	int cnt = 0, time = T;
	for(int i = 0; i<n; i++){
		if(problem[i].a >= num) {
			time -= problem[i].t;
			if(time >= 0) cnt++;
			if(time <= 0) break;
		}
	}
	return cnt >= num ;
}


int main()
{
	int ans = 0;
	scanf("%d %d", &n, &T);
	for(int i = 0; i<n; i++){
		scanf("%d %d", &problem[i].a, &problem[i].t);
		problem[i].id = i+1;
	}
	sort(problem, problem+n);
	int l = 0, r = n+1, mid;
	while(l < r - 1){
		mid = (l+r) >> 1;
		if(check(mid)) {
			ans = mid;
			l = mid;
		}
		else r = mid;
	}
	printf("%d\n%d\n", ans, ans);
	int cnt = 0;
	for(int i = 0; i<n && cnt < ans; i++){
		if(problem[i].a >= ans)
			if(cnt++ == 0)
				printf("%d", problem[i].id);
			else
				printf(" %d", problem[i].id);
	}
	puts("");
	return 0;
}