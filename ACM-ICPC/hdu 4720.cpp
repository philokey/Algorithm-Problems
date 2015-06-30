#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
const double EPS= 1e-8;
const double PI = acos(-1.0);
using namespace std;
int dcmp(double x)
{
    if(fabs(x)<EPS) return 0;
    return x<0?-1:1;
}
struct Point{
    double x,y;
    Point(){}
    Point(double a,double b):x(a),y(b){}
    Point operator+(const Point &a)const{return Point(x+a.x,y+a.y);}
    Point operator-(const Point &a)const{return Point(x-a.x,y-a.y);}
    Point operator/(double k)const{return Point(x/k,y/k);}
    bool operator<(const Point &a)const
    {
        return dcmp(x-a.x)==0||(dcmp(x-a.x)==0&&dcmp(y-a.y)<0);
    }
    void input(){scanf("%lf%lf",&x,&y);}
};
typedef Point Vector;
double cross(Vector a,Vector b)
{
    return a.x*b.y-a.y*b.x;
}
double dot(Vector a,Vector b)
{
    return a.x*b.x+a.y*a.y;
}
double length(Vector a)
{
    return sqrt(dot(a,a));
}
Point get(Point p1,Point p2,Point p3)
{
    double bx = p2.x-p1.x,by=p2.y-p1.y;
    double cx = p3.x-p1.x,cy=p3.y-p1.y;
    double d = 2*(bx*cy-by*cx);
    double x = (cy*(bx*bx+by*by)-by*(cx*cx+cy*cy))/d+p1.x;
    double y = (bx*(cx*cx+cy*cy)-cx*(bx*bx+by*by))/d+p1.y;
    return Point(x,y);
}
int main()
{
    //freopen("/home/moor/Code/input","r",stdin);
    int cas;
    Point a[5],o;
    double r;
    scanf("%d",&cas);
    for(int ca= 1; ca<=cas; ca++)
    {
        for(int i = 0; i < 4; i++)
            a[i].input();
        if(dcmp(cross(a[1]-a[0],a[2]-a[0]))==0)
        {
            sort(a,a+3);
            o = (a[0]+a[2])/2;
            r = length(a[0]-a[2])/2;
        }
        else
        {
            //double l1 = length(a[0]-a[1]),l2 = length(a[1]-a[2]),l3=length(a[2]-a[0]);

            if(dcmp(cross(a[1]-a[0],a[2]-a[0]))<0) swap(a[1],a[2]);

            if(dcmp(dot(a[1]-a[0],a[2]-a[0]))<0)
            {
                o = (a[1]+a[2])/2;
            }
            else if(dcmp(dot(a[2]-a[1],a[0]-a[1]))<0)
            {
                o = (a[0]+a[2])/2;
            }
            else if(dcmp(dot(a[0]-a[2],a[1]-a[2]))<0)
            {
                o = (a[0]+a[1])/2;
            }
            else
            {
                o = get(a[0],a[1],a[2]);
            }
            r = length(o-a[0]);
        }
        printf("Case #%d: ",ca);
        if(dcmp(length(a[3]-o)-r)<=0) printf("Danger\n");
        else printf("Safe\n");
    }
    return 0;
}
