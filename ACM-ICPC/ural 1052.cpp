#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 305;
const double eps = 1e-8;
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
	void input(){scanf("%lf%lf",&x,&y);}
	void output(){printf("%.2f %.2f\n",x,y);}
};
typedef Point Vector;
double Cross(Vector a,Vector b)
{
	return a.x*b.y-a.y*b.x;
}
double Dot(Vector a, Vector b)
{
	return a.x*b.x+a.y*b.y;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int n,ans,tmp;
	Point p[305];
	Vector v;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		p[i].input();
	ans = 2;
	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n;j++)
		{
			v = p[j]-p[i];
			tmp = 2;
			for(int k = 0; k < n; k++)
			{
				if(k==i||k==j) continue;
				if(dcmp(Cross(v,p[k]-p[i]))==0) tmp++;
			}
			ans = max(ans,tmp);
		}
	printf("%d\n",ans);
	return 0;
}






