#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 305;
const double eps = 1e-8;
const double pi = acos(-1.0);
int dcmp(double x)
{
	if(fabs(x)<eps) return 0;
	return x < 0? -1:1;
}
struct Point{
	double x,y;
	Point(){};
	Point(double a,double b):x(a),y(b){}
	Point operator +(const Point &a)const{return Point(x+a.x,y+a.y);}
	Point operator -(const Point &a)const{return Point(x-a.x,y-a.y);}
	Point operator *(double c)const{return Point(x*c,y*c);}
	bool operator <(const Point &a)const
	{
		return x<a.x||(x==a.x&&y<a.y);
	}
	bool operator ==(const Point &a)const
	{
		return dcmp(x-a.x)==0&&dcmp(y-a.y)==0;
	}
	void input(){scanf("%lf%lf",&x,&y);}
	void output(){printf("%.2f %.2f\n",x,y);}
};
typedef Point Vector;
struct Square{
	Point p[4];
	double len;
	int id;
	bool operator <(const Square&a)const
	{
		return len<a.len||(len==a.len&&id<a.id);
	}
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

Vector Rotate(Vector a,double rad)
{
	Vector c;
	c.x = a.x*cos(rad)-a.y*sin(rad);
	c.y = a.x*sin(rad)+a.y*cos(rad);
	return c;
}

double Distoseg(Point p,Point a,Point b)
{
	if(a==b) return Length(p-a);
	Vector v1 = b-a, v2 = p-a, v3 = p-b;
	if(dcmp(Dot(v1,v2))<0) return Length(v2);
	if(dcmp(Dot(v1,v2))>0) return Length(v3);
	return fabs(Cross(v1,v2))/Length(v1);
}
int main()
{
	//freopen("in.txt","r",stdin);
	Point p,mid;
	Square s[55];
	Vector v;
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n; i++)
	{
		s[i].p[0].input();
		s[i].p[2].input();
		s[i].id = i+1;

		mid = (s[i].p[0]+s[i].p[2])*0.5;
		//mid.output();
		//cout<<"**\n";
		v = s[i].p[0]-mid;
		s[i].p[1] = mid+Rotate(v,pi/2);
		s[i].p[3] = mid+Rotate(v,-pi/2);
		//for(int j = 0; j < 4; j++)
			//s[i].p[j].output();
	}
	p.input();


	for(int i = 0; i < n; i++)
	{

		int cnt = 0;
		for(int j = 0; j < 4; j++)
			if(Cross(s[i].p[(j+1)%4]-s[i].p[j],p-s[i].p[(j+1)%4])>0) cnt++;
		if(cnt==4){s[i].len = 0;continue;}
		double dis = 111111111;
		for(int j = 0; j < 4; j++)
			dis = min(dis,Distoseg(p,s[i].p[j],s[i].p[(j+1)%4]));
		s[i].len = dis;
	}
	//for(int i = 0; i < n; i++)
		//cout<<s[i].len<<endl;
	sort(s,s+n);
	for(int i = 0; i < n; i++)
		if(i==0) printf("%d",s[i].id);
		else printf(" %d",s[i].id);
	printf("\n");
	return 0;
}

