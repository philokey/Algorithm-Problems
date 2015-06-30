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
const int MAXN = 10005;
const int INF = 1111111111;

bool flag;
double po[45],an1,an2;
void init()
{
	po[0] = 1;
	for(int i = 1; i<=40; i++)
		po[i]=po[i-1]*0.5;
}
void dfs(int dep,int a,int b)
{
	if(dep>=40){flag=1;return;}
	if(a==0||b==0)
	{
		an1+=dep*po[dep];
		if(b==0) an2+=po[dep];
		return;
	}
	int t=min(a,b);
	dfs(dep+1,a-t,b+t);
	dfs(dep+1,a+t,b-t);
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int cas;
	int a,b;
	init();
	scanf("%d",&cas);
	for(int ca = 1; ca<=cas; ca++)
	{
		an1=an2=0;
		flag=0;
		scanf("%d%d",&a,&b);
		dfs(0,a,b);
		printf("Case %d: %.6f %.6f\n",ca,an1,an2);
	}
	return 0;
}
