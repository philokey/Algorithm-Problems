#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const int MAXN = 205;
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
	void input(){scanf("%lf%lf",&x,&y);}
}c[MAXN];
struct MP{
	double first;
	int second;
	MP(){}
	MP(double a,int b):first(a),second(b){}
	bool operator<(const MP&a)const
	{
		if(dcmp(first==a.first)) return second>a.second;
		return dcmp(first-a.first)<0;
	}
};
int solve(double r,int n)
{
	if(dcmp(r)==0)
		return 1;
	if(dcmp(r)<0) return 0;
	vector<MP>v;
	int ret=0;
	for(int i = 0; i < n; i++)
	{
		v.clear();
		v.push_back(MP(-PI,1));
		v.push_back(MP(PI,-1));

		for(int j = 0; j < n; j++)
		{
			if(i==j) continue;
			Point q = c[j]-c[i];
			double ab = sqrt(q.x*q.x+q.y*q.y),ac = r,bc = r;

			if(dcmp(ab+ac-bc)<=0)
			{
				v.push_back(MP(-PI,1));
				v.push_back(MP(PI,-1));
				continue;
			}
			if(dcmp(ab-ac-bc)>0) continue;
			double th = atan2(q.y,q.x);
			double fai = acos(sqr(ab)/(2*ac*ab));
			double a0 = th-fai;
			if(dcmp(a0+PI)<0) a0+=2*PI;
			double a1 = th+fai;
			if(dcmp(a1-PI)>0) a1-=2*PI;
			if(dcmp(a0-a1)>0)
			{
				v.push_back(MP(a0,1));
				v.push_back(MP(PI,-1));
				v.push_back(MP(-PI,1));
				v.push_back(MP(a1,-1));
			}
			else
			{
				v.push_back(MP(a0,1));
				v.push_back(MP(a1,-1));
			}
		}
		sort(v.begin(),v.end());
		int cur = 0;
		for(int j = 0; j < v.size(); j++)
		{
			cur+=v[j].SE;
			ret = max(ret,cur);
		}
	}
	return ret;
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n;
	double r1,r2;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i = 0; i < n; i++)
			c[i].input();
		scanf("%lf%lf",&r1,&r2);
		printf("%d\n",solve(r1-r2,n));
	}
	return 0;
}
