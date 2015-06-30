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
const int MAXN = 100005;
const long long INF = (1ll<<(61));
struct Node{
    int num,id;
    long long ans;
    bool operator<(const Node&a)const
    {
        return num>a.num;
    }
}node[MAXN];
int p[MAXN],q[MAXN];
bool cmp(const Node &a,const Node&b)
{
    return a.id<b.id;
}

int main()
{
    freopen("/home/qitaishui/code/in.txt","r",stdin);
    int ca;
    int n,m;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d",&n,&m);
        for(int i = 0; i < n; i++)
            scanf("%d%d",&p[i],&q[i]);
        for(int i = 0; i < m; i++)
        {
            scanf("%d",&node[i].num);
            node[i].id = i;
            node[i].ans = INF;
        }
        sort(node,node+m);
        int pos = n-1;
        long long tmp;
        for(int i = 0; i < m; i++)
        {
            while(pos)
            {
                if(p[pos]<=node[i].num)
                    tmp = (long long)node[i].num*q[pos];
                else
                    tmp = (long long)q[pos]*p[pos];
                if(tmp>=node[i].ans){pos++;break;}
                else
                {
                    node[i].ans = tmp;
                    pos--;
                }
                if(p[pos]<=node[i].num){pos++;break;}
            }
            node[i].ans = min(node[i].ans,(long long)q[0]*node[i].num);
        }
        sort(node,node+m,cmp);
        for(int i = 0; i < m; i++)
            cout<<node[i].ans<<"\n";
    }
    return 0;
}
