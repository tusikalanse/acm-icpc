#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct monoqueue {
	int head, tail;
	pair<int, int> q[1000010];
	monoqueue() : head(0), tail(0) {}
	void init() {
		head = 0;
		tail = 0;
	}
	void push(int i, int x) {
		while(head < tail && q[tail - 1].second < x) tail--;
		q[tail++] = make_pair(i,x);
	}
	int top() {
		if(head == tail)
			return -1;
		return q[head].second;
	}
	void pop(int i) {
		if(head < tail && i == q[head].first)
			head++;
	}
}q;

int _,x,s,l;
char c[10];

int main() {
	for(scanf("%d",&_);_;_--) {
		scanf("%*s");
		q.init();
		s=l=0;
		while(scanf("%s",c)) {
			if(c[0] == 'E')
				break;
			else if(c[0] == 'C') {
				scanf("%*s%d",&x);
				q.push(l,x);
				l++;
			}
			else if(c[0] == 'G') {
				q.pop(s);
				s++;
			}
			else
				printf("%d\n", q.top());
		}
	}
	return 0;
}