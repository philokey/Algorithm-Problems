#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
const double eps = 1e-10;
const int maxn = 35;
int dcmp(double x)
{
	if(fabs(x)<eps) return 0;
	else return x < 0? -1:1;
}
struct Point{
	double x,y;
	Point(){};
	Point (double a,double b):x(a),y(b){};
	Point operator - (const Point &a)const {return Point (x - a.x , y - a.y );}
	bool operator == (const Point &a)const
	{
		return dcmp(x-a.x)==0&&dcmp(y-a.y)==0;
	}
	void input()
	{
		scanf("%lf%lf",&x,&y);
	}
	void output()
	{
		printf("%.2lf %.2lf\n",x,y);
	}
};
typedef Point Vector;
double Cross(Vector a, Vector b)
{
	return a.x*b.y-a.y*b.x;
}
double Dot(Vector a, Vector b)
{
	return a.x*b.x+a.y*b.y;
}
bool Onseg(Point p, Point a, Point b)
{
	return dcmp(Cross(a-p,b-p))==0&&dcmp(Dot(a-p,b-p))<=0;
}
int Ispinpoly(Point p, Point *poly,int n)
{
	int wn = 0;
	for(int i = 0; i < n; i++)
	{
		const Point p1 = poly[i],p2 = poly[(i+1)%n];
		if(Onseg(p,p1,p2)) return 1;
		int k = dcmp(Cross(p2-p1, p-p1));
        int d1 = dcmp(p1.y - p.y);
        int d2 = dcmp(p2.y - p.y);
        if(k > 0 && d1 <= 0 && d2 > 0) wn++;
        if(k < 0 && d2 <= 0 && d1 > 0) wn--;
	}
	if(wn!=0) return 1;
	else return 0;
}
double judge(Point p,Point a,Point b)
{
	if(p==a||p==b||Point(a.x,b.y)==p||Point(b.x,a.y)==p)
		return 4.0;
	if(dcmp(p.x-a.x)==0||dcmp(p.x-b.x)==0||dcmp(p.y-a.y)==0||dcmp(p.y-b.y)==0)
        return 2.0;
	return 1.0;
}
int main()
{
	freopen("in.txt","r",stdin);
	Point p,q,poly[maxn],tmp;
	int n,a,b,cnt;
	while(scanf("%lf%lf",&p.x,&p.y)!=EOF)
	{
		cnt = 0;
		q.input();
		scanf("%d%d%d",&n,&a,&b);
		for(int i = 0; i < n; i++)
		{
			poly[i].input();
		}
		double ans = 0;
		for(int i = (int)p.x; i <= (int)q.x; i++)
			for(int j = (int)p.y; j <= (int)q.y; j++)
			{
				tmp.x = i,tmp.y = j;
				if(Ispinpoly(tmp,poly,n))
                {
                    //ans+=(a*i+b*j)/judge(tmp,p,q);
                    double l=max(i-0.5,p.x),r=min(i+0.5,q.x);
                    double d=max(j-0.5,p.y),u=min(j+0.5,q.y);
                    ans+=(r-l)*(u-d)*(a*i+b*j);
                }
			}
		printf("%.3f\n",ans/((q.x-p.x)*(q.y-p.y))+eps);

	}
	return 0;
}
