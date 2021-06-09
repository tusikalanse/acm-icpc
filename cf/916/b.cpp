#include <bits/stdc++.h>
using namespace std;

deque<int> bit;
int main(){
	long long n, m; 
	long long digits = 0;
	long long i;
	int flag = 0;
	scanf("%lld %lld", &n, &m);
	while(n){
		if(n&1) 
			bit.push_front(digits);
		n >>= 1;
		digits++;
	}
	int a = bit.size(), t;
	if(a > m) puts("NO");
	else{
		puts("YES");
		long long c = m - a;
		while(c > 0){
			t = bit.front();
			long long cnt = 0;
			for(deque<int>::iterator it = bit.begin(); it != bit.end(); it++){
				if(*it == t)
					cnt++;
				else break;
			}
			if(cnt > c)
				break;
			c -= cnt;
			for(int k = 0; k<cnt; k++)
				bit.pop_front();
			for(int k = 0; k<2*cnt; k++)
				bit.push_front(t-1);
		}
		while(c--){
			t = bit.back();
			bit.pop_back();
			bit.push_back(t-1);
			bit.push_back(t-1);
		}
		for(deque<int>::iterator it = bit.begin(); it != bit.end(); it++){
			printf("%d ", *it);
		}
		puts("");
	}
	return 0;
}