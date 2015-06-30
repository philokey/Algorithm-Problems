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
pair<int,int> ci[MAXN];
int pre[2][MAXN],las[2][MAXN];
int main()
{
    //freopen("F:\\code\\in.txt","r",stdin);
    int n,m,ca[2],a,cnt,tc,tj,md;
    while(scanf("%d",&n)!=EOF)
    {
        ca[0] = ca[1] = cnt = 0;
        for(int i = 0; i < n ;i++)
        {
            scanf("%d",&m);
            tc = 0,tj = 0;
            for(int j = 0; j < m; j++)
            {
                scanf("%d",&a);
                if(m%2==0)
                {
                    if(j<m/2) ca[0]+=a;
                    else ca[1]+=a;
                }
                else
                {
                    if(j<m/2) tc+=a;
                    else if(j==m/2) tj+=a,tc+=a,md=a;
                    else tj+=a;
                }
            }
            if(m%2)
            {
                pre[0][cnt] = tc;
                pre[1][cnt] = tj;
                las[0][cnt] = tc-md;
                las[1][cnt] = tj-md;
                ci[cnt++] = make_pair(md,cnt);
            }
        }
        bool nw=0;
        sort(ci,ci+cnt);
        for(int i = cnt-1; i >= 0; i--)
        {
            ca[nw]+=pre[nw][ci[i].SE];
            ca[nw^1]+=las[nw^1][ci[i].SE];
            nw^=1;
        }
        printf("%d %d\n",ca[0],ca[1]);
    }
    return 0;
}
