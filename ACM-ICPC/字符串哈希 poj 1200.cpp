#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int MAXN = 100005;
const int INF = 1111111111;
const double EPS = 1e-6;
const double PI = acos(-1.0);
bool vis[30000000];
char str[2000000];
int id[35];
int main()
{
    //freopen("F:\\acmcode\\in.txt","r",stdin);
    int n,m,cnt,len;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        scanf("%s",str);
        len = strlen(str);
        memset(id,0,sizeof(id));
        memset(vis,0,sizeof(vis));
        int ans = 0;
        cnt = 1;
        for(int i = 0; i+n<=len; i++)
        {
            int sum = 0;
            for(int j = i; j < i+n; j++)
            {
                if(!id[str[j]-'a']) id[str[j]-'a']=cnt++;
                sum=sum*m+id[str[j]-'a'];
            }
            if(!vis[sum]) ans++,vis[sum] = 1;
        }
        printf("%d\n",ans);
    }

    return 0;
}
