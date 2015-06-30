//注意符号啊啊！
//计算两块木板围城的槽最大可以接到垂直降落的水的容量
//最难写的地方是一块木板遮住另一块的口，但其实可以用斜率判断
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
const double eps = 1e-8;
int dcmp(double x)
{
	if(fabs(x)<eps) return 0;
	else return x < 0? -1:1;
}
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
	bool operator <(const Point &a)const
	{
		return x<a.x||(x==a.x&&y<a.y);
	}
	void input(){scanf("%lf%lf",&x,&y);}
	void output(){cout<<x<<" "<<y<<endl;}
};
typedef Point Vector;
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
Point Getinter(Point a,Vector aa,Point b,Vector bb)//要保证两条直线有唯一交点
{
	Vector u = a-b;
	double t = Cross(bb,u)/Cross(aa,bb);
	return a+aa*t;
}

bool Isinter(Point s1, Point e1, Point s2, Point e2){
    if( min(s1.x, e1.x) <= max(s2.x, e2.x) &&
        min(s1.y, e1.y) <= max(s2.y, e2.y) &&
        min(s2.x, e2.x) <= max(s1.x, e1.x) &&
        min(s2.y, e2.y) <= max(s1.y, e1.y) &&
        dcmp(Cross(s2-s1,e2-s1))*dcmp(Cross(s2-e1,e2-e1))<=0&&
        dcmp(Cross(s1-s2,e1-s2))*dcmp(Cross(s1-e2,e1-e2))<=0)
        return true;
    return false;
}

double Area2(Point a, Point b, Point c)//三角形面积的两倍
{
	return Cross(b-a,c-a);
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out1.txt","w",stdout);
	Point a,b,c,d,p,e,f;
	int ca,cnt;
	bool flag;
	scanf("%d",&ca);
	for(int i = 0; i < ca; i++)
	{

		flag = 1;
		cnt = 0;
		a.input();b.input();c.input();d.input();

		if(dcmp(Cross(b-a,d-c))==0||!Isinter(a,b,c,d))
		{
			printf("0.00\n");
			continue;
		}
		p = Getinter(a,b-a,c,d-c);
		double ke,kf;
		if(a.y>p.y) e = a,cnt++;
		if(b.y>p.y) e = b,cnt++;
		if(c.y>p.y) f = c,cnt++;
		if(d.y>p.y) f = d,cnt++;
		if(cnt!=2) flag = 0;
		else if(f.x-p.x!=0&&e.x-p.x!=0)
        {
            ke = (e.y-p.y)/(e.x-p.x);
            kf = (f.y-p.y)/(f.x-p.x);
            if(ke*kf>0)
            {
                if((ke<kf&&e.x<f.x+eps)||(ke>kf&&e.x+eps>f.x)) flag = 0;
            }
        }
		//if(flag&&((e.y>f.y&&e.x>=f.x)&&dcmp(Cross(e,f))<0)) flag = 0;
		//if(flag&&((f.y>e.y&&f.x>=e.x)&&dcmp(Cross(f,e))<0)) flag = 0;
		if(!flag)
		{
			printf("0.00\n");
			continue;
		}
		double ans;
		if(e.y<f.y)
        {
            a = Getinter(e,Point(1,0),f,p-f);
            ans = Area2(a,p,e)/2;
        }
        else
        {
            a = Getinter(f,Point(1,0),e,p-e);
            ans = Area2(a,p,f)/2;
        }

		printf("%.2f\n",fabs(ans));
	}
	return 0;
}
