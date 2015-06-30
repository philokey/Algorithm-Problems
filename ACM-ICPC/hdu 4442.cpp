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
const int MOD = 365*24*60*60;
typedef long long LL;
struct Node{
	LL a,b;
	bool operator<(const Node&x)const
	{
		return a*x.b<b*x.a;
	}
}node[MAXN];
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n;
	LL ans;
	while(scanf("%d",&n)&&n)
	{
		ans = 0;
		for(int i = 0; i<n; i++)
			scanf("%lld%lld",&node[i].a,&node[i].b);
		sort(node,node+n);
		for(int i = 0; i < n;i++)
		{
			ans=(ans+node[i].a+ans*node[i].b)%MOD;
		}
		cout<<ans<<endl;
	}
	return 0;
}
