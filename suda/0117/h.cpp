#include <cstdio>
#include <algorithm>
#include <bitset>
using namespace std;


bitset<10003> l[1005];
int main(){
	int n, q, m, t, x, y;
	scanf("%d", &n);
	for(int i = 1; i<=n; i++){
		scanf("%d", &m);
		l[i].set(0);
		while(m--){
			scanf("%d", &t);
			l[i].set(t);
		}
	}
	scanf("%d", &q);
	while(q--){
		int flag = 0;
		scanf("%d %d", &x, &y);
		for(int i = 1; i<=n; i++){
			if(l[i].test(x) && l[i].test(y)){
				flag = 1;
				break;
			}
		}
		puts(flag?"Yes":"No");
	}
	return 0;
}