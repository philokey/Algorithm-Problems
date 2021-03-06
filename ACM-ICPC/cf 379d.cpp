#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const int MAXN = 100005;
int p,x,n,m;
typedef long long  LL;
bool flag;
LL gao(int dep,LL ac,LL bc,bool as,bool ae,bool bs,bool be)
{
    if(dep==p) return bc;
    return gao(dep+1,bc,ac+bc+(ae&&bs),bs,be,as,be);
}
void print(int n,LL ac,bool s,bool e)
{
    string str;
    str.resize(n);
    int i = 0;
    if(s) str[i++] = 'C';
    if(e) str[--n] = 'A';
    while(ac--) str[i++] = 'A',str[i++] = 'C';
    while(i<n) str[i++] = 'B';
    cout<<str<<"\n";

}
void solve(LL ac,LL bc,bool as,bool ae,bool bs,bool be)
{
    if(ac*2+as+ae>n||bc*2+bs+be>m) return;
    if(gao(2,ac,bc,as,ae,bs,be) == x)
    {
        flag = 1;
        print(n,ac,as,ae);
        print(m,bc,bs,be);
    }
}
int main()
{
    //freopen("F:\\code\\in.txt","r",stdin);
    while(scanf("%d%d%d%d",&p,&x,&n,&m)!=EOF)
    {
        flag = 0;
        for(int i = 0; i*2 <= n&&!flag; i++)
            for(int j = 0; j*2<=m&&!flag; j++)
                for(int k = 0; k < 16&&!flag; k++)
                {
                    solve(i,j,k&1,(k>>1)&1,(k>>2)&1,(k>>3)&1);
                }
        if(!flag)
            printf("Happy new year!\n");
    }
    return 0;
}
