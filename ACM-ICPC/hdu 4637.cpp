#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const double PI = acos(-1.0);
const int MAXN = 1005;
inline int dcmp(double x)
{
    if(fabs(x)<EPS) return 0;
    return x<0? -1:1;
}
struct Point{
    double x,y;
    Point(){}
    Point(double a,double b):x(a),y(b){}
    Point operator+(const Point &a)const{return Point(x+a.x,y+a.y);}
    Point operator-(const Point &a)const{return Point(x-a.x,y-a.y);}
    Point operator*(double a)const{return Point(x*a,y*a);}
    bool operator < (const Point &a)const
    {
        return dcmp(x-a.x)<0||(dcmp(x-a.x)==0&&dcmp(y-a.y)<0);
    }
    bool operator ==(const Point &a)const
    {
    	return dcmp(x-a.x)==0&&dcmp(y-a.y)==0;
    }
    void input(){scanf("%lf%lf",&x,&y);}
    void output(){printf("%.4f %.4f\n",x,y);}
};
typedef Point Vector;
struct Circle{
    Point o;
    double r;
    Circle(){}
    Circle(Point a,double b):o(a),r(b){}
    Point point(double a)
    {
        return Point(o.x+cos(a)*r,o.y+sin(a)*r);
    }
};
struct Rain{
    double x,y,r,h;
    Point a,b,c;
    void input()
    {
        scanf("%lf%lf%lf%lf",&x,&y,&r,&h);
        a = Point(x,y+h);
        b = Point(x-r,y);
        c = Point(x+r,y);
    }
}rain;
pair<double,double> ans[3005];
int an;

double cross(Vector a,Vector b)
{
    return a.x*b.y-a.y*b.x;
}
double dot(Vector a,Vector b)
{
    return a.x*b.x+a.y*b.y;
}
double sqr(double x)
{
    return x*x;
}

double length(Vector a)
{
    return sqrt(dot(a,a));
}
double dist(Point a,Point b)
{
    return length(a-b);
}
bool onseg(Point p,Point a,Point b)
{
    return dcmp(dist(a,p)+dis(p,b)-dist(a,b))==0;
	//return dcmp(cross(a-p,b-p))==0&&dcmp(dot(a-p,b-p))<=0;

}
bool ispinter(Point a, Point b, Point c, Point d)
{
	double c1 = cross(b-a,c-a),c2 = cross(b-a,d-a),
		   c3 = cross(d-c,a-c),c4 = cross(d-c,b-c);
	return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
}
bool isinter(Point s1, Point e1, Point s2, Point e2){
    if( min(s1.x, e1.x) <= max(s2.x, e2.x) &&
        min(s1.y, e1.y) <= max(s2.y, e2.y) &&
        min(s2.x, e2.x) <= max(s1.x, e1.x) &&
        min(s2.y, e2.y) <= max(s1.y, e1.y) &&
        dcmp(cross(s2-s1,e2-s1))*dcmp(cross(s2-e1,e2-e1))<=0&&
        dcmp(cross(s1-s2,e1-s2))*dcmp(cross(s1-e2,e1-e2))<=0)
        return true;
    return false;
}
Point getinter(Point a,Vector aa,Point b,Vector bb)
{
    Vector u = a-b;
    double t = cross(bb,u)/cross(aa,bb);
    return a+aa*t;
}
int inter_c_seg(Circle c,Point a, Point b, vector<Point>& sol)
{
    Vector v = b-a;
    double A = sqr(v.x)+sqr(v.y);
    double B = 2*(v.x*(a.x-c.o.x)+v.y*(a.y-c.o.y));
    double C = sqr(a.x-c.o.x)+sqr(a.y-c.o.y)-sqr(c.r);
    double delta = sqr(B)-4*A*C;
    Point p1,p2;
    if(dcmp(delta)<0) return 0;
    double k1 = (-B-sqrt(delta))/(2*A);
    double k2 = (-B+sqrt(delta))/(2*A);
    p1 = a+v*k1;
    p2 = a+v*k2;
    if(dcmp(c.o.y-p1.y)>=0&&onseg(p1,a,b))
        sol.push_back(p1);
    if(dcmp(c.o.y-p2.y)>=0&&onseg(p2,a,b))
        sol.push_back(p2);
    return sol.size();
}
double area(Point a,Point b,Point c)
{
    return fabs(cross(a-c,b-c))/2;
}
bool inrain(Point p)
{
    if(dcmp(dist(p,Point(rain.x,rain.y))-rain.r)<=0&&dcmp(p.y-rain.y)<=0) return 1;
    if(dcmp(area(rain.a,rain.b,rain.c)-area(rain.a,rain.b,p)
            -area(rain.a,rain.c,p)-area(rain.b,rain.c,p))==0) return 1;
    return 0;
}
void solve(Point s,Point e)
{
    vector<Point> vec;
    vec.clear();
    if(isinter(rain.a,rain.b,s,e))
        vec.push_back(getinter(rain.a,rain.b-rain.a,s,s-e));

    if(isinter(rain.a,rain.c,s,e))
        vec.push_back(getinter(rain.a,rain.c-rain.a,s,s-e));

    inter_c_seg(Circle(Point(rain.x,rain.y),rain.r),s,e,vec);

    if(inrain(s)) vec.push_back(s);
    if(inrain(e)) vec.push_back(e);
    sort(vec.begin(),vec.end());
	unique(vec.begin(),vec.end());

    if(vec.size()>1)
	{
		double t1 = length(vec[1]-s),t2 = length(vec[0]-s);
		if(dcmp(t1-t2)>0) swap(t1,t2);
		ans[an++] = make_pair(t1,t2);

	}

}
int main()
{
    freopen("/home/qitaishui/code/in.txt","r",stdin);
    int cas;
    double v1,v2,v,t,x;
    Point s,e;
    int n;
    scanf("%d",&cas);
    for(int ca = 1; ca <= cas; ca++)
    {
        scanf("%lf%lf%lf%lf%lf",&v1,&v2,&v,&t,&x);
        t = t+t*v1/(v2-v1);
        s = Point(x,0);
        e = s+Point(-v1,v)*t;
        scanf("%d",&n);
        an = 0;
        for(int i = 0; i < n; i++)
        {
            rain.input();
            solve(s,e);
        }
        sort(ans,ans+an);
        int c=0;
        double sum=0;
        while(c<an)
        {
            double se = ans[c].SE;
            double fi = ans[c].FI;
            c++;
            while(c<an&&dcmp(se-ans[c].FI)>=0)
            {
                se=max(se,ans[c].SE);
                c++;
            }
            sum+=se-fi;
        }
        sum/=sqrt(v1*v1+v*v);
        printf("Case %d: %.4f\n",ca,sum+EPS);
    }
    return 0;
}
