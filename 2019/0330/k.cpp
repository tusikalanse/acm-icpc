#include <bits/stdc++.h>  
#include <ext/pb_ds/assoc_container.hpp>  
using namespace std;  
using namespace __gnu_pbds;  

struct node {
	int t;
	double val;
	bool operator<(const node &rhs) const {
		return t > rhs.t;
	}
};

int T, n, x, y, z, op, cas;
double vv;
int cnt[1000010];

int main() {  
	scanf("%d", &T);
	priority_queue<node> que;
	while(T--) {
		tree<double, null_type, less<double>, rb_tree_tag, tree_order_statistics_node_update> bbt;  
    	scanf("%d", &n);
    	while(!que.empty())
    		que.pop();
    	printf("Case %d:\n", ++cas);
    	while(n--) {
    		scanf("%d%d%d", &op, &x, &y);
      		while(!que.empty() && que.top().t < x) {
    			node u = que.top();
    			que.pop();
    			bbt.erase(u.val);
    		}
    		if(op == 1) {
    			scanf("%d", &z);
    			vv = y + 1e-8 * cnt[y];
    			cnt[y]++;
    			bbt.insert(vv);
    			que.push({z, vv});
    		}
    		else {
    			if(bbt.size() < y)
    				printf("-1\n");
    			else
    				printf("%d\n", (int)*bbt.find_by_order(y - 1));
    		}
    	}
	}
    return 0;
}