#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 100005;
const int inf = 111111;
const double eps = 1e-8;
int dcmp(double x)
{
	if(fabs(x)<eps) return 0;
	else return x < 0? -1:1;
}
struct Point{
    double x,y;
    Point() {} ;
    Point (double a , double b) : x(a) , y(b) {}
    Point operator * (double c) {return Point (x * c , y * c );}
    Point operator / (double c) {return Point (x / c , y / c );}
	Point operator - (const Point a) {return Point (x - a.x , y - a.y );}
	Point operator + (const Point a) {return Point (x + a.x , y + a.y );}
	bool operator == (const Point &a)const
	{
		return dcmp(x-a.x)==0&&dcmp(y-a.y)==0;
	}
	bool operator <(const Point &a)const
	{
		return x<a.x||(x==a.x&&y<a.y);
	}
	void input(){scanf("%lf%lf",&x,&y);}
	void output(){printf("%.2f %.2f\n",x,y);}
};
typedef Point Vector;
struct Polygon{
    int n;
    Point p[15];
    void input()
    {
        scanf("%d",&n);
        for(int i = 0; i < n; i++) p[i].input();
    }
};


Vector get_vector(Point a,Point b)
{
	return Point(b.x-a.x,b.y-a.y);
}
double Cross(Vector a,Vector b)
{
	return a.x*b.y-a.y*b.x;
}
double Dot(Vector a,Vector b)
{
	return a.x*b.x+a.y*b.y;
}
double Length(Vector a)
{
	return sqrt(Dot(a,a));
}
double Getdis(Point p1, Point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}
Point Getinter(Point a,Vector aa,Point b,Vector bb)
{
	Vector u = a-b;
	double t = Cross(bb,u)/Cross(aa,bb);
	return a+aa*t;
}
bool Isinter(Point s1, Point e1, Point s2, Point e2){
    if( min(s1.x, e1.x) <= max(s2.x, e2.x) &&
        min(s1.y, e1.y) <= max(s2.y, e2.y) &&
        min(s2.x, e2.x) <= max(s1.x, e1.x) &&
        min(s2.y, e2.y) <= max(s1.y, e1.y) &&
        dcmp(Cross(s2-s1,e2-s1))*dcmp(Cross(s2-e1,e2-e1))<=0&&
        dcmp(Cross(s1-s2,e1-s2))*dcmp(Cross(s1-e2,e1-e2))<=0)
        return true;
    return false;
}
Point s,t,p;
bool flag;
void solve(Polygon *pol,int k)
{
    Point p1,p2,tmp;
    for(int i = 0; i < pol[k].n; i++)
    {
        p1 = pol[k].p[i];
        p2 = pol[k].p[(i+1)%pol[k].n];
        // p1.output();p2.output();
        if(Isinter(s,t,p1,p2))
        {
            if(dcmp(Cross(s-t,p1-p2))==0)
            {
                if(Getdis(p1,s)<Getdis(p2,s)) tmp = p1;
                else tmp = p2;
                //tmp.output();
            }
            else
                tmp = Getinter(s,t-s,p1,p2-p1);
            //tmp.output();
            if(p.x==inf||(Getdis(tmp,s) < Getdis(p,s)))
            {
                if(k!=0) {flag = 0;return;}
                p = tmp;
            }
        }
    }

}
int main()
{
    //freopen("in.txt","r",stdin);
    int n,m;

    Vector dir;
    Polygon pol[15];
    while(scanf("%d",&n)&&n)
    {
        flag = 1;
        s.input();
        dir.input();
        for(int i = 0; i < n; i++)
            pol[i].input();
        p.x = inf,p.y = inf;
        t = s+dir*inf;
        //s.output();t.output();
        solve(pol,0);
        if(p.x==inf) flag = 0;
        //p.output();
        for(int i = 1; flag&&i<n; i++)
            solve(pol,i);
        if(flag) printf("HIT\n");
        else printf("MISS\n");
    }
    return 0;
}


