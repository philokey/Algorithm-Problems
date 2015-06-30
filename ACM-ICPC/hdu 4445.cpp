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
const int INF = 1111111111;
const double PI2 = acos(-1.0)/2;
const double del = PI2/1000;
const double g = 9.8;
inline int dcmp(double x)
{
	if(fabs(x)<EPS) return 0;
	return x<0?-1:1;
}

int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n;
	double h,l1,l2,r1,r2;
	double v[MAXN];
	while(scanf("%d",&n)&&n)
	{
		scanf("%lf%lf%lf%lf%lf",&h,&l1,&r1,&l2,&r2);
		for(int i = 0; i < n; i++)
			scanf("%lf",&v[i]);
		double rad=0,tmp,s,t,vx,x;
		int ans=0;
		for(rad=0; dcmp(PI2-rad)>0; rad+=del)
		{
			bool flag1=1,flag2=1;
			int cnt1=0,cnt2=0;
			for(int i = 0; i < n&&(flag1||flag2);i++)
			{
				s = sin(rad)*v[i];
				tmp = s*s+2*g*h;
				vx = v[i]*cos(rad);
				if(flag1)
				{
					t = (s+sqrt(tmp))/g;
					x = vx*t;
					if(dcmp(x-l2)>=0&&dcmp(x-r2)<=0){flag1=0;}
					if(flag1&&dcmp(x-l1)>=0&&dcmp(x-r1)<=0) cnt1++;
				}

				if(flag2)
				{
					t = (-s+sqrt(tmp))/g;
					x = vx*t;
					if(dcmp(x-l2)>=0&&dcmp(x-r2)<=0){flag2=0;}
					if(flag2&&dcmp(x-l1)>=0&&dcmp(x-r1)<=0) cnt2++;
				}
			}
			if(flag1) ans=max(ans,cnt1);
			if(flag2) ans=max(ans,cnt2);
		}
		printf("%d\n",ans);
	}
	return 0;
}
