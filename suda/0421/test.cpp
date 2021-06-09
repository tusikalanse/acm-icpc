//#include<bits/stdc++.h>  
//#pragma comment(linker, "/STACK:1024000000,1024000000")   
#include<stdio.h>  
#include<algorithm>  
#include<queue>  
#include<string.h>  
#include<iostream>  
#include<math.h>                    
#include<stack>
#include<set>  
#include<map>  
#include<vector>  
#include<iomanip> 
#include<bitset>

using namespace std;         //

#define ll long long  
#define ull unsigned long long
#define pb push_back  
#define FOR(a) for(int i=1;i<=a;i++) 
#define sqr(a) (a)*(a)
#define dis(a,b) sqrt(sqr(a.x-b.x)+sqr(a.y-b.y))
ll qp(ll a,ll b,ll mod){
	ll t=1;while(b){if(b&1)t=t*a%mod;b>>=1;a=a*a%mod;}return t;
}
struct DOT{int x;int y;};
inline void read(int &x){int k=0;char f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())k=k*10+c-'0';x=k*f;} 
void ex(){puts("-1");exit(0);}
const int dx[4]={0,0,-1,1};
const int dy[4]={1,-1,0,0};
const int inf=0x3f3f3f3f; 
const ll Linf=0x3f3f3f3f3f3f3f3fLL;
const ll Mod=1e18+7;
const double eps=1e-6;
const double pi=acos(-1.0);

const ll mod=1e9+7;
const int maxn=1e5+44;

int n;
int a[maxn];
int b[maxn];
int vis[maxn];
int dp[maxn];

int LIS(int a[]){
		dp[0]=inf;
		for(int i=1;i<=n;i++)dp[i]=inf;
		for(int i=1;i<=n;i++){
			*upper_bound(dp,dp+1+n,a[i])=a[i];
		}
		int ans=lower_bound(dp,dp+1+n,inf)-dp;
		return ans;
}
set<int>SSS;

int main(){
	while(~scanf("%d",&n)){
		memset(vis,0,sizeof vis);
		SSS.clear();

		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			b[i]=a[i];
			vis[a[i]]=1;
		}
		int now=1;
		for(int i=1;i<=n;i++){
			while(vis[now])now++;
			if(b[i]==0){
				b[i]=now;
				vis[now]=1;
				now++;
			}
		}

		int tl=LIS(b);

		if(tl<n-1){printf("0\n");}

		else if(tl==n-1){



			int mis=0;
			for(int i=1;i<=n;i++){
				if(a[i]!=0 && a[i]!=i){
					if(!SSS.count(a[i]-i)){
						mis++;
						SSS.insert(a[i]-i);
					}
				}
			}	

			if(mis>=2){
				printf("1\n");
			}
			else{	//mis=1
				if(abs((*SSS.begin()))>1){
					printf("1\n");
					continue;
				}

				int l=n,r=1;
				for(int i=1;i<=n;i++){
					if(a[i]!=i && a[i]){
						l=min(l,i);
						r=max(r,i);
					}
				}
				//cout<<l<<"ww"<<r<<endl;

				int lcnt=0,rcnt=0;

				while(a[l-1]==0 && l>1){l--;lcnt++;}
				while(a[r+1]==0 && r<n){r++;rcnt++;}


				//cout<<lcnt<<"ww"<<rcnt<<endl;

				if(*SSS.begin()==-1){
					printf("%lld\n",1ll*lcnt*rcnt+lcnt);
				}else{
					printf("%lld\n",1ll*lcnt*rcnt+rcnt);
				}
				
			}
		}else{
			ll ans=0;
			int cnt=0;
			for(int i=1; i<=n; ++i) {
				if(a[i]!=0){
					if(cnt!=0){
						ans+=1ll*(cnt-1)*(cnt-1);
						cnt=0;
					}			
				}else{
					cnt++;
				}
			}
			if(a[n]==0){
				ans+=1ll*(cnt-1)*(cnt-1);
			}
			printf("%lld\n",ans);
		}
	}
}





























