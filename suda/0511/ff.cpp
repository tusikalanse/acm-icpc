#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define maxn 500100
typedef long long ll;
using namespace std;
ll a[maxn], b[maxn], T, n, m, cnt;
int sum[maxn][35];
const ll mod = 1e9;
int main(){
  //  clock_t st = clock();
    cin>>T;
    while(T--){
        cnt = 0;
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=m;i++) cin>>b[i];
        sort(a+1, a+n+1);
        for(ll i=1;i<=n;i++)
            for(ll j=1;j<=32;j++)
                sum[i][j] = (sum[i-1][j]+a[i]/j)%mod;
        for(int i=1;i<=m;i++){
            ll ans = 0, p = 1, num = 1;
            while(1){
                int s = upper_bound(a+1, a+n+1, p)-a;
                if(s > n) break;
                int t = upper_bound(a+1, a+n+1, p*b[i])-a;
                if(s != t) ans = (ans+sum[t-1][num]-sum[s-1][num])%mod;
                num++;
                p *= b[i];
            }
            cnt = (cnt+ans*i)%mod;
        }
        cout<<(cnt+mod)%mod<<endl;
    }
  //  printf("%f\n", (double)(clock() - st)/CLOCKS_PER_SEC);
    return 0;
}