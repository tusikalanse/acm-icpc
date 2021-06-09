#include <bits/stdc++.h>
using namespace std;


int main(){
	long long a, b;
	scanf("%lld %lld", &a, &b);
	int flag = 1;
	a++;
	for(long long i = 1; i<=b; i++){
		if(a%i)
		{flag = 0; break;}
	}
	puts(flag?"YES":"NO");
	return 0;
}