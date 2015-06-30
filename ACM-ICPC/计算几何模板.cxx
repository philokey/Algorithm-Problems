#include<cmath>
#include <cstdio>
#include <algorithm>
const double EPS = 1e-8;
const double PI = acos(-1.0);
using namespace std;
int dcmp(double x)
{
	if(fabs(x)<EPS) return 0;
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
	Point trunc(double d)
    {
        double len = sqrt(x*x+y*y);
        return Point(x*d/len,y*d/len);
    }
	void input(){scanf("%lf%lf",&x,&y);}
	void output(){printf("%.2f %.2f\n",x,y);}
};
typedef Point Vector;
struct Line
{
    Point p;
    Vector v;
    double ang;//极角
    Line() {}
    Line(Point p, Vector v) : p(p), v(v) {ang = atan2(v.y, v.x);}
    bool operator < (const Line& L) const
    {
        return ang < L.ang;
    }
};
struct Polygon{     //  多边形的表示。
    int n;
    Point p[15];
};
struct Circle{
	Point c;
	double r;
	Circle(Point a,double b):c(a),r(b){}
	Point point(double a)
	{
		return Point(c.x+cos(a)*r,c.y+sin(a)*r);
	}
	double area(){return PI*r*r;}
};

double sqr(double x){return x*x;}

Vector get_vector(Point a,Point b)
{
	return Point(b.x-a.x,b.y-a.y);
}
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
//求单位法向量，要保证不为零向量

Vector normal(Vector a)
{
	double l = length(a);
	return Vector(-a.y/l,a.x/l);
}
//向量a,b的夹角
double v_angle(Vector a,Vector b)
{
	return acos(dot(a,b)/length(a)/length(b));
}
//求向量极角
double angle(Vector v)
{
	return atan2(v.y,v.x);
}
double area2(Point a, Point b, Point c)//三角形面积的两倍
{
	return cross(b-a,c-a);
}
//两点间的距离：
double getdis(Point p1, Point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}
Vector rotate(Vector a,double rad)//逆时针旋转弧度rad
{
	Vector c;
	c.x = a.x*cos(rad)-a.y*sin(rad);
	c.y = a.x*sin(rad)+a.y*cos(rad);
	return c;
}

Point getinter(Point a,Vector aa,Point b,Vector bb)//要保证两条直线有唯一交点
{
	Vector u = a-b;
	double t = cross(bb,u)/cross(aa,bb);
	return a+aa*t;
}
//点到直线的距离是算构成的平行四边行的面积除以底
double distoline(Point p, Point a, Point b)
{
	Vector v1 = b-a, v2 = p -a;
	return fabs(cross(v1,v2))/length(v1);//如果不取绝对值，得到的是有向距离
}
//点到线段的距离，要判断点的投影是否在线段内
double distoseg(Point p, Point a, Point b)
{
	if(a==b) return length(p-a);
	Vector v1 = b-a, v2 = p-a, v3 = p-b;
	if(dcmp(dot(v1,v2))<0) return length(v2);
	if(dcmp(dot(v1,v3))>0) return length(v3);
	return fabs(cross(v1,v2))/length(v1);
}
//计算点p在直线ab上的投影点
/*
ab: a+tv(v为ab的向量)，p的投影q为 a+t0v
所以 dot(v,p-(a+tv0))=0 => dot(v,p-a)-t0*dot(v,v)=0;
求出t0即可求得q点
*/
Point getpro(Point p, Point a, Point b)
{
	Vector v = b-a;
	return a + v*(dot(v,p-a)/dot(v,v));
}
//规范相交

bool ispinter(Point a, Point b, Point c, Point d)
{
	double c1 = cross(b-a,c-a),c2 = cross(b-a,d-a),
		   c3 = cross(d-c,a-c),c4 = cross(d-c,b-c);
	return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
}
//非规范相交
bool isinter(Point s1, Point e1, Point s2, Point e2){
    if( min(s1.x, e1.x) <= max(s2.x, e2.x) &&
        min(s1.y, e1.y) <= max(s2.y, e2.y) &&
        min(s2.x, e2.x) <= max(s1.x, e1.x) &&
        min(s2.y, e2.y) <= max(s1.y, e1.y) &&
        dcmp(cross(s2-s1,e2-s1))*dcmp(cross(s2-e1,e2-e1))<=0&&
        dcmp(cross(s1-s2,e1-s2))*dcmp(cross(s1-e2,e1-e2))<=0)
        return true;
    return false;
}
bool onseg(Point p, Point a, Point b)//点是否在线段上(非规范相交再加这个判定就可以了)
{
	return dcmp(cross(a-p,b-p))==0&&dcmp(dot(a-p,b-p))<0;
	//return dcmp(dist(a,p)+dis(p,b)-dist(a,b))==0;0
}
double Polygonarea(Point *p,int n)//多边形有向面积,凹凸都可以,p要按顺序存储
{
	double area = 0;
	for(int i = 1; i < n-1; i++)
		area+=cross(p[i]-p[0],p[i+1]-p[0]);
	return area/2;
}
//点是否在多边形内部
//原理：过该点做一条水平向右的射线，如果正向和反向穿过的次数不等，则在外部，否则在内部
int ispinpoly(Point p, Point *poly, int n)
{
    int wn = 0;
    for(int i = 0; i < n; i++)
    {
        Point p1 = poly[i], p2 = poly[(i+1)%n];
        if(onseg(p, p1, p2)) return -1; //边界上
        int k = dcmp(cross(p2-p1, p-p1));
        int d1 = dcmp(p1.y - p.y);
        int d2 = dcmp(p2.y - p.y);
        if(k > 0 && d1 <= 0 && d2 > 0) wn++;
        if(k < 0 && d2 <= 0 && d1 > 0) wn--;
    }
    if(wn != 0) return 1;//内部
    return 0;//外部
}
/*andrew算法，graham的变种，更快更好
如果不希望有点在凸包边上，把两个<=改成<即可

*/
int ConvexHull(Point *p, int n, Point *ch) //凸包
{
    sort(p, p+n);
    n = unique(p, p+n) - p; //去重
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

//点p在有向直线l的左边（线上不算）
bool OnLeft(Line L, Point p)
{
    return cross(L.v, p-L.p) > 0;
}
//直线交点，要存在唯一交点
Point getlineinter(Line a, Line b)
{
    Vector u = a.p-b.p;
    double t = cross(b.v, u) / cross(a.v, b.v);
    return a.p+a.v*t;
}
//半平面交，返回的是多边形
int HalfPlaneInter(Line* L, int n, Point* poly)
{
    sort(L, L+n);  //按极角排序
    int first, last;
    Point *p = new Point[n];
    Line* q = new Line[n]; //双端队列
    q[first=last=0] = L[0];  //初始化为只有一个半平面L[0]
    for(int i = 1; i < n; i++)//去除无用平面
    {
        while(first < last && !OnLeft(L[i], p[last-1])) last--;
        while(first < last && !OnLeft(L[i], p[first])) first++;
        q[++last] = L[i];
        if(dcmp(cross(q[last].v, q[last-1].v)) == 0)//如果斜率相同，取内侧的
        {
            last--;
            if(OnLeft(q[last], L[i].p)) q[last] = L[i];
        }
        if(first < last) p[last-1] = GetLineinter(q[last-1], q[last]);
    }
    while(first < last && !OnLeft(q[first], p[last-1])) last--;
    if(last - first <= 1) return 0;
    p[last] = GetLineinter(q[last], q[first]);
    int m = 0;
    for(int i = first; i <= last; i++) poly[m++] = p[i];//可能会重，必要是要去重！
    //m = unique(poly,poly+m)-poly;
    return m;
}
//半平面交的增量法
/*vector<Point> CutPolygon(const vector<Point> &poly, Point a, Point b) //可返回单点或者线段
{
    vector<Point> newpoly;
    int n = poly.size();
    for(int i = 0; i < n; i++)
    {
        Point c = poly[i], d = poly[(i+1)%n];
        if(dcmp(cross(b-a, c-a)) >= 0) newpoly.push_back(c);
        if(dcmp(cross(b-a, c-d)) != 0)
        {
            Point ip = GetLineInter(a, b-a, c, d-c);
            if(OnSegment(ip, c, d)) newpoly.push_back(ip);
        }
    }
    return newpoly;
}*/
Polygon CutPoly(Point *poly,Point a,Point b,int n)//可返回单点或者线段
{
	Polygon nploy;
	npoly.n = 0;
	for(int i = 0; i < n; i++)
	{
		Point c = poly[i], d = poly[(i+1)%n];
		if(dcmp(cross(b-a,c-a))>=0) nploy.p[npoly.n++] = c;
		if(dcmp(cross(b-a,c-d)) != 0)
		{
			Point ip = GetLineinter(a,b-a,c,d-c);
			if(Onseg(ip,c,d)) nploy.p[npoly.n++] = ip;
		}
	}
	return npoly;
}
void HalfPlaneInter(Point *p,int n,Point *poly)
{
    for(int i = 0; i < n; i++)
        p = CutPolygon(p, poly[i], poly[(i+1)%n]);
}
//旋转卡壳

double rotatingcalipers(Point *p,int n)
{

	if(n==1) return 0;
	if(n==2) return dist2(p[0]-p[1]);
	p[n] = p[0];
	double ret = 0;
	for(int u = 0,v=1; u<n; u++)
	{
		while(1)
		{
			double diff = cross(p[u+1]-p[u],p[v+1]-p[u])-cross(p[u+1]-p[u],p[v]-p[u]);
			if(dcmp(diff)<=0)
			{
				ret = max(ret,dist2(p[u]-p[v]));
				if(dcmp(diff)==0) ret = max(ret,dist2(p[u]-p[v+1]));
				break;
			}
			v = (v+1)%n;
		}
	}
	return ret;
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		p[i].input();
	int m = convehull(p,n,ch);
	printf("%.0f\n",rotatingcalipers(ch,m));
	return 0;
}

