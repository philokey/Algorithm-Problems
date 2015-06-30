//转化到二维平面，不能用三角形面积算点到直线的距离，因为是线段，例如
/*
1 2 0
3 3 0
0 0 0
2 用三角形面积就会错。所以直接用角度就好
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-6;
const int MAXN = 10005;
const double PI = acos(-1.0);
const int INF = 1111111111;
int dcmp(double x)
{
	if(fabs(x)<EPS) return 0;
	return x<0?-1:1;
}
struct Point3{
	double x,y,z;
	Point3(){}
	Point3(double a,double b,double c):x(a),y(b),z(c){}
	void input(){scanf("%lf%lf%lf",&x,&y,&z);}
};
double dist(Point3 a,Point3 b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}
double area(double a,double b,double c)
{
	double p = (a+b+c)/2.0;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	Point3 a,b,c;
	double r,ac,bc,ab,len=0,the;
	a.input();
	b.input();
	c.input();
	scanf("%lf",&r);
	ac = dist(a,c);
	ab = dist(a,b);
	bc = dist(b,c);

	len+=sqrt(ac*ac-r*r)+sqrt(bc*bc-r*r);
	double tha = acos(r/ac), thb = acos(r/bc),thc =  acos((ac*ac+bc*bc-ab*ab)/(2*ac*bc));
	the = thc-tha-thb;
	len += r*the;
	if(dcmp(tha+thb-thc)>=0) printf("%.2f",ab);
	else
		printf("%.2f\n",len);

	return 0;
}
