#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
const double eps = 1e-8;
const int maxn = 3005;
const double PI = acos(-1.0);
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
double Angle(Vector a,Vector b)
{
	return acos(Dot(a,b)/Length(a)/Length(b));
}
double Area2(Point a, Point b, Point c)
{
	return Cross(b-a,c-a);
}

double Getdis(Point p1, Point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}
Vector Rotate(Vector a,double rad)
{
	Vector c;
	c.x = a.x*cos(rad)-a.y*sin(rad);
	c.y = a.x*sin(rad)+a.y*cos(rad);
	return c;
}

double Polygonarea(Point *p,int n)
{
	double area = 0;
	for(int i = 1; i < n-1; i++)
		area+=Cross(p[i]-p[0],p[i+1]-p[0]);
	return area/2;
}
int ConvexHull(Point *p,int n,Point *ch)
{
	sort(p,p+n);
	n = unique(p,p+n) - p;
	int m = 0;
	for(int i = 0; i < n; i++)
	{
		while(m > 1&&dcmp(Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]))<=0) m--;
		ch[m++] = p[i];
	}
	int k = m;
	for(int i = n-1; i >=0; i--)
	{
		while(m>k&&dcmp(Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]))<=0) m--;
		ch[m++] = p[i];
	}
	if(n > 1) m--;
	return m;
}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,ca,pn;
	double w,h,rad,s1,s2;
	Point o,p[maxn],ch[maxn];
	scanf("%d",&ca);
	//cout<<PI<<endl;
	while(ca--)
	{
		scanf("%d",&n);
		pn = 0;
		s1 = s2 = 0;
		for(int i = 0; i < n; i++)
		{
			o.input();
			scanf("%lf%lf%lf",&w,&h,&rad);
			s1+=w*h;
			rad = -rad/180.0*PI;
			p[pn++] = o+Rotate(Point(-w/2,h/2),rad);
			p[pn++] = o+Rotate(Point(w/2,h/2),rad);
			p[pn++] = o+Rotate(Point(w/2,-h/2),rad);
			p[pn++] = o+Rotate(Point(-w/2,-h/2),rad);
		}
		n = ConvexHull(p,pn,ch);
		s2 = Polygonarea(ch,n);
		//cout<<s1<<" "<<s2<<endl;
		printf("%.1f %%\n",s1/s2*100);
	}
	return 0;
}
