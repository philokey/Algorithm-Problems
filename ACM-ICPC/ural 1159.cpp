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
const int MAXN = 1005;
const int INF = 1111111111;
const double PI = acos(-1.0);
int dcmp(double x)
{
	if(fabs(x)<EPS) return 0;
	return x<0?-1:1;
}
struct Point{
	double x,y;
	Point(){}
	Point(double a,double b):x(a),y(b){}
};
double len[MAXN];
double area(double a, double b, double c)
{
     double s = (a+b+c)/2;
     return sqrt(s*(s-a)*(s-b)*(s-c));
}
inline double getang(double r,double d)
{
	return asin(d/(2*r))*2;
}
bool judge(double s,double ang,bool tp)
{
	if(tp==0) return dcmp(s-ang)<0;

	if(dcmp(s+ang-2*PI)>0) return 1;
	else return 0;
}
double solve(int n)
{
	double l = len[n-1]/2,r = INF,m;
	double ang = 0,ans,ret;
	bool tp;
	for(int i = 0; i < n-1; i++)
		ang+=getang(l,len[i]);
	if(dcmp(ang-PI)<0) tp = 0;
	else tp = 1;
	while(dcmp(r-l)>EPS)
	{
		m = (l+r)/2;
		ang = 0;
		for(int i =0; i < n-1; i++)
			ang+=getang(m,len[i]);
		double tmp = getang(m,len[n-1]);
		if(judge(ang,tmp,tp)) l = m;
		else ans = m,r = m;
	}
	ret = 0;
	for(int i = 0; i < n-1; i++)
		ret+=area(ans,ans,len[i]);
	if(tp) ret+=area(ans,ans,len[n-1]);
	else ret-=area(ans,ans,len[n-1]);
	return ret;
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n;
	double sum;
	while(scanf("%d",&n)!=EOF)
	{
		sum = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%lf",&len[i]);
			sum+=len[i];
		}
		sort(len,len+n);
		if(dcmp(sum-len[n-1]*2)<=0)
		{
			printf("0.00\n");
			continue;
		}
		//cout<<sum<<endl;
		printf("%.2f\n",solve(n));
	}
	return 0;
}
