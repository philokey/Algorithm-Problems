#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int MAXN = 505;
const int INF = 1111111111;
inline double sqr(double x){return x*x;}
inline int dcmp(double x)
{
	if(fabs(x)<EPS) return 0;
	return x<0?-1:1;
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
	Point3 operator/(double a)const
	{
		return Point3(x/a,y/a,z/a);
	}
	Point3 operator*(const Point3 &a)const
	{
		return Point3(y*a.z-z*a.y,z*a.x-x*a.z,x*a.y-y*a.x);
	}
	double operator^(const Point3 &a)const
	{
		return x*a.x+y*a.y+z*a.z;
	}
	double len(){return sqrt(x*x+y*y+z*z);}
	void input(){scanf("%lf%lf%lf",&x,&y,&z);}
	void output(){printf("%lf %lf% lf\n",x,y,z);}
};
struct ConvexPolygon3D{
	struct Face{
		int a,b,c;
		bool flag;
	};
	int n;
	Point3 pt[MAXN];
	int tri_num;
	Face face[8*MAXN];
	int g[MAXN][MAXN];
	double vlen(const Point3 &p)
	{
		return sqrt(sqr(p.x)+sqr(p.y)+sqr(p.z));
	}
	double tri_area(Point3 a,Point3 b,Point3 c)
	{
		return vlen((a-c)*(b-c))/2;
	}
	double volume6(Point3 a,Point3 b,Point3 c,Point3 d)//四面体有向体积的六倍
	{
		return ((b-a)*(c-a)^(d-a))/6;
	}
	double dlcmp(Point3 &p,Face &f)//判断点是否在面内
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
				g[p][b]=g[a][p]=g[b][a]=tri_num;
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

    bool same(int s,int t)
    {
    	Point3 &a = pt[face[s].a];
    	Point3 &b = pt[face[s].b];
    	Point3 &c = pt[face[s].c];
    	bool res=fabs(volume6(a,b,c,pt[face[t].a]))<EPS&&
				 fabs(volume6(a,b,c,pt[face[t].b]))<EPS&&
				 fabs(volume6(a,b,c,pt[face[t].c]))<EPS;
		return res;
    }
    void solve()
    {
    	int tmp;
    	Face add;
    	bool flag;
    	tri_num = 0;
    	if(n<4) return ;
    	flag = true;
    	for(int i = 1; i < n; i++)
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
    	for(int i = 2; i < n; i++)
			if(vlen((pt[0]-pt[1])*(pt[1]-pt[i]))>EPS)
			{
				swap(pt[2],pt[i]);
				flag = false;
				break;
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
		for(int i = 0; i < 4; i++)
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
		for(int i = 4; i < n; i++)
			for(int j = 0; j < tri_num; j++)
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
    double area()
    {
    	double res=0;
    	if(n==3)
		{
			return tri_area(pt[0],pt[1],pt[2]);
		}
		else
			for(int i = 0; i < tri_num; i++)
				res+=tri_area(pt[face[i].a],pt[face[i].b],pt[face[i].c]);
		return res;
    }
    double volume()
	{
		double res;
		Point3 tmp(0,0,0);
		for(int i = 0; i < tri_num; i++)
			res+=volume6(tmp,pt[face[i].a],pt[face[i].b],pt[face[i].c]);
		return fabs(res);
	}
	Point3 get_center()//重心
	{
		Point3 res(0,0,0),o(0,0,0),p;
		double sum,vol;
		sum = 0;
		for(int i = 0; i < tri_num; i++)
		{
			vol=volume6(o,pt[face[i].a],pt[face[i].b],pt[face[i].c]);
			sum+=vol;
			p = (pt[face[i].a]+pt[face[i].b]+pt[face[i].c])/4;
			p.x*=vol,p.y*=vol,p.z*=vol;
			res=res+p;
		}
		res=res/sum;
		return res;
	}
	int polygon_num()
	{
		int res=0;
		bool flag;
		for(int i = 0; i < tri_num; i++)
		{
			flag = 1;
			for(int j = 0; j < i; j++)
				if(same(i,j))
				{
					flag = 0;
					break;
				}
			res+=flag;
		}
		return res;
	}
};
double dis_p_f(Point3 p,Point3 a,Point3 b,Point3 c)
{
	Point3 vec=(b-a)*(c-a);
	Point3 t = a-p;
	double tmp=(vec^t)/(vec.len()*t.len());
	return fabs(t.len()*tmp);
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n;
	ConvexPolygon3D p;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i = 0; i < n;i++)
			p.pt[i].input();
		p.n=n;
		p.solve();
		printf("%d\n",p.polygon_num());
	}
	return 0;
}
