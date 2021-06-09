#include <cstdio>
#include <cstring>
#include <algorithm>

int num[20050];
long long a[20050];



int main(){
	memset(num, 0, sizeof(num));
	memset(a, 0, sizeof(a));
	for(int i = 0; i<20040; i++){
		int temp = i;
		while(temp){
			if (temp&1) num[i]++;
			temp >>= 1;
		}
	}
	int n, k, t;
	scanf("%d %d", &n, &k);
	for(int i = 0; i<n; i++){
		scanf("%d", &t);
		a[t]++;
	}
	long long out = 0;
	for(int i = 0; i<10040; i++){
		if (a[i] == 0) continue;
		for(int j = 0; j<10040; j++){
			if(a[j] > 0 && num[(i^j)] == k)
				{if(i == j) out += a[i]*(a[i]-1);
				else out += a[i]*a[j];}
	}
	}
	printf("%I64d\n", out/2); 
	return 0;
}
