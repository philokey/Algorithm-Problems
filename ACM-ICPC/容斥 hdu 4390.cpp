//题意：已知a1*a2*...*an=b1*b2*…*bn (ai>1)，以及bi，问ai有几种组合，3 4 和 4 3 算一种
/*思路：先对b分解质因数，统计每个质因子的个数。对于每个质因子，如果不考虑ai>1用隔板法有c[n+m-1][m-1]种放法，
总的结果就是每个的相乘。可以把有1的因子当作容斥中重复的部分。所以枚举1~n-1个位置必须为空的情况。
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 1000005;
const int inf = 1111111111;
const int mod = 1000000007;
long long c[105][105];
vector<int> prime;
bool p[1000005];
map<int,int> mymap;
int init()
{
    for(int i = 0; i < 105; i ++)
    {
        c[i][i] = c[i][0] = 1;
        for(int j = 1; j < i; j++)
            c[i][j] = c[i-1][j-1]+c[i-1][j];
    }
    memset(p,0,sizeof(p));
    for(int i = 2; i < maxn; i ++)
    {
        if(p[i]==0)
        {
            prime.push_back(i);
            for(int j = i*2; j < maxn; j+=i)
                p[j] = 1;
        }
    }
}
long long solve(int n)
{
    long long ret = 0,tmp;
    int m;
    for(int i = 0; i < n; i++)
    {
        tmp = c[n][i];
        for(map<int,int>::iterator it=mymap.begin(); it!=mymap.end(); it++)
        {
            m = it->second;
            tmp = (tmp*c[n+m-1-i][n-1-i])%mod;
        }
        if(i&1) ret = (ret-tmp+mod)%mod;
        else ret = (ret + tmp)%mod;
    }
    return ret;
}
int main()
{
    //freopen("in.txt","r",stdin);
    init();
    int n,a;
    while(scanf("%d",&n)!=EOF)
    {
        mymap.clear();
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&a);
            for(int j = 0; prime[j]*prime[j]<=a; j++)
            {
                while(a%prime[j]==0)
                {
                    mymap[prime[j]]++;
                    a/=prime[j];
                }
            }
            if(a>1) mymap[a]++;
        }
        cout<<solve(n)<<endl;
    }
    return 0;
}


