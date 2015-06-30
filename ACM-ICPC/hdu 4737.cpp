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
const int MAXN = 100005;
const int INF = 1111111111;
int a[MAXN];
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int cas,n,m;
	long long ans;
	scanf("%d",&cas);
	for(int ca = 1; ca<=cas; ca++)
	{
		ans = 0;
		printf("Case #%d: ",ca);
		scanf("%d%d",&n,&m);
		for(int i = 0; i < n; i++)
			scanf("%d",&a[i]);
		for(int i = 0; i < n; i++)
		{
			int s = a[i];
			for(int j = i+1; s<m&&j < n; j++)
			{
				ans++;
				s|=a[j];
			}
			if(s<m) ans++;
		}
		printf("%I64d\n",ans);

	}
	return 0;
}
