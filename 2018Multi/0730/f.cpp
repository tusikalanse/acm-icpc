#include <bits/stdc++.h>
using namespace std;

int t, n;
int a[100010], x;
map<int, int> cnt;


int main() {
    scanf("%d", &t);
    while(t--) {
    	x = 0;
    	cnt.clear();
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        for(int i = 1; i < n; ++i)
            scanf("%*d%*d");
    	bool flag = true;
    	for(int i = 1; i <= n; ++i)
    		cnt[a[i]]++;
		for(auto it = cnt.begin(); it != cnt.end(); it++) {
			if(it->second % 2 != 0) {
				x ^= it->first;    				
			}
		}
		if(x != 0)
			flag = false;
        puts(flag ? "D" : "Q");
    }
    return 0;
}