#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <numeric>
#include <map>
#include <vector>
using namespace std;

int a[5005];
int main(){
	int n, out, res;
	while(~scanf("%d", &n)){
		out = 9999999;
		res = 0;
		memset(a, 0, sizeof(a)); 
		for(int i = 0; i<n; i++)
			scanf("%d", a+i);
		for(int i = 0; i<n-1; i++)
			for(int j = i+1; j<n; j++)
				if (a[i]>a[j])
					res++;
		out = res;
		for(int i = 0; i<n; i++){
			res = res+n-2*a[i]-1;
			out = min(out, res);
		}
		printf("%d\n", out);
	}
	return 0;
}
