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
int a[MAXN][MAXN],c[MAXN],num[MAXN];
priority_queue<int> q;
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int ca;
	int n,m;
	scanf("%d",&ca);
	while(ca--)
	{
		while(!q.empty()) q.pop();
		scanf("%d",&n);
		for(int i = 0; i < n; i++)
		{
			scanf("%d",&num[i]);
			for(int j = 0; j < num[i]; j++)
				scanf("%d",&a[i][j]);
		}
		for(int i = 0; i < n; i++)
			scanf("%d",&c[i]);
		int sum = 0,ans = 0;

		for(int i = 0; i < n; i++)
		{
			sum+=c[i];
			for(int j = 0; j<num[i]; j++)
			{
				sum-=a[i][j];
				ans++;
				q.push(a[i][j]);
				while(sum<0)
				{
					int tmp = q.top();q.pop();
					//printf("%d\n",tmp);
					sum+=tmp;
					ans--;
				}
			}

		}
		printf("%d\n",ans);
	}
	return 0;
}
