#include <cmath>
using namespace std;
const double EPS = 1e-6;
int dcmp(double x)
{
	if(fabs(x)<EPS) return 0;
	return x<0? -1:1;
}
struct Point3{
	double x,y,z;
	Point3(){}
	Point3(double a,double b,double c):x(a),y(b),z(c){}
	Point3 operator+(const Point3 &a)const
	{
		return Point3(x+a.x,y+a.y,z+a.z);
	}
	Point3 operator-(const Point3 &a)const
	{
		return Point3(x-a.x,y-a.y,z-a.z);
	}
	Point3 operator*(double c)const
	{
		return Point3(x*c,y*c,z*c);
	}
	Point3 operator/(double c)const
	{
		return Point3(x/c,y/c,z/c);
	}
	void input(){scanf("%lf%lf%lf",&x,&y,&z);}
	void output(){printf("%lf %lf %lf",x,y,z);}
};
typedef Point3 Vector3;
Vector3 Cross(Vector3 a,Vector3 b)
{
	return Vector3(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);
}
double Dot(Vector3 a,Vector3 b)
{
	return a.x*b.x+a.y*b.y+a.z*b.z;
}
double Length(Vector3 a)
{
	return sqrt(Dot(a,a));
}
double Area2(Point3 a,Point3 b,Point3 c)//面积的两倍
{
	return Length(Cross(b-a,c-a));
}
double Angle(Vector3 a, Vector3 b)//向量的夹角
{
	return acos(Dot(a,b)/(Length(a)*Length(b)));
}
//点p到平面的距离，p0为平面上的点,n为法向量
double Distoplane(Point3 p, Point3 p0, Vector3 n)
{
	return fabs(Dot(p-p0,n)/Length(n));
}
Point3 Getpro(Point3 p, Point3 p0, Vector3 n)//p在平面上的投影
{
	double d = Dot(p-p0)/Length(n);//有向距离
	return p+n*d;
}
//直线p1-p2到平面p0-n的交点。假设交点唯一存在
Point3 Lpinter(Point3 p1, Point3 p2, Point3 p0, Vector3 n)
{
	Vector3 v = p2-p1;
	double t = (Dot(n,p0-p1)/Dot(n,p2-p1));//主要判分母是否为0
	return p1+v*t;
}
//面积法。点p是否在三角形p0p1p2中，包括边界
bool Pointintri(Point3 p, Point3 p0, Point3 p1,Point3 p2)
{
	double s1 = Area2(p,p0,p1),s2 = Area2(p,p1,p2),s3 = Area2(p,p2,p0);
	return dcmp(s1+s2+s3-Area2(p0,p1,p2)) == 0;
}
//点p到直线ab的距离
double Distoline(Point3 p, Point3 a, Point3 b)
{
	Vector3 v1 = b-a,v2 = p-a;
	return Length(Cross(v1,v2))/Length(v1);
}
//点p到线段ab的距离
double Distoseg(Point3 p, Point3 a, Point3 b)
{
	if(a==b) return Length(p-a);
	Vector3 v1 = b-a,v2 = p-a,v3 = p-b;
	if(dcmp(Dot(v1,v2))<0) return Length(v2);
	if(dcmp(Dot(v1,v3))>0) return Length(v3);
	return  Length(Cross(v1,v2))/Length(v1);
}
//四面体体积的六倍
//v = 1/3sh = 1/6(ab×ac).h = 1/6(ab×ac).ad
double Volume6(Point3 a, Point3 b, Point3 c, Point3 d)
{
	return Dot(d-a,Cross(b-a,c-a));
}

 double Dislinetoline(Point3 a, Point3 b, Point3 c, Point3 d)
 {
 	Vector3 n = Cross(a-b,c-d);
 	if(dcmp(Length(n))==0) //两直线平行
		return Distoline(b,c,d);
	else
		return Distoplane(a,c,n);
 }
