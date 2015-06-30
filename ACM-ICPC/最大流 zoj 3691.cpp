//Memory: 3824 KB
//Time: 280 MS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAXN 405
#define MAXM 200005
#define INF 1000000007
#define EPS 1e-8
struct Edge{
    int v,w,next;
}edge[MAXM];
struct Point{
    double x,y,z;
    int f,l;
    void input(){scanf("%lf%lf%lf%d%d",&x,&y,&z,&f,&l);}
}p[MAXN];
double Dist(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}
int en,head[MAXN];
int h[MAXN],gap[MAXN];
double dist[MAXN][MAXN];
void init()
{
    en = 0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int w)
{
    edge[en].v = v,edge[en].w = w;
    edge[en].next = head[u];
    head[u] = en++;
    swap(u,v);
    edge[en].v = v,edge[en].w = 0;
    edge[en].next = head[u];
    head[u] = en++;
}
void build(double m,int n)
{
    init();
    for(int i = 1; i<=n; i++)
    {
        addedge(0,i,p[i].f);
        addedge(i,i+n,p[i].l);
    }
    addedge(1+n,n*2+1,INF);
    for(int i = 2; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            if(i==j||dist[i][j]+EPS>m) continue;
            addedge(i+n,j,INF);
        }

}
int dfs(int s,int t,int pos,int n,int cost)
{
    if(pos==t) return cost;
    int minh = n-1,lv = cost,d;
    for(int j = head[pos]; j!=-1; j= edge[j].next)
    {
        int v = edge[j].v, w = edge[j].w;
        if(w>0)
        {
            if(h[v]+1==h[pos])
            {
                d = min(lv,w);
                d = dfs(s,t,v,n,d);
                edge[j].w-=d,edge[j^1].w+=d;
                lv-=d;
                if(h[s]>=n) return cost-lv;
                if(lv==0) break;
            }
            if(h[v]<minh) minh = h[v];
        }
    }
    if(lv==cost)
    {
        gap[h[pos]]--;
        if(gap[h[pos]]==0) h[s] = n;
        h[pos] = minh+1;
        gap[h[pos]]++;
    }
    return cost - lv;
}
int sap(int st,int ed,int n)
{
    int ret = 0;
    memset(gap,0,sizeof(gap));
    memset(h,0,sizeof(h));
    gap[0] = n;
    while(h[st]<n) ret+=dfs(st,ed,st,n,INF);
    return ret;
}
int main()
{
    //freopen("/home/moor/Code/input","r",stdin);
    int n,sum;
    bool flag;
    double l,r,mid,ans;

    while(scanf("%d",&n)!=EOF)
    {
        l = r = 0;
        sum = 0;
        flag = 1;
        for(int i = 1; i <= n; i++)
        {
            p[i].input();
            sum+=p[i].f;
            if(i!=1&&p[i].f>p[i].l) flag = 0;
        }
        if(!flag)
        {
            printf("-1\n");
            continue;
        }
        for(int i = 1; i <=n; i++)
            for(int j = i+1; j<=n; j++)
                dist[i][j] = dist[j][i] = Dist(p[i],p[j]),
                r = max(r,dist[i][j]);
        r+=10;
        p[1].l = INF;
        ans = -1;
        while(r-l>EPS)
        {
            mid = (l+r)/2;
            build(mid,n);
            if(sap(0,n*2+1,n*2+2)==sum) ans = mid,r = mid-EPS;
            else l=mid+EPS;
        }
        if(ans<0) printf("-1\n");
        else printf("%.8f\n",ans);
    }
    return 0;
}
