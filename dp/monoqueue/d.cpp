#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 200010;
int sum[N], que[N], head, tail,n,k;

void init() {
	head = tail = 0;
}

void push(int id) {
	while(head < tail && sum[id] < sum[que[tail - 1]])
		tail--;
	que[tail++] = id;
}

void pop(int id) {
	while(head < tail && que[head] <= id - k)
		head++;
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
        sum[0] = 0;
        for(int i = 1;i <= n;++i) {
            scanf("%d",&sum[i]);
            sum[i + n] = sum[i];
            sum[i] += sum[i - 1];
        }
        for(int i = n + 1;i <= n + n;i ++)
            sum[i] += sum[i - 1];
        init();
        int ans = -0x3f3f3f3f,l,r;
        push(0);
        for(int i = 1; i < n + k;++i){
        	if(ans < sum[i] - sum[que[head]]) {
        		ans = sum[i] - sum[que[head]];
        		r = i;
        		l = que[head] + 1;
        	}
        	push(i);
        	pop(i);
        }
        printf("%d %d %d\n", ans, l, r > n ? r - n : r);
	}
	return 0;
}