#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=2e6+10;
ll m,n,k;

ll f[maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    int T=0;
    while(t--)
    {
        T++;
        cin>>n>>m>>k;
        cout<<"Case #"<<T<<": ";
        if(m<=k){//直接递推
            ll tp=(n-m+1);
            f[1] = (k-1) % tp;  //编号从0开始
            for(int i=2;i<=m;++i) f[i] = (f[i-1]+k)%(++tp);
            cout<<f[m]+1<<endl;
        }
        else{
            if(k==1) cout<<m<<endl;
            else{
                ll tp = n-m+1;
                ll ans = (k-1) % tp;  //编号从0开始
                ll now = 1;
                while(1){
                    if((tp-ans)%(k-1)==0){
                        ll x = (tp-ans)/(k-1) -1 ;
                        x = min(x,m-now);
                        ans += x*k;
                        now += x;
                        tp  += x;
                        if(now==m) break;
                        ans =(ans + k) % (tp+1);
                        now +=1;
                        tp  +=1;
                        if(now==m) break;
                        assert(now <=m);
                    }
                    else{
                        ll x = (tp-ans)/(k-1);
                        x = min(x,m-now);
                        ans += x*k;
                        now += x;
                        tp +=x;
                        if(now==m) break;
                        ans =(ans + k) % (tp+1);
                        now +=1;
                        tp  +=1;
                        if(now==m) break;
                        assert(now <=m);
                    }
                }
                cout<<ans+1<<endl;
            }
        }
    }
    return 0;
}