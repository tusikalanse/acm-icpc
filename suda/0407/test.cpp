#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    string a;
    vector<char> z;
    vector<int> p,q,h,h2;
    int m,b,c,j,x,i=0,n;
    cin>>a;

    while(i<a.size())  //将字符串转为向量
    {
        z.push_back(a[i]);
        i=i+1;
    }
    
    for(i=0;i<a.size();i++)
    {
        if(z[i]>='A' &&z[i]<='Z')z[i]=z[i]-'A'+'a';  //将字母全部转换为小写
    }
    
    for(i=0;i<a.size();i++)   //将小写字母  全部转换为ASCII
    {
        m=z[i];
        p.push_back(m);
    }

    for(m=97;m<=122;m++)
    {
        q.push_back(m);    //向量q中为对应的a-z的ascii码
    }

    for(b=0;b<=q.size()-1;b++)
    {
        n=0;
        for(c=0;c<p.size();c++)
        {
            if(q[b]==p[c])n=n+1;
        }
        h.push_back(n);           //向量h中是对应a-z的字母出现的次数。
    }
    h2=h;
     for(i=0;i<h.size()-1;i++)        //排序
    {
        for(j=i+1;j<h.size();j++)
        {
            if(h[i]>h[j])
            {
                x=h[i];
                h[i]=h[j];
                h[j]=x;
                x=q[i];
                q[i]=q[j];
                q[j]=x;
            }
        }
    }
    for(i=h.size()-1;i>=0;i--)  
    {
        if(h[i]==0)break;
        cout<<(char)q[i]<<" : "<<h[i]<<endl;
    }
    return 0;
}