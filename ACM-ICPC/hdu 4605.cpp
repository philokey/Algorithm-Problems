#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<ctime>
#include<set>
#include<string>
using namespace std;
const int MAX=255005;
const double inf=1e30;
#define eps 1e-8
#define ll long long
#define PB push_back
#define PII pair<int,int>
#define MP(x,y) make_pair(x,y)
struct Node
{
    int id,g,s;
    bool operator <(const Node &a) const
    {
        return a.g<g;
    }
}ca[MAX],cc[MAX];
int sgn(double x)
{
    if(fabs(x)<eps)
        return 0;
    return x<0?-1:1;
}
double r[MAX];
struct node
{
    int id;
    double t,g;
    bool operator < (const node &a) const
    {
        if(sgn(a.t-t)==0)
            return a.g<g;
        else
            return a.t<t;
    }
};
int tr[MAX];
int n,t;
int read(int idx)
{
    int res=0;
    while(idx>0)
    {
        res+=tr[idx];
        idx-=idx&(-idx);
    }
    return res%1000;
}
void update(int idx,int val)
{
    while(idx<=n)
    {
        tr[idx]+=val;
        idx+=idx&(-idx);
    }
}
node get(int i,int j)
{
    node t;
    t.id=j;
    if(ca[i].s>=ca[j].s)
        t.g=t.t=inf;
    else
    {
        t.t=((double)ca[i].g-ca[j].g)/(ca[j].s-ca[i].s);
        t.g=ca[j].g+ca[j].s*t.t;
    }
    r[ca[j].id]=t.t;
    return t;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,k,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&t);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&ca[i].g,&ca[i].s);
            ca[i].id=i+1;
            cc[i].g=ca[i].g+t*ca[i].s;
            cc[i].id=i+1;
        }
        sort(ca,ca+n);
        sort(cc,cc+n);
        memset(tr,0,sizeof(tr));
        int res=0;
        for(i=0;i<n;i++)
        {
            res+=(read(cc[i].id));
            res%=1000;
            update(cc[i].id,1);
        }
        cout <<res<<endl;
        priority_queue<node>que;
        while(!que.empty())
            que.pop();
        for(i=0;i<n-1;i++)
            que.push(get(i,i+1));
        int cnt=0;
		for(int i = 0; i < 10000&&i<res;)
        {
            node now=que.top();
            que.pop();
            if(sgn(now.t-r[ca[now.id].id])!=0)
                continue;
            int idx=now.id;
            cout << ca[idx].id <<" "<<ca[idx - 1].id<<endl;
            r[ca[idx-1].id]=-1;
            swap(ca[idx],ca[idx-1]);
            if(idx>1)
                que.push(get(idx-2,idx-1));
            if(idx<n-1)
                que.push(get(idx,idx+1));
			i++;
        }
    }
    return 0;
}
/*
 12
 5 1006011
 420 17
 1923 16
 9766 94
 15196 82
 18149 75
 */
