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
const int MAXN = 500015;
const int MAXM = 27;
const int INF = 1111111111;
char str[MAXN*10];
struct ACAutomaton{
	int chd[MAXN][MAXM],fail[MAXN],val[MAXN];
	int id[128];
	int sz;
	queue<int> q;
	void init()
	{
		fail[0] = 0;
		for(int i = 0; i < MAXM; i++) id[i+'a'] = i;
	}
	void reset()
	{
		sz = 1;
		memset(chd[0],0,sizeof(chd[0]));
	}
	void insert(char *a)
	{
		int p = 0;
		for(;*a; a++)
		{
			int c = id[*a];
			if(!chd[p][c])
			{
				memset(chd[sz],0,sizeof(chd[sz]));
				val[sz] = 0;
				chd[p][c] = sz++;
			}
			p = chd[p][c];
		}
		val[p]++;
	}
	void construct()
	{
		for(int i =0; i < MAXM; i++)
			if(chd[0][i])
			{
				fail[chd[0][i]] = 0;
				q.push(chd[0][i]);
			}
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			for(int i = 0; i < MAXM; i++)
			{
				int &v = chd[u][i];
				if(v)
				{
					q.push(v);
					fail[v] = chd[fail[u]][i];
				}
				else v = chd[fail[u]][i];
			}
		}
	}
	int solve(char str[])
	{
		int ret = 0,ind,p;
		p = 0;
		for(int i = 0; str[i]; i++)
		{
			ind = id[str[i]];
			p = chd[p][ind];
			int tmp = p;
			while(tmp!=0&&val[tmp]>0)
			{
				ret+=val[tmp];
				val[tmp] = -1;
				tmp = fail[tmp];
			}
		}
		return ret;
	}
}ac;
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int cas,n;

	scanf("%d",&cas);
	ac.init();
	while(cas--)
	{
		ac.reset();
		scanf("%d",&n);
		for(int i = 0; i < n; i++)
		{
			scanf("%s",&str);
			ac.insert(str);
		}
		ac.construct();
		scanf("%s",str);
		printf("%d\n",ac.solve(str));
	}
	return 0;
}
