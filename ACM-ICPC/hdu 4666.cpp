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
const int MAXN = 60005;
const int INF = 1111111111;
struct Node1{
	int id,x;
	bool operator <(const Node1&a)const
	{
		return x<a.x;
	}
}n1;
struct Node2{
	int id,x;
	bool operator <(const Node2&a)const
	{
		return a.x<x;
	}
}n2;
bool era[MAXN];
priority_queue<Node1> q1[45];
priority_queue<Node2> q2[45];
void init()
{
	memset(era,0,sizeof(era));
	for(int i = 0; i < 45; i++)
	{
		while(!q1[i].empty()) q1[i].pop();
		while(!q2[i].empty()) q2[i].pop();
	}

}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n,k,x,op;
	int a[10],s;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		init();
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&op);
			if(op==0)
			{
				for(int j =0; j < k; j++)
					scanf("%d",&a[j]);
				for(int l = 0; l <(1<<k); l++)
				{
					s = 0;
					for(int j = 0; j < k; j++)
						if((1<<j)&l) s+=a[j];
						else s-=a[j];
					n1.x = s,n1.id = i;
					n2.x = s,n2.id = i;
					q1[l].push(n1);
					q2[l].push(n2);
				}
			}
			else
			{
				scanf("%d",&x);
				era[x] = 1;
			}
			int ans = 0;
			for(int j = 0; j <(1<<k); j++)
			{
				n1 = q1[j].top();
				while(era[n1.id])
				{
					q1[j].pop();
					n1 = q1[j].top();
				}
				n2 = q2[j].top();
				while(era[n2.id])
				{
					q2[j].pop();
					n2 = q2[j].top();
				}
				ans=max(ans,n1.x-n2.x);
			}

			printf("%d\n",ans);
		}
	}

	return 0;
}
