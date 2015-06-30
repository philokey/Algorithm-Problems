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
typedef long long LL;
LL gao(LL x)
{
	if(x%4==0) return x;
	if(x%4 == 1)  return 1;
	if(x%4 == 2)  return x+1;
	return 0;

}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n;
	LL ans,x,m,tmp;

	while(scanf("%d",&n)!=EOF)
	{
		ans = 0;
		while(n--)
		{
			scanf("%I64d%I64d",&x,&m);
			tmp = gao(x-1)^gao(x+m-1);
			ans^=tmp;
		}
		if(ans!=0) printf("tolik\n");
		else printf("bolik\n");
	}
	return 0;
}
