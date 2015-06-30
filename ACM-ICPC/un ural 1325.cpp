#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
using namespace std;
const double EPS = 1e-8;
const int MAXN = 505;
const int INF = 1111111111;
struct Node{
	int tp,x,y;
	int d,c;
	bool operator<(const Node&a)const
	{
		if(c==a.c) return d>a.d;
		return c>a.c;
	}
}g[MAXN][MAXN];
int fx[8][2]={0,1,0,-1,1,0,-1,0,1,1,1,-1,-1,1,-1,-1};
int n,m;
bool is(int x,int y)
{
	return x>=0&&y>=0&&x<n&&y<m;
}
void bfs(int sx,int sy,int tx, int ty)
{
	Node u;
	priority_queue<Node> q;
	q.push(s);
	g[sx][sy].c = 0;
	g[sx][sy].d = 0;
	q.push(g[sx][sy]);
	while(!q.empty())
	{
		u = q.top();q.pop();
		for(int i = 0; i < 8; i++)
		{
			int x = u.x+fx[i][0];
			int y = u.y+fx[i][1];
			if(!is(x,y)) continue;

		}
	}
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	char a[MAXN];
	Node s,t;
	scanf("%d%d",&n,&m);
	scanf("%d%d%d%d",&s.x,&s.y,&t.x,&t.y);
	s.x--,s.y--;
	t.x--,t.y--;
	for(int i = 0; i < n; i++)
	{
		scanf("%s",a[i]);
		for(int j = 0; j < m; j++)
		{
			g[i][j].tp = a[i]-'0';
			g[i][j].x = i,g[i][j].y = j;
			g[i][j].c = -1;
		}

	}
	bfs(s.x,s.y,t.x,t.y);
	if(g[t.x][t.y].c==-1)
		printf("0 0\n");
	else
		printf("%d %d\n",g[t.x][t.y].d,g[t.x][t.y].c);
	return 0;
}
