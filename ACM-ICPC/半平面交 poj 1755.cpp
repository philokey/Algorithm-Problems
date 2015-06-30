#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
using namespace std;
const double eps = 1e-8;
const int maxn = 305;
int dcmp(double x)
{
	if(fabs(x)<eps) return 0;
	return x<0? -1:1;
}
struct Point{
	double x,y;
	Point(){}
	Point(double a,double b):x(a),y(b){}
	Point operator+(const Point &a)const{return Point(x+a.x,y+a.y);}
	Point operator-(const Point &a)const{return Point(x-a.x,y-a.y);}
	Point operator*(double a)const{return Point(x*a,y*a);}
	void input(){scanf("%lf%lf",&x,&y);}
};
typedef Point Vector;
struct Line{
	Point p;
	Vector v;
	double ang;
	Line(){}
	Line(Point a,Vector b):p(a),v(b){ang = atan2(v.y,v.x);}
	bool operator<(const Line&a)const{return ang<a.ang;}
};
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
bool OnLeft(Line l, Point p)
{
	return Cross(l.v,p-l.p)>0;
}
Point GetLineinter(Line a,Line b)
{
	Vector u = a.p-b.p;
    double t = Cross(b.v, u) / Cross(a.v, b.v);
    return a.p+a.v*t;
}
int HalfPlaneInter(Line *l,int n)
{
	sort(l,l+n);
	int first,last;
	Point p[maxn];
	Line q[maxn];
	q[first=last=0] = l[0];
	for(int i = 0; i < n; i++)
	{
		while(first<last&&!OnLeft(l[i],p[last-1])) last--;
		while(first<last&&!OnLeft(l[i],p[first])) first++;
		q[++last] = l[i];
		if(dcmp(Cross(q[last].v,q[last-1].v))==0)
		{
			last--;
			if(OnLeft(q[last],l[i].p)) q[last] = l[i];
		}
		if(first<last) p[last-1] = GetLineinter(q[last],q[last-1]);
	}
	while(first<last&&!OnLeft(q[first],p[last-1])) last--;
	return last-first>1;
}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,u[maxn],v[maxn],w[maxn];
	Point p;
	Line l[maxn];
	while(scanf("%d",&n)!=EOF)
	{
		for(int i = 0; i < n; i++)
			scanf("%d%d%d",&v[i],&u[i],&w[i]);
		for(int i = 0; i < n; i++)
		{
			int lc = 0;
			bool flag = 1;
			double k = 10000;
			for(int j=0; j<n; j++)
			{
				if(i==j) continue;
				if(v[i]<=v[j]&&u[i]<=u[j]&&w[i]<=w[j]){flag = 0;break;}
				if(v[i]>v[j]&&u[i]>u[j]&&w[i]>w[j]){continue;}
				double a = (k/v[j]-k/w[j])-(k/v[i]-k/w[i]);
				double b = (k/u[j]-k/w[j])-(k/u[i]-k/w[i]);
				double c = k/w[j]-k/w[i];
				Vector v(b,-a);
				if(dcmp(fabs(a)-fabs(b))>0) p = Point(-c/a,0);
				else p = Point(0,-c/b);
				l[lc++] = Line(p,v);
			}
			if(flag)
			{
				//cout<<"**\n";
				l[lc++] = Line(Point(0,0),Vector(0,-1));
				l[lc++] = Line(Point(0,0),Vector(1,0));
				l[lc++] = Line(Point(0,1),Vector(-1,1));
				if(!HalfPlaneInter(l,lc)) flag = 0;
			}
			if(flag==0) printf("No\n");
			else printf("Yes\n");
		}
	}
	return 0;
}
