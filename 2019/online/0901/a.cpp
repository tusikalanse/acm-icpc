#include <bits/stdc++.h>

using namespace std;
const int maxn=1e6+6;
int c[maxn],n,m,p;
int lowbit(int x){return x&(-x);}

void update(int pos,int v){
	for (int i=pos;i<=n;i+=lowbit(i)){
		c[i]+=v;
	}
}
int getsum(int p){
	int res=0;
	for (int i=p;i>0;i-=lowbit(i)){
		res+=c[i];
	}
	return res;
}
struct qry{
	int x1,y1,x2,y2;
	int lsum,rsum;
};
vector <qry> ans;
vector <int> upd[maxn];
struct node{int v,h;};
vector <node> val[maxn];
void init(){
	memset(c,0,sizeof(c));
	ans.clear();
	for(int i=0;i<maxn;i++) val[i].clear(),upd[i].clear();
}

int calc(int x,int y){
	int mid=n/2+1;
	long long l=max(abs(mid-x),abs(mid-y));
	long long len=l+l-1;
	long long tmp=len*len;
	if (x==mid-l) tmp+=len+(mid+l-y);
	else if (x==mid+l) tmp+=len*3+2+(y-(mid-l));
	else if (y==mid+l) tmp+=mid+l-x-1;
	else tmp+=len*2+1+x-(mid-l);
	long long val=1LL*n*n-tmp;
	int sum=0;
	while(val){
		sum+=val%10;
		val/=10;
	}
	return sum;
}

int main(void){
	int T;cin >> T;
	while(T--){
		init();
		cin >> n >> m >> p;
		for (int i=1;i<=m;i++){
			int x,y;scanf("%d%d",&x,&y);
			val[x].push_back({calc(x,y),y});
		}
		for (int i=0;i<p;i++){
			int x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			ans.push_back({x1,y1,x2,y2,-1,-1});
			upd[x1-1].push_back(i);if (x1==1) ans[i].lsum=0;
			upd[x2].push_back(i);
		}
		for (int i=1;i<=n;i++){
			for (int j=0;j<val[i].size();j++){
				node tmp=val[i][j];
				update(tmp.h,tmp.v);
			}
			for (int j=0;j<upd[i].size();j++){
				int idx=upd[i][j];
				int y1=ans[idx].y1,y2=ans[idx].y2;
				if (ans[idx].lsum==-1){
					
					ans[idx].lsum=getsum(y2)-getsum(y1-1);
				}else{
					ans[idx].rsum=getsum(y2)-getsum(y1-1);
				}
			}
		}
		for (int i=0;i<ans.size();i++)	printf("%d\n",ans[i].rsum-ans[i].lsum);
	}
}