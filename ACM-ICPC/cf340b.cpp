#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int MAXN = 305;
const int INF = 1111111111;
const double EPS = 1e-8;

inline int dcmp(double x)
{
	if(fabs(x)<EPS) return 0;
	return x < 0? -1:1;
}
struct Point{
    double x,y;
    Point() {} ;
    Point (double a , double b) : x(a) , y(b) {}
    Point operator * (double c) {return Point (x * c , y * c );}
	Point operator - (const Point a) {return Point (x - a.x , y - a.y );}
	Point operator + (const Point a) {return Point (x + a.x , y + a.y );}
	void input(){scanf("%lf%lf",&x,&y);}

}p[MAXN];
typedef Point Vector;
inline double Cross(Vector a,Vector b)
{
	return a.x*b.y-a.y*b.x;
}
inline double Dot(Vector a,Vector b)
{
	return a.x*b.x+a.y*b.y;
}
inline double Length(Vector a)
{
	return sqrt(Dot(a,a));
}

inline double Distoline(Point p, Point a, Point b)
{
	Vector v1 = b-a, v2 = p -a;
	return fabs(Cross(v1,v2))/Length(v1);
}

int main()
{
    //freopen("F:\\acmcode\\in.txt","r",stdin);
    int n,a,b;
    double u,v,ans=0;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        p[i].input();
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
        {
            a=b=-1;
            u=v=0;
            for(int k = 0; k < n; k++)
            {
                if(k==i||k==j) continue;
                double tmp = Distoline(p[k],p[i],p[j]);
                if(dcmp(Cross(p[j]-p[i],p[k]-p[i]))<0)
                {
                    if(dcmp(u-tmp)<0)
                       u=tmp,a=k;
                }
                else
                {
                    if(dcmp(v-tmp)<0)
                       v=tmp,b=k;
                }
            }
            if(a==-1||b==-1) continue;
            double len=Length(p[i]-p[j]);
            ans=max(ans,len*(u+v));
        }
    printf("%.10f\n",ans/2);
    return 0;
}
