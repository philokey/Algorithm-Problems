#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const double EPS = 1e-6;
const double PI = acos(-1.0);
const int MAXN = 1005;
int dcmp(double x)
{
    if(fabs(x)<EPS) return 0 ;
    return x<0?-1:1;
}
struct Point{
    double x,y;
    Point(){}
    Point(double a,double b):x(a),y(b){}
};
double length(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double get(double a,double b,double c)
{
    return acos((a*a+b*b-c*c)/(2*a*b))*2;
}
bool check(double a,double b)
{
    if(dcmp(a/b-(int)(a/b+EPS))==0) return 1;
    return 0;
}
int main()
{
    //freopen("/home/qitaishui/code/in.txt","r",stdin);
    Point p[5];
    double len[5],ang[5];
    int ans;
    while(scanf("%lf%lf",&p[0].x,&p[0].y)==2)
    {
        scanf("%lf%lf",&p[1].x,&p[1].y);
        scanf("%lf%lf",&p[2].x,&p[2].y);
        p[3] = p[0];
        for(int i = 0; i < 3; i++)
            len[i] = length(p[i],p[i+1]);

        ang[0] = get(len[0],len[1],len[2]);
        ang[1] = get(len[1],len[2],len[0]);
        ang[2] = get(len[2],len[0],len[1]);
        for(ans = 3; ans<=1000; ans++)
        {
            double tmp = 2*PI/ans;
            if(check(ang[0],tmp)&&check(ang[1],tmp)&&check(ang[2],tmp))
                break;
        }
        printf("%d\n",ans);
    }
    return 0;
}

