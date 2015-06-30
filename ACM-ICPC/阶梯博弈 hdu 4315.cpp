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
const int MAXN = 20005;
const int INF = 1111111111;

int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
    int n,k,i,sg,a,b;
    while(scanf("%d%d",&n,&k)!=EOF)
    {

        sg=i=0;
        if(n&1)
        {
            scanf("%d",&a);
            sg=a;
            i++;
        }
        for(;i<n;i+=2)
        {
            scanf("%d%d",&a,&b);
            sg^=(b-a-1);
        }
		if(k==1){printf("Alice\n");continue;}
	    if((n&1)&&k==2)
	    {
			if(sg)printf("Bob\n");
			else printf("Alice\n");
	    }

	    else if(sg)printf("Alice\n");
	    else printf("Bob\n");
	}
	return 0;
}

