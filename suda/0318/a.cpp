#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a, b = 0, t, mmax = -1, id[100006], b1, bm, cnt = 0, nmax = -1;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i<=n; i++){
		scanf("%d", &t);
		a += t;
		if(mmax < t){
			mmax = t;
			cnt = 0;
			id[cnt++] = i;
		}
		else if(mmax == t){
			mmax = t;
			id[cnt++] = i;
		}
	}
	for(int i = 1; i<=m; i++){
		scanf("%d", &t);
		b += t;
		if(i == 1) b1 = t;
		if(i == m) bm = t;
		if(nmax < t){
			nmax = t;
		}
		else if(nmax == t){
			nmax = t;
		}
	}
	if(mmax)
	printf("%d%09d\n", a + (m-1)*mmax, b + (id[0]-1)*b1 + bm*(n-id[cnt-1]) + nmax*(id[cnt-1] - id[0]));
	else
		printf("%d\n", b+nmax*(id[cnt-1] - id[0]));
	return 0;
}