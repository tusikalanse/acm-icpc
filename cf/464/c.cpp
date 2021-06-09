#include <bits/stdc++.h>
using namespace std;

int n, s, f, l, ans = 0, out;
long long temp = 0, res = 0;
int a[100006];

int main(){
	scanf("%d", &n);
	for(int i = 1; i<=n; i++)
		scanf("%d", a+i);
	scanf("%d%d", &s, &f);
	l = f-s;
	for(int i = 1; i<1+l; i++){
		temp += a[i];
	}
	res = temp;
	ans = 1;
	out = (s-(ans-1)+n-1)%n+1;
	for(int i = 2; i <= n; i++){
		temp -= a[i-1];
		temp += a[(i+l-2)%n+1];
		if(temp > res){
			res = temp;
			ans = i;
			out = (s-(ans-1)+n-1)%n+1;
		}
		if(temp == res && out > (s-(i-1)+n-1)%n+1){
			ans = i;
			out = (s-(ans-1)+n-1)%n+1;
		}
	}
	printf("%d\n", out);
	return 0;
}