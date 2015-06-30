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
const double INF = 1e40;
const double PI = acos(-1.0);
int dcmp(double x)
{
	if(fabs(x)<EPS) return 0;
	return x<0?-1:1;
}
double sqr(double x){return x*x;}
struct Point{
	double x,y,pa;
	int cnt;
	Point(){}
	Point(double a,double b):x(a),y(b){}
	Point(double a,double b,double c,int d):x(a),y(b),pa(c),cnt(d){}
	Point operator+(const Point &a)const{return Point(x+a.x,y+a.y);}
	Point operator-(const Point &a)const{return Point(x-a.x,y-a.y);}
	bool operator <(const Point &a)const
	{
		return pa<a.pa;
	}
	bool operator == (const Point &a)const
	{
		return dcmp(x-a.x)==0&&dcmp(y-a.y)==0;
	}
	Point trunc(double d)
    {
        double len = sqrt(x*x+y*y);
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

typedef Point Vector;
inline double cross(Vector a,Vector b)
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
Vector rotate(Vector a,double rad)//逆时针旋转弧度rad
{
	Vector c;
	c.x = a.x*cos(rad)-a.y*sin(rad);
	c.y = a.x*sin(rad)+a.y*cos(rad);
	return c;
}
int inter_c_and(Circle c1,Circle c2,Point &p1,Point &p2)
{
	Vector v = c2.o-c1.o;
	double len = length(v);
	if(dcmp(len-c1.r-c2.r)>0) return 0;

	double s = (sqr(c1.r)-sqr(c2.r)+sqr(len))/len/2;
	double h = sqrt(sqr(c1.r)-sqr(s));
	Point p0 = c1.o+v.trunc(s);

	p1 = p0+rotate(v,PI/2).trunc(h);
	p2 = p0-rotate(v,PI/2).trunc(h);
	return 1;
}
Point base ;
int cmp ( const Point a , const Point b )
{
	return atan2(a.y-base.y,a.x-base.x) < atan2(b.y-base.y,b.x-base.x);
}
double arc_area(Point a,Point b,Circle c)
{
	double theta = v_angle(a-c.o,b-c.o);
	double sf = sqr(c.r)*theta/2;
	double st = sqr(c.r)*sin(theta)/2;
	if(dcmp(cross(a-c.o,b-c.o))>0) return sf - st;
	else return c.area()-sf+st;
}
double arc_area(double th,double r)
{
	return 0.5*sqr(r)*(th-sin(th));
}
int inner_c(Circle a, Circle b)
{
	if(dcmp(a.r-b.r)>0) return 0;
	return dcmp(dist(a.o,b.o)+a.r-b.r)<=0;
}
struct Circles{
	int n;
	Circle c[MAXN];
	Circles():n(0){}
	void add(Circle cc){c[n++] = cc;}
	void clear(){n = 0;}
	//初始化圆的面积交,去掉能把其他圆覆盖的圆
	void init_and()
	{
		bool mark[MAXN] = {0};
		int cnt = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(i!=j&&!mark[j]&&inner_c(c[j],c[i]))
					{
						mark[i] = 1;
						break;
					}
		for(int i = 0; i < n; i++)
			if(!mark[i]) c[cnt++] = c[i];
		n = cnt;
	}

	//判断点是否被其他圆覆盖
	int isvalid_and(Point a)
	{
		for(int i = 0; i < n; i++)
			if(dcmp(dist(a,c[i].o)-c[i].r)>0)
				return 0;
		return 1;
	}
	//判断圆弧是否被其他圆覆盖
	int isvalid_and(Point a,Point b,int num)
	{
		Point v,p;
		int i;
		v = a-b;
		p = c[num].o+rotate(v,PI/2).trunc(c[num].r);
		return isvalid_and(p);
	}

	//计算圆的面积交,若交集为空,返回-1.0,若交集为一点,保存交点到res中
	double area_and(Point &res)
	{
		vector<Point> s[MAXN];
		Point a,b;
		double sa=0,sp=0;
		init_and();
		if(n==1) return c[0].area();
		for(int i = 0; i < n; i++)
			for(int j = i+1; j < n; j++)
				if(inter_c_and(c[i],c[j],a,b))
				{
					s[i].push_back(a);
					s[i].push_back(b);
					s[j].push_back(a);
					s[j].push_back(b);
				}
				else -1.0;
		for(int i = 0; i < n; i++)
		{
			base = c[i].o;
			sort(s[i].begin(),s[i].end(),cmp);
			s[i].resize(unique(s[i].begin(),s[i].end())-s[i].begin());
			if(s[i].front()==s[i].back()) s[i].pop_back();
			if(s[i].size()==1)
			{
				if(isvalid_and(s[i][0])) res = s[i][0];
				continue;
			}
			for(int j = 0; j < s[i].size(); j++)
			{
				if(isvalid_and(s[i][j]))
					res = s[i][j];
				int k = (j+1)%s[i].size();
				if(isvalid_and(s[i][j],s[i][k],i))
				{
					sa+=arc_area(s[i][j],s[i][k],c[i]);
					sp+=cross(s[i][j]-Point(0,0),s[i][k]-Point(0,0));
				}
			}
		}
		return sa+fabs(sp)/2.0;
	}

};
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	double r,ans;
	Circles c;
	Point p;
	while(scanf("%lf",&r)!=EOF)
	{
		for(int i = 0; i < 5; i++)
		{
			c.c[i].o.input();
			c.c[i].r = r;
		}
		c.n = 5;
		p = Point(INF,INF);
		ans = c.area_and(p);
		if(dcmp(ans)>0)
			printf("The total possible area is %.2f.\n",ans+EPS);
		else if(p==Point(INF,INF))
			printf("Poor iSea, maybe 2012 is coming!\n");
		else
			printf("Only the point (%.2f, %.2f) is for victory.\n",p.x+EPS,p.y+EPS);
	}
	return 0;
}

