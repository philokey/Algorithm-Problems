#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const int MAXN = 105;
const int INF = 1111111111;
struct Point{
	int x,y;
	Point(){}
	Point(int a,int b):x(a),y(b){}
	Point operator+(const Point&a)const{return Point(x+a.x,y+a.y);}
	Point operator-(const Point&a)const{return Point(x-a.x,y-a.y);}
	void input(){scanf("%d%d",&x,&y);}
}p[MAXN];
typedef Point Vector;
int cross(Vector a,Vector b)
{
	return a.x*b.y-a.y*b.x;
}
double area(int n)
{
	double area = 0;
	for(int i = 1; i < n-1; i++)
		area+=cross(p[i]-p[0],p[i+1]-p[0]);
	return abs(area)/2;
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	double a,b,s;
	int cas,n;
	scanf("%d",&cas);
	for(int ca = 1; ca<=cas; ca++)
	{
		if(ca>1) printf("\n");
		printf("Scenario #%d:\n",ca);
		scanf("%d",&n);
		p[0].input();
		for(int i = 1; i < n; i++)
		{
			p[i].input();
			p[i]=p[i]+p[i-1];
		}

		p[n] = p[0];
		b = 0;
		for(int i = 0; i < n;i++)
			b+=__gcd(abs(p[i].x-p[i+1].x),abs(p[i].y-p[i+1].y));
		s = area(n);
		a = s-b/2+1;
		printf("%.0f %.0f %.1f\n",a,b,s);

	}
	return 0;
}
