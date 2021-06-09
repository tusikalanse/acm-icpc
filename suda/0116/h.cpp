#include <cstdio>
#include <algorithm>
#include <cstring>

struct mat{
	int r, c;
	long long num[2][2];
};
const long long mod = 1000000009;
mat mat_m(mat a, mat b){
	mat t;
	t.r = t.c = 2;
	for(int i = 0; i<a.r; i++)
		for(int j = 0; j<b.c; j++){
			t.num[i][j] = 0;
			for(int k = 0; k<a.c; k++)
				t.num[i][j] = (t.num[i][j] + (a.num[i][k]*b.num[k][j])%mod)%mod;
		}
	return t;	
}

mat quickpow(mat x, long long n){
	mat ans;
	ans.r = ans.c = 2;
	ans.num[0][0] = ans.num[1][1] = 1;
	ans.num[0][1] = ans.num[1][0] = 0;
	mat temp = x;
	while(n){
		if(n&1) ans = mat_m(ans, temp);
		temp = mat_m(temp, temp);
		n >>= 1;
	}
	return ans;
}


int main(){
	long long n;
	while(~scanf("%lld", &n)){
	mat what, out;
	what.r = what.c = out.r = out.c = 2;
	what.num[0][1] = what.num[1][0] = what.num[0][0] = 1;
	what.num[1][1] = 0;
	out = quickpow(what, n-1);
	printf("%lld\n", (out.num[0][0]%mod+mod)%mod);
}
	return 0;
}
