#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n;
	cin >> n;
	int a[3010];
	int flag=1;
	for (int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	vector<int>x;
	for (int i=0;i<n-1;i++)
	{
		x.push_back(abs(a[i+1]-a[i]));
	}
	if (x.size()==0) {
		printf("Jolly\n");
		return 0;
	}
	sort(x.begin(), x.end());
	for (int i=0;i<x.size();i++)
	{
		if (x[i] != i + 1){
			flag = 0;
			break;
		}
	}
	if (flag==1) printf("Jolly\n");
	else printf("Not jolly\n");
	return 0;
}