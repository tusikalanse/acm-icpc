#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL gao(LL y, LL m, LL d)
{
	return y * 360 + m * 30 + d;
}
string s[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
const int mod = 5;
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		LL y0, m0, d0;
		string str;
		LL v0 = 0;
		
		cin >> y0 >> m0 >> d0 >> str;
		LL y1, m1, d1;
		cin >> y1 >> m1 >> d1;
		if (str[0] == 'M')
			v0 = 0;
		else if (str[0] == 'T' && str[1] == 'u')
			v0 = 1;
		else if (str[0] == 'W')
			v0 = 2;
		else if (str[0] == 'T' && str[1] == 'h')
			v0 = 3;
		else if (str[0] == 'F')
			v0 = 4;
		LL v1 = gao(y0, m0, d0), v2 = gao(y1, m1, d1);
		//cout << "v1 = " << v1 << "   v2 = " << v2 << endl;
		LL dif = v2 - v1;
		v0 = ((v0 + dif) % mod + mod) % mod;
		cout << s[v0] << endl;
	}
	return 0;
}