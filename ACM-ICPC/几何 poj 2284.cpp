//题意，给出平面图，问一共把平面分割成几个面
//利用欧拉公式：V+F-E=2;其中V为点数，E为边数，F为面的个数
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
const double eps = 1e-8;
const int maxn = 505;
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
Point Getinter(Point a,Vector aa,Point b,Vector bb)//要保证两条直线有唯一交点
{
	Vector u = a-b;
	double t = Cross(bb,u)/Cross(aa,bb);
	return a+aa*t;
}
bool Ispinter(Point a, Point b, Point c, Point d)
{
	double c1 = Cross(b-a,c-a),c2 = Cross(b-a,d-a),
		   c3 = Cross(d-c,a-c),c4 = Cross(d-c,b-c);
	return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
}

bool Onseg(Point p, Point a, Point b)//点是否在线段上(非规范相交再加这个判定就可以了)
{
	return dcmp(Cross(a-p,b-p))==0&&dcmp(Dot(a-p,b-p))<0;
}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,ca=0,xn,e;
	Point p[maxn],x[maxn*maxn];
	while(scanf("%d",&n)&&n)
	{
		xn = e = n-1 ;
		for(int i = 0; i < n; i++)
		{
			p[i].input();
			x[i] = p[i];
		}

		for(int i = 0; i < n-1; i++)
			for(int j = i+1; j < n-1; j++)
				if(Ispinter(p[i],p[i+1],p[j],p[j+1]))
					x[xn++] = Getinter(p[i],p[i+1]-p[i],p[j],p[j+1]-p[j]);
		sort(x,x+xn);
		xn = unique(x,x+xn)-x;
		for(int i = 0; i < xn; i++)
			for(int j = 0; j < n-1; j++)
				if(Onseg(x[i],p[j],p[j+1])) e++;
		//cout<<e<<endl;
		printf("Case %d: There are %d pieces.\n",++ca,e+2-xn);
	}
	return 0;
}
