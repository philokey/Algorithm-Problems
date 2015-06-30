#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 50005;
struct Node{
	int f,s,pos;
	bool operator <(const Node&x)const
	{
		return (f > x.f)||(f==x.f&&pos<x.pos);
	}
}node[maxn];
int main()
{
	//freopen("in.txt","r",stdin);
	int cas,n;
	scanf("%d",&cas);
	for(int ca = 1; ca <= cas; ca++)
	{
		scanf("%d",&n);
		for(int i = 0; i < n; i++)
			scanf("%d%d",&node[i].f,&node[i].s),node[i].pos=i+1;
		int pos,t;
		printf("Case #%d:\n",ca);
		for(int i = 0; i <min(n,505); i++)
		{
			t = 0;
			for(int j = 0; j < n; j++)
			{
				if(node[j].f==-1) continue;
				if(t<node[j].f) t = node[j].f, pos = j;
				node[j].f+=node[j].s;
			}
			if(i==0) printf("%d",pos+1);
			else printf(" %d",pos+1);
			node[pos].f = -1;
		}
		sort(node,node+n);
		for(int i = 0; i < n&&node[i].f!=-1; i++)
			printf(" %d",node[i].pos);
		printf("\n");
	}
	return 0;
}
