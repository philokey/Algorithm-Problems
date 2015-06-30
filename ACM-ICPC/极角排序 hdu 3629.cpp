/*
题意：给出平面上的n个点，无三点共线，求可以构成的凸四边形的个数。
解法：凹四边形比凸四边形好找，所以找凹四边形。对于四个点，如果三个点构成三角形且有一个点在三角形内部，则可以组成凹四边形。于是可以枚举三角形内部的点，以该点为中心进行极角排序，在中心点一侧的点构成的三角形都不能与中心点构成凹四边形。扫一遍剩余点，即可。
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
const double EPS = 1e-10;
const int MAXN = 5005;
const int INF = 1111111111;
const double PI = acos(-1.0);
typedef long long LL;
int dcmp(double x)
{
    if(fabs(x)<EPS) return 0;
    return x<0?-1:1;
}
struct Point{
    double x,y;
    void input(){scanf("%lf%lf",&x,&y);}
}p[MAXN];

bool cmp(double a,double b)
{
    return dcmp(a-b)<0;
}
double ang[MAXN];
int main()
{
    //freopen("/home/qitaishui/code/in.txt","r",stdin);
    int n;
    int ca;
    LL ans,sub,tri;
    scanf("%d",&ca);
    while(ca--)
    {
        sub = 0;
        scanf("%d",&n);
        ans = (LL)n*(n-1)*(n-2)*(n-3)/24;
        tri = (n-1)*(n-2)*(n-3)/6;
        for(int i = 0; i < n;i++)
            p[i].input();
        int m;
        for(int i = 0;i < n; i++)
        {
            m = 0;
            for(int j = 0; j < n; j++)
            {
                if(i==j) continue;
                ang[m++] = atan2(p[j].y-p[i].y,p[j].x-p[i].x);
            }
            sort(ang,ang+m,cmp);
            for(int i = 0; i < m;i++)
                ang[i+m]=2*PI+ang[i];
            int l,r,s;
            l = 0;
            s = r = 1;
            //LL tmp=0;
            tri = (n-1)*(n-2)*(n-3)/6;
            while(l < m)
            {
                while(dcmp(ang[l]+PI-ang[r])>=0)
                    r++;
                s = r-l-1;
                if(s>=2)
                    tri-=(s-1)*s/2;
                l++;
            }
            sub+=tri;
        }
        cout<<ans-sub<<endl;
    }
    return 0;
}
