#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
const double EPS = 1e-10;
const double PI = acos(-1.0);
const int MAXN = 55;

int dcmp(double x)
{
    if(fabs(x)<EPS) return 0;
    return x<0? -1:1;
}
double sqr(double x)
{
    return x*x;
}
struct Point{
    double x,y;
    bool tp;
    int id;
    Point(){}
    Point(double a,double b):x(a),y(b){}
    Point operator +(const Point &a)const{return Point(x+a.x,y+a.y);}
    Point operator -(const Point &a)const{return Point(x-a.x,y-a.y);}
    Point operator *(double k) const{return Point(x*k,y*k);}
    Point operator /(double k) const{return Point(x/k,y/k);}
    bool operator <(const Point &a)const
    {
        return dcmp(x-a.x)<0||(dcmp(x-a.x)==0&&dcmp(y-a.y)<0);
    }
    bool operator ==(const Point &a)const
    {
        return dcmp(x-a.x)==0&&dcmp(y-a.y)==0;
    }
    Point trunc(double d)
    {
        double length(Point );
        double len = length(*this);
        return Point(x*d/len,y*d/len);
    }

    void input(){scanf("%lf%lf",&x,&y);}
};
struct Circle{
    Point o;
    double r;
    Circle(){}
    Circle(Point a,double b):o(a),r(b){}
    double area(){return sqr(r)*PI;}
    double len(double ang){return r*ang;}
};
struct Tri{
    Point p[3];
};
typedef Point Vector;
double cross(Vector a,Vector b)
{
    return a.x*b.y-a.y*b.x;
}

double dot(Vector a,Vector b)
{
    return a.x*b.x+a.y*b.y;
}
double length(Vector a)
{
    return sqrt(dot(a,a));
}
double dist(Point a,Point b)
{
    return length(a-b);
}
double v_angle(Vector a,Vector b)
{
    return acos(dot(a,b)/length(a)/length(b));
}

int ConvexHull(Point *p, int n, Point *ch)
{
    sort(p, p+n);
    n = unique(p, p+n) - p;
    int m = 0;
    for(int i = 0; i < n; i++)
    {
        while(m > 1 && dcmp(cross(ch[m-1]-ch[m-2], p[i]-ch[m-2])) <= 0) m--;
        ch[m++] = p[i];
    }
    int k = m;
    for(int i = n-2; i >= 0; i--)
    {
        while(m > k && dcmp(cross(ch[m-1]-ch[m-2], p[i]-ch[m-2])) <= 0) m--;
        ch[m++] = p[i];
    }
    if(n > 1) m--;
    return m;
}
Vector rotate(Vector a,double rad)
{
    Vector c;
    c.x = a.x*cos(rad)-a.y*sin(rad);
    c.y = a.x*sin(rad)+a.y*cos(rad);
    return c;
}
void get_ocmt(Circle c1,Circle c2,Point &s1, Point &e1,Point &s2,Point &e2)
{
    double l = dist(c1.o,c2.o);
    double d = fabs(c1.r-c2.r);
    double theta = acos(d/l);
    Vector vec = c1.o-c2.o;
    vec = vec.trunc(c1.r);
    s1 = c1.o+rotate(vec,theta);
    s2 = c1.o+rotate(vec,-theta);
    vec = vec.trunc(c2.r);
    e1 = c2.o+rotate(vec,theta);
    e2 = c2.o+rotate(vec,-theta);
}
void get_pc(Circle c, Point p,Point &s1,Point &s2)
{
    Vector u = p-c.o;
	Vector v = u.trunc(c.r);
    double dist = length(u);
    double ang = PI/2-asin(c.r/dist);
    s1 = rotate(v,-ang)+c.o;
    s2 = rotate(v,ang)+c.o;
}
Point p[55*55*55],ch[55*55*55];
int main()
{
    //freopen("/home/qitaishui/code/in.txt","r",stdin);
    int n,m,pn,chn;
    Circle c[MAXN];
    Tri tri[MAXN];

    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i = 0; i < n;i++)
        {
            c[i].o.input();
            scanf("%lf",&c[i].r);
        }
        if(n==1&&m==0)
        {
            printf("%.6f\n",c[0].len(2*PI));
            continue;
        }
        for(int i = 0; i < m; i++)
            for(int j = 0; j < 3; j++)
                tri[i].p[j].input();
        pn = 0;
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
            {
            	if(dcmp(c[i].r-c[j].r)>0)
					get_ocmt(c[j],c[i],p[pn+1],p[pn],p[pn+3],p[pn+2]);
				else
					get_ocmt(c[i],c[j],p[pn],p[pn+1],p[pn+2],p[pn+3]);
                p[pn].tp = 0,p[pn].id = i;
                p[pn+1].tp = 0,p[pn+1].id = j;
                p[pn+2].tp = 0,p[pn+2].id = i;
                p[pn+3].tp = 0,p[pn+3].id = j;
                pn+=4;
            }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                for(int k = 0; k <3; k++)
                {
                    get_pc(c[i],tri[j].p[k],p[pn],p[pn+1]);
                    p[pn].tp = 0,p[pn].id = i;
                    p[pn+1].tp = 0,p[pn+1].id = i;
                    pn+=2;
                }

        for(int j = 0; j < m; j++)
            for(int k = 0; k <3; k++)
            {
                p[pn] = tri[j].p[k];
                p[pn].tp = 1, p[pn].id = j;
                pn++;
            }

        chn = ConvexHull(p,pn,ch);
        //cout<<chn<<endl;
        int top=0;
        bool flag = 0;
        double ans = 0,cir=0;
        for(int i = 0; i <chn; i++)
        {
            if(ch[i].tp==0&&ch[(i+1)%chn].tp==0&&ch[i].id==ch[(i+1)%chn].id)
            {
                int tmp=ch[i].id;
                double ang;
                ang = v_angle(ch[i]-c[tmp].o,ch[(i+1)%chn]-c[tmp].o);
                if(dcmp(cross(ch[i]-c[tmp].o,ch[(i+1)%chn]-c[tmp].o))<0)
					ang = 2*PI-ang;
                ans=ans+c[tmp].len(ang);
            }
            else
                ans+=length(ch[i]-ch[(i+1)%chn]);
        }

        printf("%.6f\n",ans);
    }
    return 0;
}
