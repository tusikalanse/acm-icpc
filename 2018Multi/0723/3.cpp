#include <bits/stdc++.h>
using namespace std;

priority_queue< pair<pair<int, int>, int> > p;
int _,n,x,y;

int main() {
	for(scanf("%d", &_);_;_--) {
		scanf("%d", &n);
		for(int i = 1; i <= 3*n;++i) {
			scanf("%d%d", &x,&y);
			p.push(make_pair(make_pair(x,y),i));
		}
		for(int i = 1; i<=3*n;++i) {
			int x=p.top().second;
			p.pop();
			printf("%d%c", x," \n"[i%3 == 0]);
		}
	}
	return 0;
}