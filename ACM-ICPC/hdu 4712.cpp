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
int g[25][25];
char str[MAXN][7];
inline int change(char c)
{
	if(c>='A'&&c<='F') return c-'A'+10;
	return c-'0';
}
void init()
{
	int t;
	for(int i = 0; i < 16; i++)
	{
		for(int j = 0; j < 16; j++)
		{
			t = i^j;
			g[i][j]=0;
			while(t)
			{
				g[i][j]+=(t&1);
				t>>=1;
			}
			//cout<<g[i][j]<<" ";
		}
		//cout<<"\n";
	}

}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int cas,n;
	scanf("%d",&cas);
	init();
	while(cas--)
	{
		scanf("%d",&n);
		for(int i = 0; i < n;i++)
			scanf("%s",str[i]);
		int ans = INF,s,a,b;
		for(int i = 0; i < 200000; i++)
		{
			s = 0;
			a = rand()%n,b=rand()%n;
			if(a==b) continue;
			for(int j = 0; j < 5; j++)
			{
				//cout<<change(str[a][j])<<" "<<change(str[b][j])<<endl;
				s+=g[change(str[a][j])][change(str[b][j])];
			}
			ans = min(s,ans);
		}
		printf("%d\n",ans);
	}
	return 0;
}
