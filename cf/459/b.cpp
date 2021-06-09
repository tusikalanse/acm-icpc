#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	map<string, string> mp;
	string name, ip;
	int n, m;
	scanf("%d %d", &n, &m);
	while(n--){
		cin >> name >> ip;
		mp[ip] = name;
	}
	while(m--){
		cin >> name >> ip;
		cout << name << " " << ip << " #";
		ip.erase(ip.end()-1);
		cout << mp[ip] << endl;
	}
	return 0;
}