#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 100005;
const int inf = 1111111111;
const double eps = 1e-8;

int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    return x<0?-1:1;
}
struct Point{
    double x,y;
    Point(){}
    Point(double a,double b):x(a),y(b){}
    Point operator +(const Point a)const{return Point(x+a.x,y+a.y);}
    Point operator -(const Point a)const{return Point(x-a.x,y-a.y);}
    void input(){scanf("%lf%lf",&x,&y);}
};
typedef Point Vector;
double Dot(Vector a,Vector b)
{
    return a.x*b.x+a.y*b.y;
}
double Cross(Vector a,Vector b)
{
    return a.x*b.y-a.y*b.x;
}
double Dist(Point b)
{
    return sqrt(Dot(b,b));
}
Point mid(Point a, Point b)
{
	return Point((a.x + b.x) / 2, (a.y + b.y) / 2);
}
int main()
{
    //freopen("in.txt","r",stdin);

    int ans = 0;
    Point p[4];
    double dist[4];
    for(int i = 0; i < 4; i++)
        p[i].input();
    if(Dot(p[0] - p[2],p[1] - p[3]) == 0 && Dist(p[1] - p[0]) == Dist(p[3] - p[0])) ans += 2;
	if(Dot(p[1] - p[3],p[0] - p[2]) == 0 && Dist(p[1] - p[0]) == Dist(p[2] - p[1])) ans += 2;
	Point u, v;
	u = mid(p[0], p[1]), v = mid(p[2], p[3]);
	if(Dot(u - v,p[0] - p[1]) == 0 && Dot(u - v,p[2] - p[3]) == 0) ans += 2;

	u = mid(p[0], p[3]), v = mid(p[1], p[2]);
	if(Dot(u - v,p[0] - p[3]) == 0 && Dot(u - v,p[1] - p[2]) == 0) ans += 2;

	cout << ans << endl;
	return 0;
}

