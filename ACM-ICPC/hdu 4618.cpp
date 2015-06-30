#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const int MAXN = 305;
int n,m;
int g[MAXN][MAXN];
int ans;
bool judge(int x,int y,int l)
{
    for(int i = x; i < x+l; i++)
        for(int j = 1; j <= l/2; j++)
            if(g[i][y+j-1]!=g[i][y+l-j]) return 0;
    for(int i = y; i < y+l ;i++)
        for(int j = 1; j <= l/2; j++)
            if(g[x+j-1][i]!=g[x+l-j][i]) return 0;
    return 1;
}
void solve(int x,int y)
{
    int len = min(n-x+1,m-y+1);
    if(len<=ans) return ;
    while(ans<len)
    {
        if(judge(x,y,len)) {ans=len;return;}
        len--;
    }
}
int main()
{
	//freopen("in.txt","r",stdin);
	int cas;
	scanf("%d",&cas);
	while(cas--)
	{
	    scanf("%d%d",&n,&m);
	    for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("%d",&g[i][j]);
        ans = 1;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                solve(i,j);
        printf("%d\n",ans);
	}

	return 0;
}
