#include <bits/stdc++.h>

using namespace std;
const int maxn=5e4+4;
int n,m,q;
struct node{
    int v,w;
    bool operator < (const node& oth) const{return w<oth.w;}
};
vector <node> E[maxn];
struct ele{
    int u;
    long long d;
    bool operator<(const ele& oth) const{return d<oth.d;}
};
vector <long long> ans;
void bfs(int k){
    int mmax=0;
    //priority_queue<ele> que;
    multiset <ele> que;
    for (int i=1;i<=n;i++){
        for (int j=0;j<E[i].size();j++){
            que.insert({E[i][j].v,E[i][j].w});
        }
    }
    while(1){
        ele tmp=*que.begin();que.erase(que.begin());
        //cout << "> "<<tmp.d << endl;
        ans.push_back(tmp.d);
        if (ans.size()==k) return;
        for (int i=0;i<E[tmp.u].size();i++){
            ele endd=*--que.end();
            if (que.size()==k&&tmp.d+E[tmp.u][i].w>=endd.d) break;
            que.insert({E[tmp.u][i].v,tmp.d+E[tmp.u][i].w});
            if (que.size()>k)que.erase(--que.end());
        }
    }
}
int qry[maxn];
void init(){
    ans.clear();
    for (int i=1;i<=n;i++) E[i].clear();
}
int main(void){
    int t;cin >> t;
    while(t--){
        
        cin >> n >> m >> q;
        init();
        for (int i=1;i<=m;i++){
            int u,v,w;scanf("%d%d%d",&u,&v,&w);
            E[u].push_back({v,w});
        }
        int k=0;
        for (int i=1;i<=q;i++){
            scanf("%d",&qry[i]);
            k=max(k,qry[i]);
        }
        for (int i=1;i<=n;i++) sort(E[i].begin(),E[i].end());
        bfs(k);
        for (int i=1;i<=q;i++){
            printf("%lld\n",ans[qry[i]-1]);    
        }
        
    }
}