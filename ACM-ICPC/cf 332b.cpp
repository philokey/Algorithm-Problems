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
const int MAXN = 500005;
const int INF = 1111111111;
int num[MAXN];
long long sum[MAXN];
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n,k,a,b,pb;
	long long sa,s;
	scanf("%d%d",&n,&k);
	for(int i = 1; i<=n; i++)
		scanf("%d",&num[i]);
	for(int i = 1; i<= k; i++)
		sum[1]+=num[i];

	for(int i = k+1; i<= n;i++)
		sum[i-k+1]=sum[i-k]+num[i]-num[i-k];

	s = sa = 0;
	for(int i = n-2*k+1; i>0; i--)
	{
		if(sa<=sum[i+k]) sa = sum[i+k], pb= i+k;
		if(s <= sa+sum[i])
		{
			s = sa+sum[i];
			a = i;
			b = pb;
		}
	}
	printf("%d %d\n",a,b);

	return 0;
}
