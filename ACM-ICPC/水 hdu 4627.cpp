#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
using namespace std;
const double EPS = 1e-8;
const int MAXN = 10005;
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int cas;
	long long n;
	scanf("%d",&cas);
	while(cas--)
	{
		cin>>n;
		if(n==2)
		{
			printf("1\n");
			continue;
		}
		if(n%2) printf("%I64d\n",(n/2)*(n/2+1));
		else
		{
			long long a = n/2;
			if((a-1)%2) printf("%I64d\n",(a-1)*(a+1));
			else printf("%I64d\n",(a-2)*(a+2));
		}

	}
	return 0;
}
