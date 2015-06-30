#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int maxn = 1005;
struct Node{
	string name;
	int next;
	bool operator < (const Node&x)const
	{
		return name<x.name;
	}
	bool operator ==(const Node&x)const
	{
		return name==x.name;
	}
}node;
set<Node> st[maxn];
int main()
{
	freopen("in.txt","r",stdin);
	int n,len,cnt,pos;
	char str[95],tmp[95];
	scanf("%d",&n);
	cnt = pos = 0;
	for(int i = 0; i < n; i++)
	{
		scanf("%s",str);
		len = 0;
		for(int i = 0; str[i]; i++)
		{
			if(str[i]!='\\')
				tmp[len++]=str[i];
			else
			{
				tmp[len]='\0';
				node.name = tmp;
				if(st[i].find(node));

			}
		}
	}
	return 0;
}
