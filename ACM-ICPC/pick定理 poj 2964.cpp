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
const int MAXN = 10005;
const int INF = 1111111111;
struct Point{
	int x,y;
	Point(){}
	Point(int a,int b):x(a),y(b){}
	Point operator-(const Point&a)const{return Point(x-a.x,y-a.y);}
	void input(){scanf("%d%d",&x,&y);}
}a,b,c;
int cross(Point a,Point b)
{
	return a.x*b.y-a.y*b.x;
}
double area(Point a,Point b,Point c)
{
	return abs(cross(a-b,a-c))/2.0;
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	double aa,bb;
	while(1)
	{
		a.input();
		b.input();
		c.input();
		if(!(a.x||b.x||c.x||a.y||b.y||c.y)) break;
		double s = area(a,b,c);
		bb = 0;
		bb += __gcd(abs(a.x-b.x),abs(a.y-b.y));
		bb += __gcd(abs(a.x-c.x),abs(a.y-c.y));
		bb += __gcd(abs(c.x-b.x),abs(c.y-b.y));
		aa = s-bb/2+1;
		printf("%.0f\n",aa);
	}
	return 0;
}
