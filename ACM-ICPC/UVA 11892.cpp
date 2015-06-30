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
	int ca,cnt,n,a;
	scanf("%d",&ca);
	while(ca--)
	{
		scanf("%d",&n);
		cnt = 0;
		for(int i = 0; i< n; i++)
		{
			scanf("%d",&a);
			if(a>1) cnt++;
		}
		if(!cnt&&n%2==0) printf("piloop\n");
		else printf("poopi\n");
	}
	return 0;
}
