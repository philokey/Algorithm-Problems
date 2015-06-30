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
const int MAXN = 1005;
const int INF = 1111111111;
char str[MAXN];
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int cas;
	scanf("%d",&cas);
	for(int ca = 1;ca<=cas;ca++)
	{
		scanf("%s",str);
		int len = strlen(str);
		printf("Case #%d: ",ca);
		if(len<4)
			printf("%snanodesu\n",str);
		else
		{
			if(strcmp(str+(len-4),"desu")==0)
				str[len-4]='\0';
			printf("%snanodesu\n",str);
		}
	}
	return 0;
}
