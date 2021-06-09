#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)

const int MAXN = 1000010;

char s[MAXN];
int wa[MAXN*3], wb[MAXN*3], wv[MAXN*3], wss[MAXN*3],r[MAXN*3],rnk[MAXN],height[MAXN],sa[MAXN*3];
int c0(int *r, int a, int b) 
{return r[a] == r[b] && r[a + 1] == r[b + 1] && r[a + 2] == r[b + 2];}
int c12(int k, int *r, int a,int b) 
{if(k==2) return r[a]<r[b]||r[a]==r[b]&&c12(1,r,a+1,b+1);
else return r[a]<r[b]||r[a]==r[b]&&wv[a+1]<wv[b+1];}
void sort(int *r, int *a, int *b, int n, int m) {
	int i;
	for(i=0;i<n;++i) wv[i] = r[a[i]];
	for(i=0;i<m;++i) wss[i] = 0;
	for(i=0;i<n;++i) wss[wv[i]]++;
	for(i=1;i<m;++i) wss[i]+=wss[i-1];
	for(i=n-1;i>=0;--i) b[--wss[wv[i]]]=a[i];
}

void dc3(int *r,int *sa,int n,int m) {
	int i,j,*rn=r+n,*san=sa+n,ta=0,tb=(n+1)/3,tbc=0,p;
	r[n]=r[n+1]=0;
	for(i=0;i<n;++i) if(i%3!=0) wa[tbc++]=i;
	sort(r+2,wa,wb,tbc,m);
	sort(r+1,wb,wa,tbc,m);
	sort(r,wa,wb,tbc,m);
	for(p=1,rn[F(wb[0])]=0,i=1;i<tbc;++i)
		rn[F(wb[i])]=c0(r,wb[i-1],wb[i])?p-1:p++;
	if(p<tbc) dc3(rn,san,tbc,p);
	else for(i=0;i<tbc;++i) san[rn[i]]=i;
	for(i=0;i<tbc;++i) if(san[i]<tb) wb[ta++]=san[i]*3;
	if(n%3==1) wb[ta++]=n-1;
	sort(r,wb,wa,ta,m);
	for(i=0;i<tbc;++i) wv[wb[i]=G(san[i])]=i;
	for(i=0,j=0,p=0;i<ta&&j<tbc;++p)
		sa[p]=c12(wb[j]%3,r,wa[i],wb[j])?wa[i++]:wb[j++];
	for(;i<ta;++p) sa[p]=wa[i++];
	for(;j<tbc;++p) sa[p]=wb[j++];
	return;
}

void calheight(int *r, int *sa, int n) {
	int i,j,k=0;
	for(i=1;i<=n;++i) rnk[sa[i]]=i;
	for(i=0;i<n;height[rnk[i++]]=k)
		for(k?k--:0,j=sa[rnk[i]-1];r[i+k]==r[j+k];k++);
	return;
}

int main() {
	int n;
	while(~scanf("%s", s) && s[0] != '.') {
		n = strlen(s);
		for(int i = 0; i < n; ++i)
			r[i] = s[i];
		for(int i = n; i < n * 3; ++i)
			r[i] = 0;
		dc3(r, sa, n + 1, 128);
		calheight(r, sa, n);
		int flag = 1;
		for(int i = 1; i < n; ++i) {
			if(n % i == 0 && rnk[0] == rnk[i] + 1 && height[rnk[0]] == n - i) {
				printf("%d\n", n / i);
				flag = 0;
				break;
			}
		} 
		if(flag)
			puts("1");
	}
	return 0;
}