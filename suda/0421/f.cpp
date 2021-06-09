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

int n,m,cnt;
int vis[maxn * 2];
int head[maxn];
ll dis[maxn * 2];

struct EDGE{
	int v, c, nxt;
	ll w;
}edge[maxn << 1];        

void addedge(int x, int y, int c, int w) {
	edge[cnt].v = y;
	edge[cnt].c = c;
	edge[cnt].w = w;
	edge[cnt].nxt = head[x];
	head[x] = cnt++;
}

struct NODE{    
    int id;
	ll d;    
    friend bool operator<(NODE a,NODE b){return a.d>b.d;}    
};    


ll dij(){  
   	ll ans = 0x3f3f3f3f3f3f3f3fLL;
	priority_queue<NODE>Q;    
	for(int i = head[1]; ~i; i = edge[i].nxt) {
		Q.push((NODE) {i, edge[i].w});
		dis[i] = edge[i].w;
	}
    while(!Q.empty()){    
        NODE now=Q.top();
        Q.pop();   
	  	int p = now.id;
        if(vis[p]) continue;
        vis[p] = 1;
		int u = edge[p].v;
		if(u == n) 
			ans = min(ans, dis[p]);
		for(int i = head[u]; ~i; i = edge[i].nxt) {
			int v = edge[i].v;
			int w = edge[i].w;
			int c = abs(edge[i].c - edge[p].c);
			if(dis[i] > dis[p] + w + c) {
				dis[i] = dis[p] + w + c;
				Q.push((NODE){i, dis[i]});
			}
		}
    }    
    return ans;
}   


int main(){
	while(~scanf("%d%d",&n,&m)){
		memset(dis, 0x3f, sizeof(dis));
		memset(vis, 0, sizeof(vis));
		cnt = 0;
		memset(head, -1, sizeof(head));
		int ai,bi,ci,di;
		for(int i=1;i<=m;i++){
			//scanf("%d%d%d%lld",&ai,&bi,&ci,&di);
			read(ai);read(bi);read(ci);read(di);
			addedge(ai, bi, ci, di);
			addedge(bi, ai, ci, di);
		}
		printf("%lld\n", dij());
	}
}































