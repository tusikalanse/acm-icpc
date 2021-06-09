#include <bits/stdc++.h>
using namespace std;
string s, mx, mn;

int ptr = 0, mvv = 0, t;
int stk[110] = {0};
char raw[110];
char input[110];
char four[110] = {'\0'};

int go(string s) {
	char ch;
	strcpy(raw, s.c_str());
	memset(four, '\0', sizeof(four));
	memset(stk, 0, sizeof(stk));
	memset(input, '\0', sizeof(input));
		for(int i = 0; i<strlen(raw); i++) {
			ch = raw[i];
			if (ch<='9' && ch>='0') input[ptr++] = ch;
			else { 
				input[ptr++] = ' ';
				if (ch!='(' && ch!='d') {
				if (mvv) {
					switch(ch) {
						case '-':
						case '+':
						for(--mvv; mvv>=0; mvv--) {
							if (four[mvv] == '(') break;
							else input[ptr++] = four[mvv];
						} mvv++; break;
						case '*':
						case '/':
						for(--mvv; mvv>=0; mvv--) {
							if (four[mvv] == '(' || four[mvv] == '+' || four[mvv] == '-') break;
							else input[ptr++] = four[mvv];
						} mvv++; break;
						case ')':
						for(--mvv; mvv>=0; mvv--) {
							if (four[mvv] == '(') {mvv--; break;}
							else input[ptr++] = four[mvv];
						} mvv++; break;
					}
					if (ch!=')') four[mvv++] = ch;
				}
				else four[mvv++] = ch;
			}
			else four[mvv++] = ch;
			} 		
		}
		for(int j = mvv-1; j>=0; j--)   input[ptr++] = four[j]; 
		input[ptr++] = '\0';
		t = -1;
		mvv = 0;
        ptr = 0;
		while (input[mvv]!='\0')
			{ch = input[mvv++];
			if(ch<='9' && ch>='0') if(~t) t = t*10 + (int)(ch-'0'); else t = ch - '0';
			else	{
					if (~t)	{stk[ptr++] = t; t = -1;}
						switch(ch)
					{
						case '+':
							stk[ptr-2] = stk[ptr-1]+stk[ptr-2];
							ptr--;
							break;
						case '-':
							stk[ptr-2] = stk[ptr-2]-stk[ptr-1];ptr--;break;
						case '*':
							stk[ptr-2] *= stk[ptr-1];ptr--;break;
						case '/':
							stk[ptr-2] /= stk[ptr-1];ptr--;break;
						case 'd': stk[ptr-2] *= stk[ptr-1]; ptr--; break;
						default: break;
					}
					}
			}if (~t) stk[0] = t;
		ptr = mvv = 0;
		return stk[0];
}

int main() {
	while(cin >> s) {
		mx = mn = "";
		for(int i = 0; i < s.size(); ++i)
			mx += s[i];
		for(int i = 0; i < s.size(); ++i) {
			if(s[i] == 'd') {
				mn += 'd';
				mn += '1';
				if(s[i + 1] == '(') 
					while(s[i] != ')')
						i++;
				else
					while(s[i + 1] >= '0' && s[i + 1] <= '9')
						i++;
			}
			else
				mn += s[i];
		}
		cout << mn << " " << mx << endl;
		int a = go(mn), b = go(mx);
		if(a > b) swap(a, b);
		cout << a << " " << b << endl;
	}
	return 0;
}
