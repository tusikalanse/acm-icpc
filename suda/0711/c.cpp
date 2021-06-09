#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int main() {
    int T, cas, n, t, cnt;
    scanf("%d", &T);
    while(T--) {
	    cnt = 0;
        scanf("%d %d", &cas, &n);
        printf("%d %d\n", cas, 1 + n/2);
        priority_queue<int, vector<int>, greater<int> > big;
        priority_queue<int> small;
        scanf("%d", &t);
        small.push(t);
        printf("%d", t);
    	cnt++;
        for(int i = 2; i <= n; i++) {
            scanf("%d", &t);
            if(t <= small.top()) {
                small.push(t);
                if(small.size() > big.size() + 1) {
                    t = small.top();
                    small.pop();
                    big.push(t);
                }
            }
            else {
                big.push(t);
                if(big.size() > small.size()) {
                    t = big.top();
                    big.pop();
                    small.push(t);
                }
            }
            if(i & 1) {
                if(cnt == 0) printf("%d", small.top());
		        else
                    printf(" %d", small.top());
		        cnt++;
		        if(cnt % 10 == 0) {
		            puts("");
		            cnt -= 10;
		        }
	        }        
	    }
        puts("");
    }
    return 0;
}
