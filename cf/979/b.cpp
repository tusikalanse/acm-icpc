#include <bits/stdc++.h>
using namespace std;


string s1, s2, s3;
int main() {
	int n;
	cin >> n >> s1 >> s2 >> s3;
	map<char, int> p1, p2, p3;
	int m1 = 1, m2 = 1, m3 = 1;
	int len = s1.size();
	for(int i = 0; i < len; ++i) {
		p1[s1[i]]++;
		p2[s2[i]]++;
		p3[s3[i]]++;
	}
	for(char i = 'a'; i <= 'z'; ++i) {
		if(p1[i] + n <= len)
			m1 = max(m1, p1[i] + n);
		else
			m1 = len;
		if(p2[i] + n <= len)
			m2 = max(m2, p2[i] + n);
		else
			m2 = len;
		if(p3[i] + n <= len)
			m3 = max(m3, p3[i] + n);
		else
			m3 = len;
	}	
	for(char i = 'A'; i <= 'Z'; ++i) {
	if(p1[i] + n <= len)
			m1 = max(m1, p1[i] + n);
		else
			m1 = len;
		if(p2[i] + n <= len)
			m2 = max(m2, p2[i] + n);
		else
			m2 = len;
		if(p3[i] + n <= len)
			m3 = max(m3, p3[i] + n);
		else
			m3 = len;
		}	
	if(m1 > m2 && m1 > m3)
		puts("Kuro");
	else if(m2 > m1 && m2 > m3)
		puts("Shiro");
	else if(m3 > m1 && m3 > m2)
		puts("Katie");
	else
		puts("Draw");
	return 0;
}