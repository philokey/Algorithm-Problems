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
const int MAXN = 1005;
const int INF = 1111111111;
const double PI = acos(-1.0);
int dcmp(double x)
{
	if(fabs(x)<EPS) return 0;
	else return x < 0? -1:1;
}
double r = 1;
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
	void input(){scanf("%lf%lf",&x,&y);}
	void output(){printf("%.2f %.2f\n",x,y);}
}p[MAXN];
double dist(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
Point find_center(Point a,Point b)
{
    Point mid=(a+b)/2;
    double angle=atan2(a.x-b.x,b.y-a.y);
    double d=sqrt(1-dist(a,mid)*dist(a,mid));
    return Point(mid.x+d*cos(angle),mid.y+d*sin(angle));
}
int main()
{
    //freopen("/home/qitaishui/code/in.txt","r",stdin);
    int n,ans,cnt;
    double tmp;
    Point center;
    while(scanf("%d",&n)&&n)
    {
        for(int i = 0; i < n; i++)
            p[i].input();
        ans = 1;
        for(int i = 0; i < n; i++)
            for(int j = i+1; j<n; j++)
            {
                if(dcmp(dist(p[i],p[j])-2*r)>0) continue;
                cnt = 0;
                center = find_center(p[i],p[j]);
                for(int k = 0; k < n; k++)
                    if(dcmp(dist(p[k],center)-r)<=0) cnt++;
                ans = max(ans,cnt);
            }
        printf("%d\n",ans);
    }
    return 0;
}
