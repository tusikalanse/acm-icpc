#include <cstdio>
using namespace std;


int main(){
	long long l[52]={0,0,1,1};
	for(int i = 4; i<=50; i++)
		l[i] = l[i-1]+l[i-2]+l[i-3];
	int n;
	while(~scanf("%d", &n))
		printf("%lld\n", l[n]);
	return 0;
}