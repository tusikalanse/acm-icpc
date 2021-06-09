#include <bits/stdc++.h>
using namespace std;

char a[105], b[105];

int main(){
	int n, flag = 0, cnt = 0;
	scanf("%d", &n);
	scanf("%s", a);
	for(int i = 0; i<n; i++){
		if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u' || a[i] == 'y'){
			if(flag) continue;
			else {
				flag = 1;
				b[cnt++] = a[i];
			}
		}
		else {
			flag = 0;
			b[cnt++] = a[i];
		}
	}
	printf("%s\n", b);
	return 0;
}