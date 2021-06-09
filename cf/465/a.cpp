#include <cstdio>
using namespace std;

int main(){
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = 1; 2*i<=n; i++){
		if(n%i == 0)
			ans++;
	}
	printf("%d\n", ans);




	return 0;
}