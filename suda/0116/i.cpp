#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

long long n, a, b, c, p;
struct mat{
	long long num[3][3];
};
mat mat_m(mat a, mat b){
	mat t;
	for(int i = 0; i<3; i++)
		for(int j = 0; j<3; j++){
			t.num[i][j] = 0;
			for(int k = 0; k<3; k++)
				t.num[i][j] = (t.num[i][j] + (a.num[i][k]*b.num[k][j])%mod)%mod;
		}
	return t;
}

mat quickpow(mat x, long long n){
	mat ans;
	memset(ans.num, 0, sizeof(ans.num));
	for(int i = 0; i<3; i++) ans.num[i][i] = 1;
	mat temp = x;
	while(n){
		if(n&1) ans = mat_m(ans, temp);
		temp = mat_m(temp, temp);
		n >>= 1;
	}
	return ans;
}


int main(){
	int t;
	scanf("%d", &t);
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
