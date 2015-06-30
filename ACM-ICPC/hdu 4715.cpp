#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 3000005

int cnt,prime[maxn],ans[maxn];
bool isprime[maxn];
void init()
{
    for (int i=2;i<maxn;i++)
        if (!isprime[i])
        {
            prime[++cnt]=i;
            int j=i*2;
            while (j<maxn) isprime[j]=1,j+=i;
        }
}
int main()
{
    //freopen("/home/moor/Code/input","r",stdin);
    init();
    for (int n=2;n<=1000000;n+=2)
    {
        for (int i=2;i<=cnt;i++)
            if (prime[i]+n<maxn&&!isprime[prime[i]+n]){
                ans[n]=prime[i];
                break;
            }
    }
    int cas,n;
    scanf("%d",&cas);
    while (cas--)
    {
        scanf("%d",&n);
        if(n==0)    printf("2 2\n");
        else    if (n<0) printf("%d %d\n",ans[-n],ans[-n]-n);
        else printf("%d %d\n",ans[n]+n,ans[n]);
    }
    return 0;
}
