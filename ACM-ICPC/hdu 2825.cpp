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
const int CHN = 28;
const int INF = 1111111111;
const int MOD = 20090717;
struct ACAutomato{
	int sz;
	int fail[MAXN],chd[MAXN][CHN],val[MAXN],id[CHN];
	int dp[2][MAXN][1<<10];
	queue<int> q;
	void init()
	{
		fail[0] = 0;
		for(int i = 0; i < CHN; i++) id[i+'a'] = i;
	}
	void reset()
	{
		q.clear();
		sz = 1;
		memset(chd[0],0,sizeof(0));
	}
	void insert(char *a,int w)
	{
		int p = 0;
		for(;*a;a++)
		{
			int c = id[*a];
			if(!chd[p][c])
			{
				memset(chd[sz],0,sizeof(sz));
				val[sz] = 0;
				chd[p][c] = sz++;
			}
			p = chd[p][c];
		}
		val[p] = w;
	}
	void build()
	{
		for(int i = 0; i<CHN; i++)
			if(chd[0][i])
			{
				q.push(chd[0][i]);
				fail[chd[0][i]]=0;
			}
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			for(int i = 0; i<CHN; i++)
			{
				int &v = chd[u][i];
				if(v)
				{
					q.push(v);
					fail[v] = chd[fail[u]][i];
					val[v]|=val[fail[v]];
				}
				else v = chd[fail[u]][i];
			}
		}
	}
	int solve(int n,int m,int k)
	{
		int s = 0;
		memset(dp[0],0,sizeof(dp[0]));
		dp[0][0][0] = 1;
		while(n--)
		{
			memset(dp[s^1],0,sizeof(dp[s^1]));
			for(int i = 0; i < sz; i++)
				for(int j = 0; j < m; j++)
					if(dp[s][i][j])
						for(int k = 0; k < CHN; k++)
						{
							int p = chd[i][k];
							int tmp =
						}
		}
	}
};
int main()
{
	freopen("/home/qitaishui/code/in.txt","r",stdin);

	return 0;
}
