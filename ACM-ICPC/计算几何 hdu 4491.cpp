/*
题意：给定平面上n个点的坐标，在一个点上放一条直线，并给出直线的方向，将直线以该点位轴逆时针转，遇到下一个点时，就以这个点为轴逆时针转动。按顺序输出前m次遇到的点的序列。
解法：有atan2计算点和坐标轴的夹角，在[-pi,0]的点变成[pi,2*pi]。找逆时针方向上距离当前直线最近的点就可以了。值得注意的是旋转的是直线不是射线，所以>pi的要减去pi
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int inf = 1111111;
int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    return x<0?-1:1;
}
struct Point{
    double x,y;
    Point (){};
    Point (double a, double b):x(a),y(b){};
    Point operator + (const Point a){return Point(x+a.x,y+a.y);}
    Point operator - (const Point a){return Point(x-a.x,y-a.y);}
    Point operator * (double c) {return Point(x*c,y*c);}
    bool operator == (const Point a)
    {
        return dcmp(x==a.x&&y==a.y);
    }
	void input(){scanf("%lf%lf",&x,&y);}
	void output(){printf("%.2f %.2f\n",x,y);}
};
typedef Point Vector;

double Cross(Point a, Point b)
{
    return a.x*b.y-a.y*b.x;
}
double Dot(Point a,Point b)
{
    return a.x*b.x-a.y*b.y;
}
Vector Rotate(Vector a,double rad)
{
    Vector c;
    c.x = a.x*cos(rad)-a.y*sin(rad);
    c.y = a.x*sin(rad)+a.y*cos(rad);
    return c;
}

double Angle(Point v)
{
	double x = atan2(v.y,v.x);
	return dcmp(x)<0? x+2*pi:x;
}
double Change(double rad)
{
	if(dcmp(rad)<0) rad+=2*pi;
	if(dcmp(rad-pi)>0) rad-=pi;
	return rad;
}

Point p[25];
int m;

int main()
{
    //freopen("in.txt","r",stdin);
    int cas;
    int tmp,s,u,v;
    double ang,a;
    scanf("%d",&cas);
    for(int ca = 1; ca<=cas;ca++)
    {
    	v = -1;
        scanf("%d%d%d%d%lf",&tmp,&m,&s,&u,&ang);
        for(int i = 1;i<=m; i++)
        {
            scanf("%d",&tmp);
            p[i].input();
        }

        ang = ang*pi/180.0;
        printf("%d",ca);
        for(int i = 0; i < s; i++)
        {
        	a=inf;
        	for(int i=1;i<=m;i++)
				if(i!=u&&i!=v)
				{
					double rad=Angle(p[i]-p[u])-ang;
					rad = Change(rad);
					if(dcmp(a-rad)>0)
					{
						a=rad;
						tmp=i;
					}
				}
            printf(" %d",tmp);
            ang=a+ang,v=u,u=tmp;
            ang = Change(ang);
        }
        printf("\n");
    }
    return 0;
}
