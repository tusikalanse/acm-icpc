#include <bits/stdc++.h>
using namespace std;


int ans[10003];
int cnt = 1;

bool judge(int x){
	int res = 0;
	while(x){
		res += x%10;
		x /= 10;
	}
	if(res == 10) return true;
	return false;
}



int main(int argc, char const *argv[])
{

	for(int i = 1; cnt<=10000; i++){
		if(judge(i))
			ans[cnt++] = i;
	}
	int n;
	scanf("%d", &n);
	printf("%d\n", ans[n]);
	return 0;
}