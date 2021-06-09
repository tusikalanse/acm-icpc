#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;


int num[1000010];

int main() {
	int n, cas = 0, len, x;
	char com[30];
	while(~scanf("%d", &n) && n) {
		printf("Scenario #%d\n", ++cas);
		queue<int> q[1010];
		for(int i = 1; i <= n; i++) {
			scanf("%d", &len);
			while(len--) {
				scanf("%d", &x);
				num[x] = i;
			}
		}
		while(true) {
			scanf("%s", com);
			if(com[0] == 'S')
				break;
			else if(com[0] == 'E') {
				scanf("%d", &x);
				if(q[num[x]].size() == 0)
					q[0].push(num[x]);
				q[num[x]].push(x);
			}
			else {
				printf("%d\n", q[q[0].front()].front());
				q[q[0].front()].pop();
				if(q[q[0].front()].size() == 0)
					q[0].pop();
			}
		}
		puts("");
	}
	return 0;
}