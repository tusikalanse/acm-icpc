#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int a[N], b[N], n, pa[N], pb[N];


int main() {
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &b[i]);
        }
        a[0] = b[0] = -1e9;
        stack<int> sa, sb;
        sa.push(0); sb.push(0);
        for(int i = 1; i <= n; ++i) {
        	while(!sa.empty() && a[sa.top()] > a[i]) sa.pop();
        	pa[i] = sa.top();
   	     	sa.push(i);
   			while(!sb.empty() && b[sb.top()] > b[i]) sb.pop();
        	pb[i] = sb.top();
        	sb.push(i);
        }
        int p = 1;
        for(int i = 1; i <= n; ++i) {
        	if(pa[i] == pb[i])
        		p = i;
        	else
        		break;
        }
        printf("%d\n", p);
    }
    return 0;
}