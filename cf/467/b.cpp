#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int p, y;
	scanf("%d %d", &p, &y);
	int ans = -1, flag = 0;
	while(y > p){
		flag = 0;
		for(int i = 2; i*i <= y && i <= p; i++){
			if(y % i == 0){
				flag = 1; 
				break;
			}
		}
		if(!flag){
			ans = y;
			break;
		}
		y--;
	}
	printf("%d\n", ans);
	return 0;
}