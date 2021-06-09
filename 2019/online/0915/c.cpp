#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int MAXN = (262144) + 10;
namespace fastIO{
    #define BUF_SIZE 100000
    #define OUT_SIZE 100000
    #define ll long long
    //fread->read
    bool IOerror=0;
    inline char nc(){
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if (p1==pend){
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if (pend==p1){IOerror=1;return -1;}
            //{printf("IO error!\n");system("pause");for (;;);exit(0);}
        }
        return *p1++;
    }
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
    inline void read(int &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(ll &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(double &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (ch=='.'){
            double tmp=1; ch=nc();
            for (;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0');
        }
        if (sign)x=-x;
    }
    inline void read(char *s){
        char ch=nc();
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        for (;!blank(ch)&&!IOerror;ch=nc())*s++=ch;
        *s=0;
    }
    inline void read(char &c){
        for (c=nc();blank(c);c=nc());
        if (IOerror){c=-1;return;}
    }
    //getchar->read
    inline void read1(int &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (bo)x=-x;
    }
    inline void read1(ll &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (bo)x=-x;
    }
    inline void read1(double &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (ch=='.'){
            double tmp=1;
            for (ch=getchar();ch>='0'&&ch<='9';tmp/=10.0,x+=tmp*(ch-'0'),ch=getchar());
        }
        if (bo)x=-x;
    }
    inline void read1(char *s){
        char ch=getchar();
        for (;blank(ch);ch=getchar());
        for (;!blank(ch);ch=getchar())*s++=ch;
        *s=0;
    }
    inline void read1(char &c){for (c=getchar();blank(c);c=getchar());}
    //scanf->read
    inline void read2(int &x){scanf("%d",&x);}
    inline void read2(ll &x){
        #ifdef _WIN32
            scanf("%I64d",&x);
        #else
        #ifdef __linux
            scanf("%lld",&x);
        #else
            puts("error:can't recognize the system!");
        #endif
        #endif
    }
    inline void read2(double &x){scanf("%lf",&x);}
    inline void read2(char *s){scanf("%s",s);}
    inline void read2(char &c){scanf(" %c",&c);}
    //inline void readln2(char *s){gets(s);}
    //fwrite->write
    struct Ostream_fwrite{
        char *buf,*p1,*pend;
        Ostream_fwrite(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;}
        void out(char ch){
            if (p1==pend){
                fwrite(buf,1,BUF_SIZE,stdout);p1=buf;
            }
            *p1++=ch;
        }
        void print(int x){
            static char s[15],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1);
        }
        void println(int x){
            static char s[15],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1); out('\n');
        }
        void print(ll x){
            static char s[25],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1);
        }
        void println(ll x){
            static char s[25],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1); out('\n');
        }
        void print(double x,int y){
            static ll mul[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,
                1000000000,10000000000LL,100000000000LL,1000000000000LL,10000000000000LL,
                100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL};
            if (x<-1e-12)out('-'),x=-x;x*=mul[y];
            ll x1=(ll)floor(x); if (x-floor(x)>=0.5)++x1;
            ll x2=x1/mul[y],x3=x1-x2*mul[y]; print(x2);
            if (y>0){out('.'); for (size_t i=1;i<y&&x3*mul[i]<mul[y];out('0'),++i); print(x3);}
        }
        void println(double x,int y){print(x,y);out('\n');}
        void print(char *s){while (*s)out(*s++);}
        void println(char *s){while (*s)out(*s++);out('\n');}
        void flush(){if (p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}}
        ~Ostream_fwrite(){flush();}
    }Ostream;
    inline void print(int x){Ostream.print(x);}
    inline void println(int x){Ostream.println(x);}
    inline void print(char x){Ostream.out(x);}
    inline void println(char x){Ostream.out(x);Ostream.out('\n');}
    inline void print(ll x){Ostream.print(x);}
    inline void println(ll x){Ostream.println(x);}
    inline void print(double x,int y){Ostream.print(x,y);}
    inline void println(double x,int y){Ostream.println(x,y);}
    inline void print(char *s){Ostream.print(s);}
    inline void println(char *s){Ostream.println(s);}
    inline void println(){Ostream.out('\n');}
    inline void flush(){Ostream.flush();}
    //puts->write
    char Out[OUT_SIZE],*o=Out;
    inline void print1(int x){
        static char buf[15];
        char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x;
        while(x)*p1++=x%10+'0',x/=10;
        while(p1--!=buf)*o++=*p1;
    }
    inline void println1(int x){print1(x);*o++='\n';}
    inline void print1(ll x){
        static char buf[25];
        char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x;
        while(x)*p1++=x%10+'0',x/=10;
        while(p1--!=buf)*o++=*p1;
    }
    inline void println1(ll x){print1(x);*o++='\n';}
    inline void print1(char c){*o++=c;}
    inline void println1(char c){*o++=c;*o++='\n';}
    inline void print1(char *s){while (*s)*o++=*s++;}
    inline void println1(char *s){print1(s);*o++='\n';}
    inline void println1(){*o++='\n';}
    inline void flush1(){if (o!=Out){if (*(o-1)=='\n')*--o=0;puts(Out);}}
    struct puts_write{
        ~puts_write(){flush1();}
    }_puts;
    inline void print2(int x){printf("%d",x);}
    inline void println2(int x){printf("%d\n",x);}
    inline void print2(char x){printf("%c",x);}
    inline void println2(char x){printf("%c\n",x);}
    inline void print2(ll x){
        #ifdef _WIN32
            printf("%I64d",x);
        #else
        #ifdef __linux
            printf("%lld",x);
        #else
            puts("error:can't recognize the system!");
        #endif
        #endif
    }
    inline void println2(ll x){print2(x);printf("\n");}
    inline void println2(){printf("\n");}
    #undef ll
    #undef OUT_SIZE
    #undef BUF_SIZE
}; using namespace fastIO;

struct cp {
    double a, b;
    cp(double _a = 0, double _b = 0) : a(_a), b(_b) {}
    cp operator+(const cp &rhs) const {
        return cp(a + rhs.a, b + rhs.b);
    }
    cp operator-(const cp &rhs) const {
        return cp(a - rhs.a, b - rhs.b);
    }
    cp operator*(const cp &rhs) const {
        return cp(a * rhs.a - b * rhs.b, a * rhs.b + b * rhs.a);
    }
    cp operator!() const {
        return cp(a, -b);
    }
};

cp a[MAXN], b[MAXN], c[MAXN];
cp ab[MAXN], ac[MAXN], bc[MAXN];
int n, m, N, cas;
int rev[MAXN];
void get_rev(int bit) {
    for(int i = 0; i < (1 << bit); ++i) {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
    }
}

void FFT(cp a[], int len, int dft) {
    for(int i = 0; i < N; ++i) if(i < rev[i]) swap(a[i], a[rev[i]]);
    for(int i = 2, mid = 1; i <= N; i <<= 1, mid <<= 1) {
        cp wn(cos(2 * PI / i), sin(2 * dft * PI / i));
        for(int j = 0; j < N; j += i) {
            cp w(1, 0);
            for(int k = j; k < j + mid; ++k) {
                cp u = a[k], v = w * a[k + mid];
                a[k] = u + v;
                a[k + mid] = u - v;
                w = w * wn;
            }
        }
    }
    if(dft == -1)
        for(int i = 0; i < N; ++i)
            a[i].a /= N, a[i].b /= N;
}
int num[200010];
int al[100010], bl[100010],cl[100010], T, len, bit, mx;
long long abi[MAXN],bci[MAXN],aci[MAXN];
int main() {
    read(T);
    while(T--) {
    	len = 0, mx = 0;
    	read(n);

    	if(n <= 1000) {
    		for(int i = 0; i < n; ++i) 
    			read(al[i]);

    		for(int i = 0; i < n; ++i) 
    			read(bl[i]);

    		for(int i = 0; i < n; ++i) 
    			read(cl[i]);

    		sort(al + 1, al + n + 1);
    		sort(bl + 1, bl + n + 1);
    		sort(cl + 1, cl + n + 1);

    		long long ans = 0;
    		for (int i = 1; i <= n; ++i)
    		{
    			for (int j = 1; j <= n; ++j)
    			{
    				int aa = al[i], bb = bl[j];
    				int R = aa + bb, L = abs(bb - aa);
    				for (int k = 1; k <= n; ++k)
    				{
    					ans += (cl[k] >= L && cl[k] <= R);
    				}
    			}
    		}
    		/*
    		vector<int> vec;
    		for(int i = 0; i < n; ++i) {
    			for(int j = 0; j < n; ++j) {
    				vec.push_back(al[i] + bl[j]);
    			}
    		}
    		sort(vec.begin(), vec.end());
    		for(int i = 0; i < n; ++i) {
    			int x = cl[i];
    			ans += upper_bound(vec.begin(), vec.end(), x) - vec.begin();
    		}

    		vec.clear();
    		for(int i = 0; i < n; ++i) {
    			for(int j = 0; j < n; ++j) {
    				vec.push_back(bl[i] + cl[j]);
    			}
    		}
    		sort(vec.begin(), vec.end());
    		for(int i = 0; i < n; ++i) {
    			int x = al[i];
    			ans += upper_bound(vec.begin(), vec.end(), x) - vec.begin();
    		}

    		vec.clear();
    		for(int i = 0; i < n; ++i) {
    			for(int j = 0; j < n; ++j) {
    				vec.push_back(al[i] + cl[j]);
    			}
    		}
    		sort(vec.begin(), vec.end());
    		for(int i = 0; i < n; ++i) {
    			int x = bl[i];
    			ans += upper_bound(vec.begin(), vec.end(), x) - vec.begin();
    		}*/
    		ans = n * n * n - ans;
    		printf("Case #%d: %lld\n", ++cas, ans);
    		continue;
    	}


        memset(num, 0, sizeof(num));
        for(int i = 0; i < n; ++i) { 
        	read(al[i]);
            mx = max(mx, al[i]);
        }
        for(int i = 0; i < n; ++i)
            num[al[i]]++;
        for(int i = 0; i <= mx; ++i) 
        	a[i] = cp(num[i], 0);
        len = max(len, mx);

        mx = 0;
        memset(num, 0, sizeof(num));
        for(int i = 0; i < n; ++i) { 
        	read(bl[i]);
            mx = max(mx, bl[i]);
        }
        for(int i = 0; i < n; ++i)
            num[bl[i]]++;
        for(int i = 0; i <= mx; ++i) 
        	b[i] = cp(num[i], 0);
        len = max(len, mx);
        mx = 0;
        memset(num, 0, sizeof(num));
        for(int i = 0; i < n; ++i) {

        read(cl[i]); 
            mx = max(mx, cl[i]);
        }
        for(int i = 0; i < n; ++i)
            num[cl[i]]++;
        for(int i = 0; i <= mx; ++i) 
        	c[i] = cp(num[i], 0);
        len = max(len, mx);
        len *= 2;
        bit = 1;
        while((1 << bit) < len) bit++;
        get_rev(bit);
        N = 1 << bit;
        FFT(a, N, 1);
        FFT(b, N, 1);
        FFT(c, N, 1);
        for(int i = 0; i < N; ++i) {
            ab[i] = a[i] * b[i];
            ac[i] = a[i] * c[i];
            bc[i] = b[i] * c[i];
        }
        FFT(ab, N, -1);
        FFT(ac, N, -1);
        FFT(bc, N, -1);
       	long long ans = 0;
       	for(int i = 1; i < N; ++i) {
       		abi[i] = (long long)(ab[i].a+0.5) +abi[i-1];
       	} 
       	for(int i=0;i<n;++i) {
       		//cout<<abi[cl[i]-1]<<endl;

       		ans+=abi[cl[i]-1];
       	}
      	for(int i = 1; i < N; ++i) {
       		bci[i] = (long long)(bc[i].a+0.5) +bci[i-1];
       	} 
       	for(int i=0;i<n;++i) {
       		//cout<<bci[al[i]-1]<<endl;
       		ans+=bci[al[i]-1];
       	}
       	for(int i = 1; i < N; ++i) {
       		aci[i] = (long long)(ac[i].a+0.5) +aci[i-1];
       	} 
       	for(int i=0;i<n;++i) {
       		//cout<<aci[bl[i]-1]<<endl;
       		ans+=aci[bl[i]-1];
       	}
       	ans = 1ll*n*n*n-ans;
       	printf("Case #%d: %lld\n", ++cas, ans);
       	for(int i = 0; i < N; ++i)
       		a[i] = b[i] = c[i] = cp(0, 0);
       }
    return 0;
}