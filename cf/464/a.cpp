#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, a[5004], flag = 0;
	scanf("%d", &n);
	for(int i = 1; i<=n; i++) scanf("%d", &a[i]);
	for(int i = 1; i<=n; i++){
		if(i != a[i] && i != a[a[i]] && a[i] != a[a[i]] && i == a[a[a[i]]]){
			flag = 1;
			break;
		}
	}
	puts(flag?"YES":"NO");
	return 0;
}