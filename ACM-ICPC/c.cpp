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
int ans[MAXN][MAXN];
int main()
{
    //freopen("F:\\code\\in.txt","r",stdin);
    int n,m,a[3];
    char str[5];
    bool flag;
    a[0]=a[1]=a[2]=0;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(ans,0,sizeof(ans));
        flag = 0;
        for(int i = 0; i < n ;i++)
            for(int j=0;j<m; j++)
            {
                scanf("%s",str);
                int t1=str[0]-'0';
                int t2 = str[1]-'0';
                a[t1+t2]++;
            }
        int nz=1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m;j++)
            {
                if(a[2])
                {
                    ans[i][j]=3;
                    a[2]--;
                }
                else if(a[1])
                {
                    if(!flag)
                    {
                        flag = 1;
                        while(j<m&&a[1])
                        {
                            if(nz) ans[i][j]=1;
                            else ans[i][j]=2;
                            a[1]--;
                            j++;
                        }
                        while(j<m) {j++;ans[i][j]=0;}
                        //nz^=1;
                        continue;
                    }
                    if(nz) ans[i][m-j-1]=1;
                    else ans[i][m-j-1]=2;
                    a[1]--;
                }
                else ans[i][m-j-1]=0;
            }
            nz = nz^1;
        }
        for(int i = 0; i < n;i++)
        {
            for(int j=0; j < m;j++)
            {
                if(ans[i][j]==0) printf("00 ");
                if(ans[i][j]==1) printf("10 ");
                if(ans[i][j]==2) printf("01 ");
                if(ans[i][j]==3) printf("11 ");
            }
            printf("\n");
        }
    }
    return 0;
}
