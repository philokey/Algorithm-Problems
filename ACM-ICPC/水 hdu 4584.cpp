#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 55;
const int INF = 1000000;
char g[MAXN][MAXN];
int get(int x1,int y1,int x2,int y2)
{
	return abs(x1-x2)+abs(y1-y2);
}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,m;
	int x1,y1,x2,y2,d;
	while(scanf("%d%d",&n,&m)&&(n+m))
	{
		d = INF;
		for(int i = 0; i < n; i++)
			scanf("%s",g[i]);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				for(int ii = 0; ii < n; ii++)
					for(int jj = 0; jj < m; jj++)
					{
						if(g[i][j]=='H'&&g[ii][jj]=='C')
						{
							if(d>get(i,j,ii,jj))
							{
								d = get(i,j,ii,jj);
								x1 = i,y1 = j;
								x2 = ii,y2 = jj;
							}

						}
					}
		printf("%d %d %d %d\n",x1,y1,x2,y2);
	}
}
