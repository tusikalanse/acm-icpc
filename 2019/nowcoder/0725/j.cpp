#include <bits/stdc++.h>
using namespace std;


namespace fastIO {    
    #define BUF_SIZE 100000    
    #define OUT_SIZE 100000    
    #define ll long long    
    //fread->read    
    bool IOerror=0;    
    inline char nc() {    
        static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;    
        if (p1 == pend) {    
            p1 = buf;
            pend = buf + fread(buf, 1, BUF_SIZE, stdin);    
            if (pend == p1) {
                IOerror = 1;
                exit(0);
                return -1;
            }    
            //{printf("IO error!\n");system("pause");for (;;);exit(0);}    
        }    
        return *p1++;    
    }    
    inline bool blank(char ch){return ch == ' '|| ch == '\n'|| ch == '\r'|| ch == '\t';}    
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
    #undef OUT_SIZE    
    #undef BUF_SIZE    
}; using namespace fastIO;  



const int N = 5e5 + 10;
int T, q, m, op, v;
long long ss;
char s[12];
map<int, long long> ptos;
map<long long, int> stop, stov;

long long convert(char s[]) {
	long long val = 0;
	for(int i = 0; s[i]; ++i) {
		val = val * 11 + s[i] - '0' + 1;
	}
	return val;
}


int main() {
	read(T);
	while(T--) {
		ptos.clear(); stop.clear(); stov.clear();
		read(q); read(m);
		ptos[100000] = 1e18;
		stop[1000000000000000000LL] = 100000;
		stov[1000000000000000000LL] = 100;
		while(q--) {
			read(op); read(s); read(v);
			ss = convert(s);
			if(op == 0) {
				if(stov.count(ss)) {
					printf("%d\n", stov[ss]);
					int fi = ptos.begin()->first;
					int pos = stop[ss];
					ptos.erase(ptos.find(pos));
					stop[ss] = fi - 1;
					ptos[fi - 1] = ss;
				}
				else {
					stov[ss] = v;
					int fi = ptos.begin()->first;
					stop[ss] = fi - 1;
					ptos[fi - 1] = ss;
					if(ptos.size() > m) {
						long long es = ptos.rbegin()->second;
						ptos.erase(--ptos.end());
						stop.erase(stop.find(es));
						stov.erase(stov.find(es));
					}
					printf("%d\n", v);
				}
			}
			else {
				if(!stov.count(ss)) {
					puts("Invalid");
					continue;
				}
				int pos = stop[ss];
				if(v == 0) {
					printf("%d\n", stov[ss]);
				}
				else {
					map<int, long long>::iterator it = ptos.find(pos);
					if(v == 1) {
						if(it == ptos.begin()) {
							puts("Invalid");
							continue;
						}
						it--;
						if(stov[it->second] == 100) {
							puts("Invalid");
							continue;
						}
						printf("%d\n", stov[it->second]);
					}
					else {
						if(++it == ptos.end()) {
							puts("Invalid");
							continue;
						}
						if(stov[it->second] == 100) {
							puts("Invalid");
							continue;
						}
						printf("%d\n", stov[it->second]);
					}
				}
			}
		}
	}
	return 0;
}