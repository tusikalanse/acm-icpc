#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int upper[30], lower[30];
int type(int a[]){
	int o = 0;
	for(int i = 0; i<30; i++)
		o += (a[i]>0);
	return o;	
}
char a[100006] = "";
int main(){
	int n, s;
	memset(upper, 0, sizeof(upper));
	memset(lower, 0, sizeof(lower));
	scanf("%d", &n);
	getchar();
	for(int i = 1; i<=n; i++) {
		a[i] = getchar();
		if (a[i] <= 'z' && a[i] >= 'a') lower[a[i]-'a']++;
		else upper[a[i]-'A']++;
	}
	s = type(upper) + type(lower);
	int l = 1, r = 2, ans = 1e7;
	memset(upper, 0, sizeof(upper));
	memset(lower, 0, sizeof(lower));
	if (a[1] <= 'z' && a[1] >= 'a') lower[a[1]-'a']++; else if (a[1]!='\0')upper[a[1]-'A']++;
	if(s==1) ans = 1;
	else{ 
	while(l<=n && r<=n+1){
		if (r<=n){
		if (a[r] <= 'z' && a[r] >= 'a') lower[a[r]-'a']++;
		else upper[a[r]-'A']++;
	}
		//printf("s = %d, %d, %d %d\n", type(upper)+type(lower), l, r, s);
		if(type(upper)+type(lower) < s) r++;
		else
		{
		ans = min(ans, r-l+1);
		if (a[r] <= 'z' && a[r] >= 'a') lower[a[r]-'a']--; else upper[a[r]-'A']--;
		if (a[l] <= 'z' && a[l] >= 'a') lower[a[l]-'a']--; else upper[a[l]-'A']--;
		l++;	
		}
		}
		
	}
	printf("%d\n", ans);
	return 0;
}
