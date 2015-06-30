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
const int MAXN = 105;
int fa[MAXN],fb[MAXN],ha[MAXN],hb[MAXN];
int n;
int main()
{
    freopen("F:\\code\\in.txt","r",stdin);
    int c,s,m=0;
    scanf("%d",&n);
    priority_queue<pair<int,int> >q1,q2;
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&s);
        m+=s;
        for(int j = 1; j <= s; j++)
        {
            scanf("%d",&c);
            if(s%2)
            {
                if(j<=s/2) fa[i]+=c,ha[i]+=c;
                if(j==s/2+1) fa[i]+=c,fb[i]+=c;
                if(j>s/2+1) fb[i]+=c,hb[i]+=c;
            }
            else
            {
                if(j<=s/2) fa[i]+=c,ha[i] += c;
                else fb[i]+=c,hb[i] = hb[i];
            }
        }
        q1.push(make_pair(-abs(fa[i]-hb[i]),i));
        q2.push(make_pair(-abs(fb[i]-ha[i]),i));
    }
    bool vis[MAXN]={0};
    int an1,an2;
    an1 = an2 = 0;
    for(int i = 1; i <= n; i++)
    {
        int tp;
        if(i%2)
        {
            tp = q1.top().SE;
            an1+=fa[tp];
            an2+=hb[tp];
        }
        else
        {
            tp = q2.top().SE;
            an1+=ha[tp];
            an2+=fb[tp];
        }
    }
    printf("%d %d\n",an1,an2);
    return 0;
}
