#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
const double eps = 1e-8;
const double inf = 1e20;
const double pi = acos(-1.0);
const int maxp = 1010;
int sgn(double x)
{
    if (fabs(x) < eps) return 0;
    if (x < 0) return -1;
    else return 1;
}
inline double sqr(double x){return x * x;}

struct Point
{
    double x, y;
    Point(){}
    Point(double _x, double _y){x = _x; y = _y;}
    void input() {scanf("%lf%lf", &x, &y);}
    void output(){printf("%.2f %.2f\n", x, y);}
    bool operator == (Point b) const {return sgn(x - b.x) == 0 && sgn(y - b.y) == 0;}
    bool operator < (Point b) const {return sgn(x - b.x) == 0 ? sgn(y - b.y) < 0: x < b.x;}
    Point operator + (const Point &b) const {return Point(x + b.x, y + b.y);}
    Point operator - (const Point &b) const {return Point(x - b.x, y - b.y);}
    //叉积
    double operator ^ (const Point &b) const {return x * b.y - y * b.x;}
    //点积
    double operator * (const Point &b) const {return x * b.x + y * b.y;}
    //返回长度   向量(0,0) -> (x,y)的长度
    double len(){return hypot(x,y);}
    //返回长度的平方
    double len2(){return x * x + y * y;}
    //两点距离
    double distance(Point p){return hypot(x - p.x, y - p.y);}
    Point operator * (const double &k) const {return Point(x * k, y * k);}
    Point operator / (const double &k) const {return Point(x / k, y / k);}
    //求该点看点a,b的夹角
    double rad(Point a, Point b)
    {
        Point p = *this;
        return fabs(atan2( fabs((a - p) ^ (b - p)), (a - p) * (b - p) ));
    }
    //化为长度为r的向量
    Point trunc(double r)
    {
        double l = len();
        if (!sgn(l)) return *this;
        r /= l;
        return Point(x * r, y * r);
    }
    //逆时针转90°
    Point rotleft() {return Point(-y, x);}
    //顺时针转90°
    Point rotright() {return Point(y, -x);}
    //绕p点逆时针旋转angle(弧度)
    Point rotate(Point p, double angle)
    {
        Point v = (*this) - p;
        double c = cos(angle), s = sin(angle);
        return Point(p.x + v.x * c - v.y * s, p.y + v.x * s + v.y * c);
    }
};

struct Line
{
    Point s, e;
    Line(){}
    Line(Point _s, Point _e) {s = _s; e = _e;}
    bool operator == (Line v) {return (s == v.s) && (e == v.e);}
    //点斜式确定直线：点丢给s，倾斜角angle算出e (0 <= angle < pi)
    Line (Point p, double angle)
    {
        s = p;
        if (sgn(angle - pi / 2) == 0)
        {
            e = (s + Point(0,1));
        }
        else
        {
            e = (s + Point(1,tan(angle)));
        }
    }
    //ax + by + c == 0
    Line(double a, double b, double c)
    {
        if (sgn(a) == 0)
        {
            s = Point(0, - c / b);
            e = Point(1, - c / b);
        }
        else if (sgn(b) == 0)
        {
            s = Point(-c / a, 0);
            e = Point(-c / a, 1);
        }
        else
        {
            s = Point(0, -c / b);
            e = Point(1, (-c-a) / b);
        }
    }
    void input()
    {
        s.input();
        e.input();
    }
    //小的点放在s
    void adjust() {if (e < s) swap(s, e);}
    //求线段长度
    double length() {return s.distance(e);}
    //返回直线倾斜角(0 <= angle < pi)
    double angle()
    {
        double k = atan2(e.y - s.y, e.x - s.x);
        if (sgn(k) < 0) k += pi;
        if (sgn(k - pi) == 0) k -= pi;
        return k;
    }
    //点和直线关系：1 在左侧 // 2 在右侧 // 3 在直线上
    int relation(Point p)
    {
        int c = sgn((p - s) ^ (e - s));
        if (c < 0) return 1;
        else if (c > 0) return 2;
        else return 3;
    }
    //点在线段上的判断
    bool pointonseg(Point p){return sgn((p - s) ^ (e - s)) == 0 && sgn((p - s) * (p - e)) <= 0;}
    //两向量平行（对应直线平行或重合）
    bool parallel(Line v){return sgn((e - s) ^ (v.e - v.s)) == 0;}
    //两线段相交判断 2 规范相交  //  1 非规范相交  //  0 不相交
    /*
    规范相交：交点不是顶点并且线段没重合；
    非规范相交：交点是顶点或者线段重合。
    */
    int segcrossseg(Line v)
    {
        int d1 = sgn((e - s) ^ (v.s - s));
        int d2 = sgn((e - s) ^ (v.e - s));
        int d3 = sgn((v.e - v.s) ^ (s - v.s));
        int d4 = sgn((v.e - v.s) ^ (e - v.s));
        if ( (d1 ^ d2) == -2 && (d3 ^ d4) == -2) return 2;
        return (d1 == 0 && sgn((v.s - s) * (v.s - e)) <= 0) ||
        (d2 == 0 && sgn((v.e - s) * (v.e - e)) <= 0) ||
        (d3 == 0 && sgn((s - v.s) * (s - v.e)) <= 0) ||
        (d4 == 0 && sgn((e - v.s) * (e - v.e)) <= 0);
    }
    //直线和线段相交判断 2 规范相交  //  1 非规范相交  //  0 不相交
    int linecrosseg(Line v)
    {
        int d1 = sgn((e - s) ^ (v.s - s));
        int d2 = sgn((e - s) ^ (v.e - s));
        if ((d1 ^ d2) == -2) return 2;
        return (d1 == 0 || d2 == 0);
    }
    //两直线相交判断 2 相交  //  1 重合  //  0 平行
    int linecrossline(Line v)
    {
        if ((*this).parallel(v))
            return v.relation(s) == 3;
        return 2;
    }
    Point crosspoint(Line v)
    {
        double a1 = (v.e - v.s) ^ (s - v.s);
        double a2 = (v.e - v.s) ^ (e - v.s);
        return Point((s.x * a2 - e.x * a1) / (a2 - a1), (s.y * a2 - e.y * a1) / (a2 - a1));
    }
    //点到直线的距离
    double dispointtoline(Point p){return fabs((p - s) ^ (e - s)) / length();}
    //点到线段的距离
    double dispointtoseg(Point p)
    {
        if (sgn((p - s) * (e - s)) < 0 || sgn((p - e) * (s - e)) < 0)
            return min(p.distance(s), p.distance(e));
        return dispointtoline(p);
    }
    //返回线段到线段的距离 (前提：线段不相交， 相交距离就是0了)
    double dissegtoseg(Line v)
    {
        return min( min(dispointtoseg(v.s), dispointtoseg(v.e)),
                    min(v.dispointtoseg(s), v.dispointtoseg(e)) );
    }
    //返回p在直线上的投影
    Point lineprog(Point p) {return s + ( ( (e-s) *  ( (e-s) * (p-s) )  )/( (e-s).len2() ) );}
    //返回p关于直线的对称点
    Point symmetrypoint(Point p)
    {
        Point q = lineprog(p);
        return Point(2 * q.x - p.x, 2 * q.y - p.y);
    }
};

struct Circle
{
    Point p;
    double r;
    Circle(){}
    Circle(Point _p, double _r) {p = _p; r = _r;}
    Circle(double x, double y, double _r) {p = Point(x, y); r = _r;}
    //三角形外接圆：需要Point的 + / rotate()和Line的crosspoint()    中垂线得圆心
    Circle(Point a, Point b, Point c)
    {
        Line u = Line((a + b) / 2, ((a + b) / 2) + ((b - a).rotleft()));
        Line v = Line((b + c) / 2, ((b + c) / 2) + ((c - b).rotleft()));
        p = u.crosspoint(v);
        r = p.distance(a);
    }
    //三角形的内切圆
    Circle(Point a, Point b, Point c, bool qwjeiq)
    {
        Line u, v;
        double m = atan2(b.y - a.y, b.x - a.x), n = atan2(c.y - a.y, c.x - a.x);
        u.s = a;
        u.e = u.s + Point(cos((n + m) / 2), sin((n + m) / 2));
        v.s = b;
        m = atan2(a.y - b.y, a.x - b.x), n = atan2(c.y - b.y, c.x - b.x);
        v.e = v.s + Point(cos((n + m) / 2), sin((n + m) / 2));
        p = u.crosspoint(v);
        r = Line(a, b).dispointtoseg(p);
    }

    void input()
    {
        p.input();
        scanf("%lf", &r);
    }

    void output()
    {
        printf("%.2f %.2f %.2f\n", p.x, p.y, r);
    }

    bool operator == (Circle v){return (p == v.p) && sgn(r - v.r) == 0;}
    bool operator < (Circle v) const {return ((p < v.p) || ((p == v.p) && sgn(r - v.r) < 0));}
    double area() {return pi * r * r;}
    double circumference() {return 2 * pi * r;}
    //点和圆的关系: 0 圆外     1 圆上     2 圆内
    int realation(Point b)
    {
        double dst = b.distance(p);
        if (sgn(dst - r) < 0) return 2;
        else if (sgn(dst - r) == 0) return 1;
        return 0;
    }
    //线段和圆的关系
    int relationseg(Line v)
    {
        double dst = v.dispointtoseg(p);
        if (sgn(dst - r) < 0) return 2;
        else if (sgn(dst - r) == 0) return 1;
        return 0;
    }

    //直线和圆
    int relationline(Line v)
    {
        double dst = v.dispointtoline(p);
        if (sgn(dst - r) < 0) return 2;
        else if (sgn(dst - r) == 0) return 1;
        return 0;
    }
    //两圆关系  5外离  4外切   3相交  2内切  1内含
    int relationcircle(Circle v)
    {
        double d = p.distance(v.p);
        if (sgn(d - r - v.r) > 0) return 5;
        if (sgn(d - r - v.r) == 0) return 4;
        double l = fabs(r - v.r);
        if (sgn(d - r - v.r) < 0 && sgn(d - l) > 0) return 3;
        if (sgn(d - l) == 0) return 2;
        if (sgn(d - l) < 0) return 1;
    }
    //求两圆交点（返回值 0：不交  1：1个   2：2个， 排除重合情况）
    int pointcrosscircle(Circle v, Point &p1, Point &p2)
    {
        int rel = relationcircle(v);
        if (rel == 1 || rel == 5)
            return 0;
        double d = p.distance(v.p);
        double l = (d * d + r * r - v.r * v.r) / (2 * d);
        double h = sqrt(r * r - l * l);
        Point tmp = p + (v.p - p).trunc(l);
        p1 = tmp + ((v.p - p).rotleft().trunc(h));
        p2 = tmp + ((v.p - p).rotright().trunc(h));
        if (rel == 2 || rel == 4)
            return 1;
        return 2;
    }
    //求直线和圆的交点
    int pointcrossline(Line v, Point &p1, Point &p2)
    {
        if (!(*this).relationline(v))
            return 0;
        Point a = v.lineprog(p);
        double d = v.dispointtoline(p);
        d = sqrt(r * r - d * d);
        if (sgn(d) == 0)
        {
            p1 = a;
            p2 = a;
            return 1;
        }
        p1 = a + (v.e - v.s).trunc(d);
        p2 = a - (v.e - v.s).trunc(d);
        return 2;
    }
    //得到过a,b两点 半径为r1的两个圆
    int getcircle(Point a, Point b, double r1, Circle &c1, Circle &c2)
    {
        Circle x(a, r1), y(b, r1);
        int t = x.pointcrosscircle(y, c1.p, c2.p);
        if (!t) return 0;
        c1.r = c2.r = r;
        return t;
    }
    //得到与直线u相切，过点q半径为r1的圆
    int getcircle(Line u, Point q, double r1, Circle &c1, Circle &c2)
    {
        double dis = u.dispointtoline(q);
        if (sgn(dis - r1 * 2) > 0)
            return 0;
        if (sgn(dis) == 0)
        {
            c1.p = q + ((u.e - u.s).rotleft().trunc(r1));
            c2.p = q + ((u.e - u.s).rotright().trunc(r1));
            c1.r = c2.r = r1;
            return 2;
        }
        Line u1 = Line((u.s + (u.e - u.s).rotleft().trunc(r1)),
                       (u.e + (u.e - u.s).rotleft().trunc(r1)));
        Line u2 = Line((u.s + (u.e - u.s).rotright().trunc(r1)),
                       (u.e + (u.e - u.s).rotright().trunc(r1)));
        Circle cc = Circle(q, r1);
        Point p1, p2;
        if (!cc.pointcrossline(u1, p1, p2))
            cc.pointcrossline(u2, p1, p2);
        c1 = Circle(p1, r1);
        if (p1 == p2)
        {
            c2 = c1;
            return 1;
        }
        c2 = Circle(p2, r1);
        return 2;
    }
    //与直线u，v相切半径为r1的圆
    int getcircle(Line u, Line v, double r1, Circle &c1, Circle &c2, Circle &c3, Circle &c4)
    {
        if (u.parallel(v))
            return 0;
        Line u1 = Line(u.s + (u.e - u.s).rotleft().trunc(r1), u.e + (u.e - u.s).rotleft().trunc(r1));
        Line u2 = Line(u.s + (u.e - u.s).rotright().trunc(r1), u.e + (u.e - u.s).rotright().trunc(r1));
        Line v1 = Line(v.s + (v.e - v.s).rotleft().trunc(r1), v.e + (v.e - v.s).rotleft().trunc(r1));
        Line v2 = Line(v.s + (v.e - v.s).rotright().trunc(r1), v.e + (v.e - v.s).rotright().trunc(r1));
        c1.r = c2.r = c3.r = c4.r = r1;
        c1.p = u1.crosspoint(v1);
        c2.p = u1.crosspoint(v2);
        c3.p = u2.crosspoint(v1);
        c4.p = u2.crosspoint(v2);
        return 4;
    }
    //同时与不相交圆cx，cy相切半径为r1的圆
    int getcircle(Circle cx, Circle cy, double r1, Circle &c1, Circle &c2)
    {
        Circle x(cx.p, r1 + cx.r), y(cy.p, r1 + cy.r);
        int t = x.pointcrosscircle(y, c1.p, c2.p);
        if (!t)
            return 0;
        c1.r = c2.r = r1;
        return t;
    }
    //过一点作圆的切线 (先判断点和圆的关系)
};

Point A, B, O;
double r;

double zgggnb(double theta) {
	double x = r * cos(theta), y = r * sin(theta);
	return hypot(abs(A.x - x), abs(A.y - y)) + hypot(abs(B.x - x), abs(B.y - y));
}

double norm(double x) {
	return max(-1.0, min(1.0, x));
}

double trinary_search() {
	double midx = (A.x + B.x) / 2, midy = (A.y + B.y) / 2;
	double theta = atan2(midy, midx);
	double l = theta - pi / 2, r = theta + pi / 2;
	for(int i = 1; i <= 60; ++i) {
		double lmid = l + (r - l) / 3, rmid = r - (r - l) / 3;
		if(zgggnb(lmid) < zgggnb(rmid))
			r = rmid;
		else
			l = lmid;
	}
	return zgggnb(l);
}


int aa,bb,cc,dd,ee,ff,gg;

int main()
{
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        scanf("%d %d %d %d %d %d %d", &aa, &bb, &cc, &dd, &ee, &ff, &gg);
        A.x = aa, A.y = bb, B.x = cc, B.y = dd, O.x = ee, O.y = ff, r = gg;
        A.x -= O.x;
        A.y -= O.y;
        B.x -= O.x;
        B.y -= O.y;
        O.x = O.y = 0;
        Line AB(A, B);
        AB.adjust();
        Circle CO(O, r);
        double d1 = A.distance(O), d2 = B.distance(O), dab = A.distance(B);
        if (CO.relationseg(AB) == 2)
        {
            double th3 = acos(CO.r / d1);
            double th4 = acos(CO.r / d2);
            double dd1 = sqrt(d1 * d1 - r * r), dd2 = sqrt(d2 * d2 - r * r);
            double th = acos(norm((d1 * d1 + d2 * d2 - dab * dab) / 2.0 / d1 / d2));
            double d3 = r * (th - th3 - th4);
            printf("%.3f\n", dd1 + dd2 + d3);
        }
        else
        {
            printf("%.3f\n",trinary_search());
        }
    }
    return 0;
}