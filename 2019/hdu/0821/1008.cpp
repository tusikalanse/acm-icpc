#include<bits/stdc++.h>

using namespace std;
const int maxn=1e5+5;
int n;
long long a[maxn],b[maxn];

struct ele{
    int id;
    long long val,sz;
    bool operator<(const ele& oth) const{
        return val<oth.val;
    }
};
vector <ele> arr;
vector <long long> mmax;
vector <long long> ans;
int main(void){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        arr.clear();ans.clear();mmax.clear();
        for (int i=1;i<=n;i++){
            scanf("%lld%lld",&a[i],&b[i]);
            a[i]*=2;b[i]*=2;
            if (a[i]>=b[i]) arr.push_back({i,a[i],1}),arr.push_back({i,b[i],1});
            else arr.push_back({i,(a[i]+b[i])/2,2});
            
        }
        sort(arr.begin(),arr.end());
        for (int i=0;i<arr.size();i++){
            long long tmp;
            if (arr[i].sz==1)tmp=arr[i].val;
            else tmp=a[arr[i].id];
            if (mmax.size()==0) mmax.push_back(tmp);
            else mmax.push_back(max(mmax[mmax.size()-1],tmp));
        }
        long long mmin=1e18;
        long long sum=0;
        for (int i=arr.size()-1;i>=0;i--){
            if(arr[i].sz==1){
                sum+=arr[i].val;
                ans.push_back(sum);
                mmin=min(mmin,arr[i].val);
            }else{
                long long tmp=0;
                tmp=sum-mmin+arr[i].val*2;
                tmp=max(tmp,sum+mmax[i]);
                ans.push_back(tmp);
                sum+=arr[i].val*2;ans.push_back(sum);
                mmin=min(mmin,b[arr[i].id]);
            }
        }
        for (int i=0;i<ans.size();i++) printf("%lld%c",ans[i]/2," \n"[i==ans.size()-1]);
    }
}