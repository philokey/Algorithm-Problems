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
const int MAXN = 2000005;
char sa[MAXN],sb[MAXN];
int a,b,c;
int n;
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%s%s",sa,sb);
		a = b=c=0;
		for(int i = 0; i < 2*n; i++)
			if(sa[i]=='1'&&sb[i]=='1') c++;
			else if(sa[i]=='1'&&sb[i]=='0') a++;
			else if(sa[i]=='0'&&sb[i]=='1') b++;
		int ta,tb;
		ta = c/2+c%2+a;
		tb = c/2+b;

		if(ta==tb) printf("Draw\n");
		else if(ta>tb) printf("First\n");
		else printf("Second\n");
	}
	return 0;
}
