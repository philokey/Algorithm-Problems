/*题意：
有一些考试，已知开始时间和结束时间，左闭右开，如果考试时间有重叠，则可以安排在同一天。求最少要安排几天，以及方案。
题解：
将时间点排序，从小到大排序，若有考试开始，则加入队列;若有考试结束，则将队列中的全部考试都安排在一天。*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100015;
struct Node{
    int x,y,id;
    bool operator < (const Node &a)const
    {
        return x<a.x||(x==a.x&&y<a.y);
    }
}node[maxn];
vector<int> ans[maxn];
int main()
{
	//freopen("in.txt","r",stdin);
	int n;
	while(scanf("%d",&n)!=EOF)
	{
	    for(int i = 0; i < n; i++)
        {
            scanf("%d%d",&node[i].x,&node[i].y);
            node[i].id = i+1;
            ans[i].clear();
        }
        sort(node,node+n);
        int r=node[0].y,pos = 0,cnt = 0;
        ans[0].push_back(node[0].id);
        for(int i = 1 ; i < n; i++)
        {
            if(node[i].x<r)
            {
                ans[cnt].push_back(node[i].id);
                r = min(r,node[i].y);
            }
            else
            {
                r = node[i].y;
                ans[++cnt].push_back(node[i].id);
            }
        }
        ++cnt;
        printf("%d\n",cnt);
        for(int i = 0; i < cnt;i++)
        {
            for(int j = 0; j < ans[i].size(); j++)
                if(j==0) printf("%d",ans[i][j]);
                else    printf(" %d",ans[i][j]);
            printf("\n");
        }
        printf("\n");
	}
	return 0;
}


