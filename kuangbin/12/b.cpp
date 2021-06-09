#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
	int n;
	while(~scanf("%d", &n)){
		int num = 0, ans, t;
		for(int i = 1; i<=n; i++){
			scanf("%d", &t);
			if(num == 0){
				num++;
				ans = t;
			}
			else{
				if(t == ans)
					num++;
				else
					num--;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}