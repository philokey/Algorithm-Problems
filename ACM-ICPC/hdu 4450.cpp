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
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n,ans,a;
	while(scanf("%d",&n)&&n)
	{
		ans=0;
		for(int i = 0; i < n;i++)
		{
			scanf("%d",&a);
			ans+=a*a;
		}
		printf("%d\n",ans);
	}
	return 0;
}
