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
const int INF = 1111111111;
const double PI = acos(-1.0);
struct Node{
    int sta,ont,offt,svt;
    int m,l,k;
}node[MAXN];
int t,n;
bool check(int m)
{
    int ava = 0,cnt = 0;
    for(int i = 0; i <= t; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(node[j].sta==1&&(node[j].svt+node[j].m==i))
                node[j].sta = -1,ava++,cnt++;
            if(node[j].sta==2&&(node[j].offt+node[j].k==i))
                node[j].sta = 0,node[j].ont = j;
        }
        for(int j = 0; j < n; j++)
        {
            if(node[j].sta==0&&ava)
            {
                --ava;
                node[j].sta = 1;
            }
            else if(node[j].sta==0&&(node[j].ont+node[j].l==i))
                node[j].sta = 2,node[j].offt = i;
        }
    }
    return cnt==n;
}
int main()
{
    freopen("/home/qitaishui/code/in.txt","r",stdin);
    int ans;
    while(scanf("%d%d",&n,&t)&&(n+t))
    {
        memset(node,0,sizeof(node));
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d%d",&node[i].m,&node[i].l,&node[i].k);
        }
        int m,l = 0, r = n;
        while(l<=r)
        {
            m = (l+r)/2;
            if(check(m)) ans = m,r = m-1;
            else l = m+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
