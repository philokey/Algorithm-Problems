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
const int MAXN = 5000005;
const int INF = 1111111111;
int n,a[15],cnt,ip[15],tip[5];
int vis[15],vn;
struct IP{
    int a[4];
}ips[MAXN];
void check(int pos,int len,int num,int tn)
{
    if((tn==4&&pos!=len)||pos>len) return;
    if(pos==len&&(tn==3))
    {
        for(int i = 0; i < tn; i++)
            ips[cnt].a[i]=tip[i];
        ips[cnt].a[3]=num;
        cnt++;
        return;
    }
	tip[tn]=num;
	check(pos+1,len,ip[pos],tn+1);
    if(num*10+ip[pos]<256&&num)
        check(pos+1,len,num*10+ip[pos],tn);

}
void dfs(int len,int dep)
{
    if(dep==(len+1)/2)
    {
        if(vn!=n) return;
        for(int i = 0; i < dep; i++)
            ip[len/2+i] = ip[dep-i-1];
        check(1,len,ip[0],0);
        return;
    }
    for(int i = 0; i < n; i++)
    {
        ip[dep] = a[i];
        if(!vis[a[i]]) vn++;
        vis[a[i]]++;
        dfs(len,dep+1);
        vis[a[i]]--;
        if(!vis[a[i]]) vn--;
    }
    return ;
}
int main()
{
    //freopen("/home/qitaishui/code/in.txt","r",stdin);
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    cnt = 0;
    for(int i = 4; i <= 12; i++)
    {
        memset(vis,0,sizeof(vis));
        vn = 0;
        dfs(i,0);
    }

    printf("%d\n",cnt);
    for(int i = 0; i < cnt; i++)
    {
        for(int j = 0; j < 4; j++)
            if(j==0) printf("%d",ips[i].a[j]);
            else printf(".%d",ips[i].a[j]);
        printf("\n");
    }
    return 0;
}
