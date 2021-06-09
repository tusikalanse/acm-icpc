#include <bits/stdc++.h>
using namespace std;

const int MAXN = 0x3f3f3f3f;
int n, r = 1e9, l = -1e9, t;
int a[100005];
char b[100005];


int mmax(int *s, int *e){
	int res = -MAXN;
	for(int *i = s; i != e; i++){
		res = max(*i, res);
	}
	return res;
}

int mmin(int *s, int *e){
	int res = MAXN;
	for(int *i = s; i != e; i++){
		res = min(*i, res);
	}
	return res;
}



int main(){
	scanf("%d", &n);
	for(int i = 1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	getchar();
	for(int i = 1; i<=n; i++){
		scanf("%c", &b[i]);
	}
	for(int i = 5; i<=n; i++){
		if(b[i] != b[i-1]){
			if(b[i] == '0'){
				t = mmin(a+i-4, a+i+1);
				r = min(t - 1, r);
			}
			else{
				t = mmax(a+i-4, a+i+1);
				l = max(t + 1, l);
			}
		}
		else if(b[i-1] == b[i-2] && b[i-2] == b[i-3] && b[i-3] == b[i-4]){
			if(b[i] == '0'){
				t = mmax(a+i-4, a+i+1);
				l = min(l, t);
			}
			else {
				t = mmin(a+i-4, a+i+1);
				r = max(r, t);
			}
		}

		//printf("%d\n", t);
	}
	printf("%d %d\n", l, r);



	return 0;
}