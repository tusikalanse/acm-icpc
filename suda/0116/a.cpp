#include <cstdio>
using namespace std;

int main(){
	double n, l, v1, v2, k;
	scanf("%lf %lf %lf %lf %lf", &n, &l, &v1, &v2, &k);
	if(n==k) printf("%lf\n", l/v2);
	else{
		int m = (int)n/(int)k;
		if ((int)n%(int)k) m++;       
		double dis = ((l/v1)/((m/v2)+(m-1)*(1-v1/v2)/(v1+v2)+1/v1-1/v2));
		printf("%lf\n", (l-dis)/v1 + dis/v2);
	}
	return 0;
}
