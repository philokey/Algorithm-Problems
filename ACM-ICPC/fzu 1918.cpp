#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 1000005;
const int inf = 1111111111;
const double eps = 1e-10;
const double PI = acos(-1.0);
int dx[]={0,-1,0,1},dy[]={1,0,-1,0};
int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    return x<0?-1:1;
}
struct Point{
    double x,y;
    Point (){};
    Point (double a, double b):x(a),y(b){};
    Point operator + (const Point a){return Point(x+a.x,y+a.y);}
    Point operator - (const Point a){return Point(x-a.x,y-a.y);}
    Point operator * (double c) {return Point(x*c,y*c);}
    Point operator / (double c) {return Point(x/c,y/c);}
	void input(){scanf("%lf%lf",&x,&y);}
	void output(){printf("%.2f %.2f\n",x,y);}
};
typedef Point Vector;
double Cross(Vector a,Vector b)
{
	return a.x*b.y-a.y*b.x;
}
struct Node{
    double x,y;
    Node (){};
    Node (double a, double b):x(a),y(b){};
    bool operator <(const Node&a) const
    {
        return x<a.x||(x==a.x&&y<a.y);
    }
}arg[maxn];
int an;

void Find(Point q, Point p1, Point p2)
{
    double a1,a2;
    if(dcmp(Cross(p1-q,p2-q))==0) return;
    a1 = atan2(p1.y-q.y,p1.x-q.x);
    a2 = atan2(p2.y-q.y,p2.x-q.x);
    if(a2<a1) swap(a1,a2);
    if(a2 - a1 > PI)
    {
        arg[an++] = Node(a2,PI);
        arg[an++] = Node(-PI,a1);
    }
    else arg[an++] = Node(a1,a2);
}
int main()
{
    //freopen("in.txt","r",stdin);
    int cas,n,m,d;
    double len;
    char str[5];
    Point q,p1,p2;
    scanf("%d",&cas);

    for(int ca = 1; ca<=cas; ca++)
    {
        scanf("%d",&n);
        q.input();
        an = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&m);
            p1.input();
            d = 0;
            for(int j = 0; j < m; j++)
            {
                scanf("%s",str);
                //cout<<d<<"***\n";
                if(str[0]=='F')
                {
                    scanf("%lf",&len);
                    p2 = p1 + Point(dx[d],dy[d])*len;
                    Find(q,p1,p2);
                   // p2.output();
                    p1= p2;
                }
                else if(str[0]=='L') d = (d+1)%4;
                else d = (d-1+4)%4;
            }
        }
        //cout<<an<<endl;
        sort(arg,arg+an);
        double ans=0,r,l;
        l = arg[0].x,r = arg[0].y;
        ans+=r-l;
        for(int i = 1; i < an; i++)
        {
            if(dcmp(arg[i].x-r)<0)
            {
                if(dcmp(arg[i].y-r)>0)
                {
                    ans+=arg[i].y-r;
                    r= arg[i].y;
                }
            }
            else
            {
                l = arg[i].x,r = arg[i].y;
                ans+=r-l;
            }
        }
        printf("Case %d: %.2lf\n",ca,(2*PI-ans)/PI*180+eps);
    }
    return 0;
}

