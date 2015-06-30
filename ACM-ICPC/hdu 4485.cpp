#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
using namespace std;
char tmp[10000005];
int main()
{
    int ncase,hh,n,now;
    long long num,ans;
    scanf("%d",&ncase);
    while(ncase--)
    {
        scanf("%d%d",&hh,&n);
        scanf("%s",&tmp);
        now=0;
        for(int i = 0; tmp[i]; i++)
		{
			now=now*n+tmp[i]-'0';
			now%=n-1;
		}

        printf("%d %d\n",hh,now);
    }
    return 0;
}
