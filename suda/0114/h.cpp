#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;



int main(){
	int n, mx = 0, id = 0, a[55];
	scanf("%d", &n);
	for(int i = 1; i<=n; i++){
		scanf("%d", &a[i]);
		if(abs(a[i])>mx){
			mx = abs(a[i]);
			id = i;
		}
	}
	if(id == 0) id = 1;
	printf("%d\n", 2*n-1);
	for(int i = 1; i<=n; i++)
		printf("%d %d\n", id, i);
	if(a[id]>0)
		for(int i = 1; i<n; i++)
			printf("%d %d\n", i, i+1);
	else
		for(int i = n; i>1; i--)
			printf("%d %d\n", i, i-1);
	return 0;
}
