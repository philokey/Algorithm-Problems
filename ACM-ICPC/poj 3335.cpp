#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const double eps = 1e-10;
int dcmp(double x)
{
	if(fabs(x)<eps) return 0;
	return x<0? -1:1;
}
struct Point{
	double x,y;
	Point(){}
	Point(double a,double b):x(a),y(b){}
	Point operator +(const Point &a)const{return Point(x+a.x,y+a.y);}
	Point operator -(const Point &a)const{return Point(x-a.x,y-a.y);}
	Point operator *(double c)const{return Point(x*c,y*c);}
	bool operator <(const Point &a)const
	{
		return x<a.x||(x==a.x&&y<a.y);
	}
	void input(){scanf("%lf%lf",&x,&y);}
	void output(){printf("%.2f %.2f\n",x,y);}
};
typedef Point Vector;
struct Line{
	Point p;
	Vector v;
	double ang;
	Line(){}
	Line(Point a,Vector b):p(a),v(b){ang = atan2(v.x,v.y);}
	bool operator < (const Line&l)const
	{
		return ang<l.ang;
	}
};

double Cross(Vector a,Vector b)
{
	return a.x*b.y-b.x*a.y;
}
double Dot(Vector a, Vector b)
{
	return a.x*b.x+a.y*b.y;
}
bool OnLeft(Line l,Point p)
{
	return Cross(l.v,p-l.p)>=0;
}

Point GetLineinter(const Line &a,const Line &b)
{
	Vector u = a.p-b.p;
	double t = Cross(b.v,u)/Cross(a.v,b.v);
	return a.p+a.v*t;
}
double Polygonarea(Point *p,int n)
{
	double area = 0;
	for(int i = 1; i < n-1; i++)
		area+=Cross(p[i]-p[0],p[i+1]-p[0]);
	//cout<<area/2<<endl;
	return area/2;
}
int HalfPlaneInter(Line *L,int n)
{
	sort(L, L+n);
    int first, last;
    Point *p = new Point[n];
    Line* q = new Line[n];
    q[first=last=0] = L[0];
    for(int i = 1; i < n; i++)
    {
        while(first < last && !OnLeft(L[i], p[last-1])) last--;
        while(first < last && !OnLeft(L[i], p[first])) first++;
        q[++last] = L[i];
        if(dcmp(Cross(q[last].v, q[last-1].v)) == 0)
        {
            last--;
            if(OnLeft(q[last], L[i].p)) q[last] = L[i];
        }
        if(first < last) p[last-1] = GetLineinter(q[last-1], q[last]);
    }
    while(first < last && !OnLeft(q[first], p[last-1])) last--;
    for(int i = first; i < last; i++)
		p[i].output();
	return last-first>1;
}

int main()
{
	freopen("in.txt","r",stdin);
	int t,n;
	scanf("%d",&t);
	Point p[1005];
	Line l[105];
	while(t--)
	{
		scanf("%d",&n);
		for(int i = 0; i < n; i++)
			p[i].input();
		p[n] = p[0];
		if(Polygonarea(p,n)<0)
			for(int i = 0; i < n; i++)
				l[i] = Line(p[i],p[i]-p[i+1]);
		else
			for(int i = 0; i < n; i++)
				l[i] =Line(p[i],p[i+1]-p[i]);
		if(HalfPlaneInter(l,n))
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}





