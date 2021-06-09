#include<bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
struct Point
{
	double x, y;
	Point(){}
	Point(double _x, double _y)
	{
		x = _x; y = _y;
	}
	void read()
	{
		scanf("%lf %lf", &x, &y);
	}
	Point operator-(const Point& p) const
	{
		return Point(x - p.x, y - p.y);
	}
	double operator*(const Point& p) const
	{
		return x * p.x + y * p.y;
	}
};

double dis(Point p, Point q)
{
	return sqrt((p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y));
}

double geta(Point p2, Point p1, Point p3)
{
	double res = (p1 - p2) * (p3 - p2);
	res = res / dis(p1, p2) / dis(p3, p2);
	return PI - acos(res);
}


int T, n;
Point arr[58];
Point Q;
int main()
{
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
		{
			arr[i].read();
		}
		arr[0] = arr[n];
		arr[n+1] = arr[1];
		Q.read();
		double res = 0;
		for (int i = 1; i <= n; ++i)
		{
			res += dis(arr[i], Q) * geta(arr[i], arr[i-1], arr[i+1]);
		}
		printf("Case #%d: %.3f\n", cas, res);
	}
}