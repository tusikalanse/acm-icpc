#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 1005;

struct qwer
{
	int s, t ,x;
	void init(){
		s = t = x = 5;
	}
}card[MAXN];

int main()
{
	int n, res;
	while(~scanf("%d", &n)){
		res = 0;
		for(int i = 1; i<=n; i++){
			card[i].init();
			scanf("%d %d", &card[i].s, &card[i].t);
			if(card[i].t < 3) scanf("%d", &card[i].x);
		}
		int i = 1, start = 1;
		while(i <= n){
			start = i;
			while(i<n && card[i].s <= card[i+1].s) i++;
			int j = i;
			while(j >= start){
				switch(card[j].t){
					case 1:
						res += card[j].x;
						break;
					case 2:
						res += card[i].x*(j-start+1);
						break;
					case 3:
						j = start-1;
						break;
					case 4:
						j--;
						break;
				}
				j--;
			}
			i++;
		}
		printf("%d\n", res);
	}
	return 0;
}