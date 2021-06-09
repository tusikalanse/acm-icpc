#include <bits/stdc++.h>
using namespace std;

char com[3][10] = {"insert", "getMin", "removeMin"};
char s[10];
int ans[1000003][2], cnt = 0;


int main() {
	int n, t;
	priority_queue<int, vector<int>, greater<int> > q;
	scanf("%d", &n);
	while(n--) {
		scanf("%s", s);
		if(s[0] == 'i') {
			scanf("%d", &t);
			q.push(t);
			ans[cnt][0] = 0;
			ans[cnt][1] = t;
			cnt++;
		}
		else if(s[0] == 'g') {
			scanf("%d", &t);
			while(!q.empty() && q.top() < t) {
					ans[cnt][0] = 2;
					cnt++;
					q.pop();
			}
			if(q.empty() || q.top() > t) {
				ans[cnt][0] = 0;
				ans[cnt][1] = t;
				cnt++;
				q.push(t);
			}
			ans[cnt][0] = 1;
			ans[cnt][1] = t;
			cnt++;
		}
		else {
			if(q.empty()) {
				ans[cnt][0] = 0;
				ans[cnt][1] = 1;
				q.push(1);
				cnt++;
			}
			ans[cnt][0] = 2;
			q.pop();
			cnt++;
		}
	}
	printf("%d\n", cnt);
	for(int i = 0; i < cnt; i++) {
		if(ans[i][0] != 2)
			printf("%s %d\n", com[ans[i][0]], ans[i][1]);
		else
			printf("%s\n", com[2]);
	}
	return 0;
}