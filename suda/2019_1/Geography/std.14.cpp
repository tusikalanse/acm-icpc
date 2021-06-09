#include <bits/stdc++.h>
#define pii pair<int,int>
#define pdd pair<double,double>
#define x first
#define y second
using namespace std;
int T;
int R;
pii s, r, p;

int dis2(pii a, pii b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

double dis(pdd a, pdd b)
{
	//cout << a.x << "    " << a.y << "    " << b.x << "    " << b.y << endl;
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool incircle(pii a, pii p)
{
	return dis2(a, p) <= R*R;
}

bool under(pdd a, pdd b, pdd p)
{
	double k = (b.y - a.y) / (b.x - a.x);
	double m = a.y - k * a.x;
	return p.y <= k * p.x + m;
}

int main()
{
	double ans = 0;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d %d %d %d", &R, &s.x, &r.x, &p.x, &p.y);
		s.y = r.y = 0;
		if (r.x - s.x <= R)
		{
			ans = 0;
		}
		else if (r.x - s.x > 2 * R)
		{
			ans = -1;
		}
		else
		{
			if (incircle(s, p) && incircle(r, p))
				ans = 0;
			else
			{
				pdd x1, x2;
				x1.x = x2.x = (s.x + r.x) / 2.0;
				x1.y = sqrt(R*R-(x1.x-s.x)*(x1.x-s.x));
				x2.y = -x1.y;
				if (!incircle(s, p))
				{
					if (under(s, x1, p))
					{
						ans = dis(s, p) - R;
					}
					else
					{
						ans = min(dis(p, x1), dis(p, x2));
					}
				}
				else
				{
					if (under(x1, r, p))
					{
						ans = dis(r, p) - R;
					}
					else
					{
						ans = min(dis(p, x1), dis(p, x2));
					}
				}
			}
		}
		printf("%.10f\n", ans);
	}
}