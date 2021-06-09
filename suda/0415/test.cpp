#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#pragma comment(linker,"/STACK:102400000,102400000")

using namespace std;
#define   MAX           100005
#define   MAXN          1000005
#define   maxnode       205
#define   sigma_size    2
#define   lson          l,m,rt<<1
#define   rson          m+1,r,rt<<1|1
#define   lrt           rt<<1
#define   rrt           rt<<1|1
#define   middle        int m=(r+l)>>1
#define   LL            long long
#define   ull           unsigned long long
#define   mem(x,v)      memset(x,v,sizeof(x))
#define   lowbit(x)     (x&-x)
#define   pii           pair<int,int>
#define   bits(a)       __builtin_popcount(a)
#define   mk            make_pair
#define   limit         10000

//const int    prime = 999983;
const int    INF   = 0x3f3f3f3f;
const LL     INFF  = 0x3f3f;
//const double pi    = acos(-1.0);
const double inf   = 1e18;
const double eps   = 1e-9;
const LL     mod   = 1e9+7;
const ull    mx    = 133333331;

/*****************************************************/
inline void RI(int &x) {
      char c;
      while((c=getchar())<'0' || c>'9');
      x=c-'0';
      while((c=getchar())>='0' && c<='9') x=(x<<3)+(x<<1)+c-'0';
 }
/*****************************************************/

struct Edge{
    int v,next;
}edge[MAX*2];
int head[MAX];
int tot;
int c[MAX];
map<int,int> cnt[MAX];
map<int,LL> sum[MAX];
LL ans[MAX];
void init(){
    mem(head,-1);
    tot=0;
}

void add_edge(int a,int b){
    edge[tot]=(Edge){b,head[a]};
    head[a]=tot++;
}

void dfs(int u,int fa){
    cnt[u].clear();
    sum[u].clear();
    cnt[u][c[u]]=1;
    sum[u][1]=c[u];
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(v==fa) continue;
        dfs(v,u);
        if(cnt[u].size()<cnt[v].size()){
            swap(cnt[u],cnt[v]);
            swap(sum[u],sum[v]);
        }
        for(map<int,int>::iterator it=cnt[v].begin();it!=cnt[v].end();it++){
            int x=it->first,y=it->second;
            if(cnt[u].count(x)){
                sum[u][cnt[u][x]]-=x;
                cnt[u][x]+=y;
                sum[u][cnt[u][x]]+=x;
            }
            else{
                cnt[u][x]=y;
                sum[u][cnt[u][x]]+=x;
            }
        }
    }
    map<int,LL>::iterator it=sum[u].end();
    it--;
    ans[u]=it->second;
}
int main(){
    //freopen("in.txt","r",stdin);
    int n;
    while(cin>>n){
        init();
        for(int i=1;i<=n;i++) scanf("%d",&c[i]);
        for(int i=1;i<n;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            add_edge(a,b);
            add_edge(b,a);
        }
        dfs(1,-1);
        for(int i=1;i<=n;i++) printf("%I64d ",ans[i]);
    }
    return 0;
}