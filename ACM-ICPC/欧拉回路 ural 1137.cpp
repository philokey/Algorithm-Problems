#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <stack>
#include <cmath>
using namespace std;
const int maxn = 100005;
const int inf = 1111111111;
struct Edge{
    int v,next;
}edge[maxn*10];
int head[maxn],en;
stack<int> sta;
bool vis[maxn];
void addedge(int u,int v)
{
    edge[en].v = v;
    edge[en].next = head[u];
    head[u]=en++;
}
void init()
{
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
    en = 0;
}
void euler(int u)
{
    int v;
    for(int i = head[u]; i!=-1; i = edge[i].next)
    {
        v = edge[i].v;
        if(!vis[i])
        {
            vis[i] = 1;
            euler(v);
            sta.push(v);
        }
    }
}
void print()
{
    printf("%d 1",sta.size());
    while(!sta.empty())
    {
        printf(" %d",sta.top());
        sta.pop();
    }
    printf("\n");
}
int main()
{
    //freopen("in.txt","r",stdin);
    int n,u,v,a;
    scanf("%d",&n);
    init();
    for(int i = 0 ;i < n; i++)
    {
        scanf("%d%d",&a,&u);
        for(int j = 0; j < a; j++)
        {
            scanf("%d",&v);
            addedge(u,v);
            u = v;
        }
    }
    euler(1);
    print();
    return 0;
}


