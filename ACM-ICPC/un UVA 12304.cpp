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
const int MAXN = 10005;
const int INF = 1111111111;
const double PI = acos(-1.0);
inline int dcmp(double x)
{
    if(fabs(x)<EPS) return 0;
    return x<0?-1:1;
}
inline double sqr(double x){return x*x;}
struct Point{
    double x,y;
    Point(){}
    Point(double a,double b):x(a),y(b){}
    Point operator+(const Point&a)const{return Point(x+a.x,y+a.y);}
    Point operator-(const Point&a)const{return Point(x-a.x,y-a.y);}
    Point operator*(double k)const{return Point(x*k,y*k);}
	Point operator/(double k)const{return Point(x/k,y/k);}
    Point trunc(double d)
    {
        double len = sqrt(x*x+y*y);
        return Point(x*d/len,y*d/len);
    }
    bool operator==(const Point&a)const
    {
        return dcmp(x-a.x)==0&&dcmp(y-a.y)==0;
    }
    bool operator<(const Point&a)const
    {
        return dcmp(x-a.x)<0||(dcmp(x-a.x)==0&&dcmp(y-a.y)<0);
    }
    void input(){scanf("%lf%lf",&x,&y);}
    void output(){printf("%.3f %.3f\n",x,y);}
}ord;
typedef Point Vector;
struct Circle{
    Point o;
    double r;
    Circle(){}
    Circle(Point a,double b):o(a),r(b){}
    Point point(double a)
    {
        return Point(o.x+cos(a)*r,o.y+sin(a)*r);
    }
};
inline double cross(Vector a,Vector b)
{
	return a.x*b.y-a.y*b.x;
}
inline double dot(Vector a,Vector b)
{
	return a.x*b.x+a.y*b.y;
}
double length(Vector a)
{
	return sqrt(a.x*a.x+a.y*a.y);
}
double dis(Point a,Point b)
{
	return length(a-b);
}
Vector rotate(Vector a,double rad)
{
    Vector c;
    c.x = a.x*cos(rad)-a.y*sin(rad);
    c.y = a.x*sin(rad)+a.y*cos(rad);
    return c;
}
double disttoline(Point p,Point a,Point b)
{
	Vector v1 = b-a,v2 = p-a;
	return fabs(cross(v1,v2))/length(v1);
}
Vector normal(Vector a)
{
	double l = length(a);
	return Vector(-a.y/l,a.x/l);
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
Circle circumscribed(Point p1,Point p2,Point p3)
{
	double bx = p2.x-p1.x,by = p2.y-p1.y;
	double cx = p3.x-p1.x,cy = p3.y-p1.y;
	double d = 2*(bx*cy-by*cx);
	double x = (cy*(bx*bx+by*by)-by*(cx*cx+cy*cy))/d+p1.x;
	double y = (bx*(cx*cx+cy*cy)-cx*(bx*bx+by*by))/d+p1.y;
	Point p = Point(x,y);
	return Circle(p,length(p-p1));
}
Circle inscribed(Point p1,Point p2,Point p3)
{
	double a = length(p2-p3),b = length(p3-p1),c = length(p1-p2);
	Point p = (p1*a+p2*b+p3*c)/(a+b+c);
	return Circle(p,disttoline(p,p1,p2));
}
int inter_c_seg(Circle c,Point a, Point b, vector<Point>& sol)
{
	double delta,A,B,C;
	Vector v;
	double dist = disttoline(c.o,a,b);
	if(dcmp(dist-c.r)>0) return 0;
	v = b-a;
	A = sqr(v.x)+sqr(v.y);
	B = 2*(v.x*(a.x-c.o.x)+v.y*(a.y-c.o.y));
	C = sqr(a.x-c.o.x)+sqr(a.y-c.o.y)-sqr(c.r);
	if(dcmp(dist-c.r)==0) delta=0;
	else
	{
		delta = sqr(B)-4*A*C;
	}
    Point p1,p2,t1,t2;
    double k1 = (-B-sqrt(delta))/(2*A);
    double k2 = (-B+sqrt(delta))/(2*A);
    p1 = a+v*k1;
    p2 = a+v*k2;
	if(p1==p2) sol.push_back(p1);
	else sol.push_back(p1),sol.push_back(p2);
	return sol.size();

}
double v_angle(Vector a,Vector b)
{
	return acos(dot(a,b)/length(a)/length(b));
}
Point getinter(Point a,Vector aa,Point b,Vector bb)
{
	Vector u = a-b;
	double t = cross(bb,u)/cross(aa,bb);
	return a+aa*t;
}
vector<Point> PointAndTangentToALine(Point p,Point a,Point b,double r)
{
	vector<Point> sol;
	Circle tmp = Circle(p,r);
	Vector nor = normal(a-b);
	nor=nor*r;
	Point na = a+nor,nb = b+nor;
	inter_c_seg(tmp,na,nb,sol);
	na = a-nor,nb = b-nor;
	inter_c_seg(tmp,na,nb,sol);
	return sol;
}
void inter_c_and(Circle c1,Circle c2,vector<Point>&sol)
{
	Vector v = c2.o-c1.o;
	Point p1,p2;
	double len = length(v);
	double s = (sqr(c1.r)-sqr(c2.r)+sqr(len))/len/2;
	double h = sqrt(sqr(c1.r)-sqr(s));
	Point p0 = c1.o+v.trunc(s);

	p1 = p0+rotate(v,PI/2).trunc(h);
	p2 = p0-rotate(v,PI/2).trunc(h);
	if(p1==p2) sol.push_back(p1);
	else sol.push_back(p1),sol.push_back(p2);
}
vector<Point> TangentToTwoLines(Point a,Point b,Point c,Point d,double r)
{
	vector<Point> sol;
	Point p = getinter(a,b-a,c,d-c);
	Vector vec;
	double rad = v_angle(a-p,c-p);
	if(dcmp(cross(a-p,c-p))>0) vec = rotate(a-p,rad/2);
	else vec = rotate(a-p,-rad/2);
	vec = vec/length(vec);
	double len = r/sin(rad/2);
	sol.push_back(p+vec*len);
	sol.push_back(p-vec*len);

	rad = v_angle(a-p,d-p);
	if(dcmp(cross(a-p,d-p))>0) vec = rotate(a-p,rad/2);
	else vec = rotate(a-p,-rad/2);
	vec = vec/length(vec);
	len = r/sin(rad/2);
	sol.push_back(p+vec*len);
	sol.push_back(p-vec*len);
	return sol;
}
vector<Point> TangentToTwoDisjoint(Circle c1,Circle c2,double r)
{
	vector<Point> sol;
	Circle a = Circle(c1.o,c1.r+r);
	Circle b = Circle(c2.o,c2.r+r);
	double tmp = length(c1.o-c2.o);
	if(dcmp(tmp-a.r-b.r)>0||dcmp(tmp-fabs(a.r-b.r))<0) return sol;
	inter_c_and(a,b,sol);
	return sol;
}
void solve1(Point a,Point b,Point c){
    double a1=b.x-a.x,b1=b.y-a.y,c1=dot(b-a,b-a)/2;
    double a2=c.x-a.x,b2=c.y-a.y,c2=dot(c-a,c-a)/2;
    double d=a1*b2-a2*b1;
    Point cp(a.x+(c1*b2-c2*b1)/d,a.y+(a1*c2-a2*c1)/d);
    cp=cp;
    printf("(%.6lf,%.6lf,%.6lf)\n",cp.x+EPS,cp.y+EPS,dis(cp,a));
}
void solve2(Point a,Point b,Point c){
    double la=dis(c,b);
    double lb=dis(a,c);
    double lc=dis(a,b);
    double d=la+lb+lc;
    Point cp((la*a.x+lb*b.x+lc*c.x)/d,(la*a.y+lb*b.y+lc*c.y)/d);
    cp=cp;
    printf("(%.6lf,%.6lf,%.6lf)\n",cp.x+EPS,cp.y+EPS,fabs(cross(b-a,c-a))/d);
}

int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	string str;
	Point a,b,c,d,p;
	Circle ans,c1,c2;
	double r;
	ord = Point(0,0);
	while(cin>>str)
	{
		if(str=="CircumscribedCircle")
		{
			a.input();
			b.input();
			c.input();
			//ans = circumscribed(a,b,c);
			//printf("(%.6f %.6f %.6f)\n",ans.o.x+EPS,ans.o.y+EPS,ans.r);
			solve1(a,b,c);
		}
		else if(str=="InscribedCircle")
		{
			a.input();
			b.input();
			c.input();
			//ans = inscribed(a,b,c);
			//printf("(%.6f %.6f %.6f)\n",ans.o.x+EPS,ans.o.y+EPS,ans.r);
			solve2(a,b,c);
		}
		else if(str=="TangentLineThroughPoint")
		{
			Point s1,s2;
			c1.o.input();
			scanf("%lf",&c1.r);
			p.input();
			if(dcmp(length(c1.o-p)-c1.r)<0) printf("[]\n");
			else if(dcmp(length(c1.o-p)-c1.r)==0)
			{
				Vector vec = p-c1.o;
				vec = normal(vec);
				double ang = atan2(vec.y,vec.x);
				if(dcmp(ang)<0) ang+=PI;
				ang = ang*180/PI;
				if(dcmp(ang-180)==0) ang-=180;
				printf("[%.6f]\n",ang+EPS);
			}
			else
			{
				get_pc(c1,p,s1,s2);
				s1=s1-p,s2=s2-p;
				double ang1 = atan2(s1.y,s1.x),ang2 = atan2(s2.y,s2.x);
				if(dcmp(ang1)<0) ang1+=PI;
				ang1 = ang1*180/PI;
				if(dcmp(ang1-180)==0) ang1-=180;
				if(dcmp(ang2)<0) ang2+=PI;
				ang2 = ang2*180/PI;
				if(dcmp(ang2-180)==0) ang2-=180;
				if(ang1>ang2) swap(ang1,ang2);
				printf("[%.6f,%.6f]\n",ang1+EPS,ang2+EPS);
			}
		}
		else if(str=="CircleThroughAPointAndTangentToALineWithRadius")
		{
			p.input();
			a.input(),b.input();
			scanf("%lf",&r);
			vector<Point>sol = PointAndTangentToALine(p,a,b,r);
			sort(sol.begin(),sol.end());
			printf("[");
			for(int i = 0; i < (int)sol.size(); i++)
				if(i==0) printf("(%.6f,%.6f)",sol[i].x+EPS,sol[i].y+EPS);
				else printf(",(%.6f,%.6f)",sol[i].x+EPS,sol[i].y+EPS);
			printf("]\n");
		}
		else if(str=="CircleTangentToTwoLinesWithRadius")
		{
			a.input(),b.input(),c.input(),d.input();
			scanf("%lf",&r);
			vector<Point>sol = TangentToTwoLines(a,b,c,d,r);
			sort(sol.begin(),sol.end());
			printf("[");
			for(int i = 0; i < (int)sol.size(); i++)
				if(i==0) printf("(%.6f,%.6f)",sol[i].x+EPS,sol[i].y+EPS);
				else printf(",(%.6f,%.6f)",sol[i].x+EPS,sol[i].y+EPS);
			printf("]\n");
		}
		else if(str=="CircleTangentToTwoDisjointCirclesWithRadius")
		{
			c1.o.input();
			scanf("%lf",&c1.r);
			c2.o.input();
			scanf("%lf",&c2.r);
			scanf("%lf",&r);
			vector<Point>sol = TangentToTwoDisjoint(c1,c2,r);
			sort(sol.begin(),sol.end());
			printf("[");
			for(int i = 0; i < (int)sol.size(); i++)
				if(i==0) printf("(%.6f,%.6f)",sol[i].x+EPS,sol[i].y+EPS);
				else printf(",(%.6f,%.6f)",sol[i].x+EPS,sol[i].y+EPS);
			printf("]\n");
		}
	}
	return 0;
}
