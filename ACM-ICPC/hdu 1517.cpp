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
const int MAXN = 100005;
const int INF = 1111111111;
int sg[MAXN];
int n;
//int get_sg(int p)
//{
//	if(sg[p]!=-1) return sg[p];
//    if (p >= n) return sg[p]=0;
//    bool vis[10];
//    memset(vis, 0, sizeof(vis));
//    for (int i = 2; i <= 9; i++)
//    {
//        int x = get_sg(p*i);
//        vis[x] = 1;
//    }
//    for (int i = 0; ; i++)
//        if (!vis[i]) return sg[p]=i;
//}
//
//int main()
//{
//	freopen("/home/qitaishui/code/out.txt","w",stdout);
//
//	for(int i = 1; i <= 9; i++) sg[i] = 1;
//	for(int i = 1; i <= 10000; i++)
//	{
//		memset(sg,-1,sizeof(sg));
//		sg[0] = 0;
//		n = i;
//		printf("%d\n",get_sg(1));
//	}
//	printf("\n");
//	return 0;
//}
int main()
{
    while (scanf("%I64d", &n) != EOF)
    {
        long long a = 2, b = 9;
        while(1)
        {
            if (a <= n && n <= b)
            {
                printf("Stan wins.\n");
                break;
            }
            else if (n < a)
            {
                printf("Ollie wins.\n");
                break;
            }
            a = (a-1)*18+1;
            b = b*18;
        }
    }
    return 0;
}
