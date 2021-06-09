#include <bits/stdc++.h>
using namespace std;

string t[100005], s;

long long calc(string x){
	long long res = 0, tot = 0;
	for(int i = 0, l = x.length(); i<l; i++){
		if(x[i] == 's') tot++;
		else res+=tot;
	}
	return res;
}

bool cmp(string a, string b){
	return calc(a+b) > calc(b+a);
}



int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i<=n; i++) cin >> t[i];
	sort(&t[1], &t[n+1], cmp);
	for(int i = 1; i<=n; i++) s+=t[i];
	printf("%lld\n", calc(s));


	return 0;
}