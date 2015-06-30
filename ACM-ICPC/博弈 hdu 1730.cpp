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
	int n,m,u,v,a,b;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		a = b = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%d%d",&u,&v);
			b^=(abs(u-v)-1);
		}
		if(b) printf("I WIN!\n");
		else printf("BAD LUCK!\n");
	}
	return 0;
}
