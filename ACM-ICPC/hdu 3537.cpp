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
	int n,u,a[105];
	while(scanf("%d",&n)!=EOF)
	{
		int ans = 0,cnt,tmp;
		for(int i = 0; i < n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		n=unique(a,a+n)-a;
		for(int i = 0; i < n; i++)
		{
			int u = a[i];
			cnt = 0;
			while(u)
			{
				cnt+=(u&1);
				u>>=1;
			}
			if(cnt%2) ans^=(2*a[i]);
			else ans^=(2*a[i]+1);
		}
		if(ans==0) printf("Yes\n");
		else printf("No\n");

	}
	return 0;
}
