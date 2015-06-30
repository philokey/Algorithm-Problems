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
const int MAXN = 105;
const double INF = 1e50;
double sqr(double x){return x*x;}
int dcmp(double x)
{
	if(fabs(x)<EPS) return 0;
	return x<0?-1:1;
}
struct Point3{
	double x,y,z;
	Point3(){}
	Point3(double a,double b,double c):x(a),y(b),z(c){}
	Point3 operator +(const Point3&a)const
	{
		return Point3(x+a.x,y+a.y,z+a.z);
	}
	Point3 operator -(const Point3&a)const
	{
		return Point3(x-a.x,y-a.y,z-a.z);
	}
	Point3 operator /(double k)const
	{
		return Point3(x/k,y/k,z/k);
	}
	Point3 operator *(const Point3&a)const
	{
		return Point3(y*a.z-z*a.y,z*a.x-x*a.z,x*a.y-y*a.x);
	}
	double operator ^(const Point3&a)const
	{
		return x*a.x+y*a.y+z*a.z;
	}
	double len(){return sqrt(x*x+y*y+z*z);}
	void input(){scanf("%lf%lf%lf",&x,&y,&z);}
};
struct ConvexPolygon3D{
	struct Face{
		int a,b,c;
		bool flag;
	};
	int n,tri_num;
	Point3 pt[MAXN];
	Face face[8*MAXN];
	int g[MAXN][MAXN];
	double vlen(const Point3&p)
	{
		return sqrt(sqr(p.x)+sqr(p.y)+sqr(p.z));
	}
	double tri_area(Point3 a,Point3 b,Point3 c)
	{
		return vlen((a-c)*(b-c))/2;
	}
	double dlcmp(Point3 p,Face f)
	{
		Point3 m = pt[f.b]-pt[f.a];
		Point3 n = pt[f.c]-pt[f.a];
		Point3 t = p-pt[f.a];
		return (m*n)^t;
	}
	void deal(int a,int b,int p)
	{
		int f = g[a][b];
		Face add;
		if(face[f].flag)
		{
			if(dlcmp(pt[p],face[f])>EPS) dfs(p,f);
			else
			{
				add.a = b,add.b = a,add.c = p;
				add.flag = 1;
				g[p][b] = g[a][p]=g[b][a] = tri_num;
				face[tri_num++] = add;
			}
		}
	}
	void dfs(int p,int now)
	{
		face[now].flag = 0;
		deal(face[now].b,face[now].a,p);
		deal(face[now].c,face[now].b,p);
		deal(face[now].a,face[now].c,p);
	}
	void solve()
	{
		int tmp;
		Face add;
		bool flag;
		tri_num = 0;
		if(n < 4) return;
		flag = true;
		for(int i = 1; i < n;i++)
		{
			if(vlen(pt[0]-pt[i])>EPS)
			{
				swap(pt[1],pt[i]);
				flag = false;
				break;
			}
		}
		if(flag) return;
		flag = true;
		for(int i = 2; i < n;i++)
		{
			if(vlen((pt[0]-pt[1])*(pt[1]-pt[i]))>EPS)
			{
				swap(pt[2],pt[i]);
				flag = false;
				break;
			}
		}
		if(flag) return;
		flag = true;
		for(int i = 3; i < n;i++)
			if(fabs((pt[0]-pt[1])*(pt[1]-pt[2])^(pt[0]-pt[i]))>EPS)
			{
				swap(pt[3],pt[i]);
				flag = false;
				break;
			}
		if(flag) return;
		for(int i = 0; i< 4;i++)
		{
			add.a = (i+1)%4;
			add.b = (i+2)%4;
			add.c = (i+3)%4;
			add.flag = true;
			if(dlcmp(pt[i],add)>EPS)
				swap(add.b,add.c);
			g[add.a][add.b]=g[add.b][add.c]=g[add.c][add.a]=tri_num;
			face[tri_num++] = add;
		}
		for(int i = 4; i< n;i++)
			for(int j = 0; j<tri_num;j++)
				if(face[j].flag&&dlcmp(pt[i],face[j])>EPS)
				{
					dfs(i,j);
					break;
				}
		tmp = tri_num;
		for(int i = tri_num=0; i < tmp; i++)
			if(face[i].flag)
				face[tri_num++] = face[i];
	}
};
inline double dis_p_f(Point3 p,Point3 a,Point3 b,Point3 c)
{
	Point3 vec=(b-a)*(c-a);
	Point3 t = a-p;
	double tmp = (vec^t)/(vec.len()*t.len());
	return fabs(t.len()*tmp);
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n;

	double h,s,dis;
	ConvexPolygon3D hull;
	Point3 va,vb,a,b,c;
	while(scanf("%d",&n)&&n)
	{
		for(int i = 0; i< n;i++)
			hull.pt[i].input();
		if(n<=2)
		{
			printf("0.000 0.000\n");
			continue;
		}
		if(n==3)
		{
			Point3 vec=(hull.pt[1]-hull.pt[0])*(hull.pt[2]-hull.pt[0]);
            double area=vec.len()/2;
            printf("0.000 %.3f\n",area);
            continue;
		}
		hull.n = n;
		hull.solve();

		h = 0,s = INF;
		for(int i = 0; i<hull.tri_num; i++)
		{

			a = hull.pt[hull.face[i].a];
			b = hull.pt[hull.face[i].b];
			c = hull.pt[hull.face[i].c];
			dis = 0;
			for(int j = 0; j < n; j++)
				dis = max(dis,dis_p_f(hull.pt[j],a,b,c));
			va = (b-a)*(c-a);
			double area = 0;
			for(int j = 0; j < hull.tri_num; j++)
			{
				a = hull.pt[hull.face[j].a];
				b = hull.pt[hull.face[j].b];
				c = hull.pt[hull.face[j].c];
				vb = (b-a)*(c-a);
				double sia = fabs((va^vb)/(va.len()*vb.len()));
				area+=hull.tri_area(a,b,c)*sia;
			}
			//printf("%.3f %.3f\n",dis,area);
			if(dcmp(dis-h)>0||(dcmp(dis-h)==0&&dcmp(area-s)<0))
			{
				h = dis;
				s = area;
			}
		}
		printf("%.3f %.3f\n",h+EPS,s/2+EPS);
	}
	return 0;
}
