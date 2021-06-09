#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int ans[50010];

struct Cow {
	int beg, END, ord;
	bool operator < (const Cow &rhs) const {
		return beg < rhs.beg;
	}
}cows[50010];

struct node
{
	int id, tm;
	bool operator < (const node &rhs) const {
		return tm > rhs.tm;
	}
}temp;


int main() {
	int n, cnt = 1;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &cows[i].beg, &cows[i].END);
		cows[i].ord = i + 1;
	}
	sort(cows, cows + n);
	priority_queue<node> q;
	temp.id = 1;
	temp.tm = cows[0].END;
	q.push(temp);
	ans[cows[0].ord] = 1;
	for(int i = 1; i < n; i++) {
		node u = q.top();
		if(u.tm < cows[i].beg) {
			q.pop();
			u.tm = cows[i].END;
			q.push(u);
			ans[cows[i].ord] = u.id;
		}
		else {
			temp.id = ++cnt;
			temp.tm = cows[i].END;
			q.push(temp);
			ans[cows[i].ord] = cnt;
		}
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= n; ++i)
	{
		printf("%d\n", ans[i]);
	}
	return 0;
}