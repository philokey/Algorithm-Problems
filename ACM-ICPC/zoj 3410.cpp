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
const int MAXN = 55000;
const int INF = 1111111111;
const double PI = acos(-1.0);
struct Node{
    int d,t;
    bool operator<(const Node&a)const
    {
        return d<a.d;
    }
}node[MAXN];
int main()
{
    //freopen("/home/qitaishui/code/in.txt","r",stdin);
    int n,hp,t,thp;
    while(scanf("%d%d",&n,&hp)!=EOF)
    {
        for(int i = 0; i < n;i++)
            scanf("%d%d",&node[i].t,&node[i].d);
        sort(node,node+n);
        t = 0;
        thp = hp;
        priority_queue<int> q;
        bool flag = 1;
        for(int i = 0; flag&&i < n; i++)
        {
            t+=node[i].t;
            q.push(node[i].t);
            while(!q.empty()&&t>node[i].d&&hp>0)
            {
                int top = q.top();
                t-=top;
                hp--;
                q.pop();
            }
            if(t>node[i].d||hp==0) flag = 0;
        }
        if(!flag) printf("-1\n");
        else printf("%d\n",thp-hp);

    }
    return 0;
}
