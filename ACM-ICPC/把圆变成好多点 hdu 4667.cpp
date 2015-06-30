#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
const double EPS = 1e-10;
const double PI = acos(-1.0);
const int MAXN = 2005;

int dcmp(double x)
{
    if(fabs(x)<EPS) return 0;
    return x<0? -1:1;
}
double sqr(double x)
{
    return x*x;
}
struct Point{
    double x,y;
    bool tp;
    int id;
    Point(){}
    Point(double a,double b):x(a),y(b){}
    Point operator +(const Point &a)const{return Point(x+a.x,y+a.y);}
    Point operator -(const Point &a)const{return Point(x-a.x,y-a.y);}
    Point operator *(double k) const{return Point(x*k,y*k);}
    Point operator /(double k) const{return Point(x/k,y/k);}
    bool operator <(const Point &a)const
    {
        return dcmp(x-a.x)<0||(dcmp(x-a.x)==0&&dcmp(y-a.y)<0);
    }
    bool operator ==(const Point &a)const
    {
        return dcmp(x-a.x)==0&&dcmp(y-a.y)==0;
    }
    Point trunc(double d)
    {
        double dist(Point ,Point);
        double len = dist(*this,Point(0,0));
        return Point(x*d/len,y*d/len);
    }
    Point rotate(double a)
    {
        return Point(x*cos(a)-y*sin(a),y*cos(a)+x*sin(a));
    }
    void input(){scanf("%lf%lf",&x,&y);}
};
struct Circle{
    Point o;
    double r;
    Circle(){}
    Circle(Point a,double b):o(a),r(b){}
    double area(){return sqr(r)*PI;}
    double len(double ang){return r*ang;}
};
struct Tri{
    Point p[3];
};
typedef Point Vector;
double cross(Vector a,Vector b)
{
    return a.x*b.y-a.y*b.x;
}

double dot(Vector a,Vector b)
{
    return a.x*b.x+a.y*b.y;
}
double length(Vector a)
{
    return sqrt(dot(a,a));
}
double dist(Point a,Point b)
{
    return length(a-b);
}
double v_angle(Vector a,Vector b)
{
    return acos(dot(a,b)/length(a)/length(b));
}

int ConvexHull(Point *p, int n, Point *ch)
{
    sort(p, p+n);
    n = unique(p, p+n) - p;
    int m = 0;
    for(int i = 0; i < n; i++)
    {
        while(m > 1 && dcmp(cross(ch[m-1]-ch[m-2], p[i]-ch[m-2])) <= 0) m--;
        ch[m++] = p[i];
    }
    int k = m;
    for(int i = n-2; i >= 0; i--)
    {
        while(m > k && dcmp(cross(ch[m-1]-ch[m-2], p[i]-ch[m-2])) <= 0) m--;
        ch[m++] = p[i];
    }
    if(n > 1) m--;
    return m;
}
Vector rotate(Vector a,double rad)
{
    Vector c;
    c.x = a.x*cos(rad)-a.y*sin(rad);
    c.y = a.x*sin(rad)+a.y*cos(rad);
    return c;
}
void get_ocmt(Circle c1,Circle c2,Point &s1, Point &e1,Point &s2,Point &e2)
{
    double l = dist(c1.o,c2.o);
    double d = fabs(c1.r-c2.r);
    double theta = acos(d/l);
    if(dcmp(c1.r-c2.r)>0) swap(c1,c2);
    Vector vec = c1.o-c2.o;
    vec = vec.trunc(c1.r);
    s1 = c1.o+rotate(vec,theta);
    s2 = c1.o+vec.rotate(-theta);
    vec = vec.trunc(c2.r);
    e1 = c2.o+vec.rotate(theta);
    e2 = c2.o+vec.rotate(-theta);
}
void get_pc(Circle c, Point p,Point &s1,Point &s2)
{
    Vector u = p-c.o;

    double dist = length(u);
    Point v = c.o+u/dist*c.r;
    double ang = PI/2-asin(c.r/dist);
    s1 = rotate(v-c.o,-ang)+c.o;
    s2 = rotate(v-c.o,ang)+c.o;
}
Point p[MAXN*105],ch[MAXN*105];
int pn;
void get_p(Circle c)
{
	Vector vec = Vector(c.r,0);
	double del = PI/1000;
	for(int i = 0; i < 2000; i++)
		p[pn++] = c.o+vec.rotate(del*i);
}
int main()
{
    //freopen("/home/qitaishui/code/in.txt","r",stdin);
    int n,m,chn;
    Circle c;

    while(scanf("%d%d",&n,&m)!=EOF)
    {
		pn = 0;
        for(int i = 0; i < n;i++)
        {
            c.o.input();
            scanf("%lf",&c.r);
            get_p(c);
        }

        for(int i = 0; i < m; i++)
            for(int j = 0; j < 3; j++)
                p[pn++].input();

        chn = ConvexHull(p,pn,ch);

        double ans = 0;
        for(int i = 0; i <chn; i++)
			ans+=length(ch[i]-ch[(i+1)%chn]);

        printf("%.6f\n",ans);
    }
    return 0;
}
