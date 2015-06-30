#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <ctime>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const int MAXN = 10005;
const int INF = 1111111111;
int main()
{
	freopen("/home/qitaishui/code/out.txt","w",stdout);
	int n,a,b,c,d,ca;
	srand(time(NULL));
	ca = 50000;
	for(int i = 0; i < ca; i++)
	{
		n = rand()%200;
		n++;

		printf("%d\n",n);
		for(int j = 0; j < n; j++)
		{
			a = rand()%1000000*(rand()%2==0?-1:1);;
			b = rand()%1000000*(rand()%2==0?-1:1);;
			c = rand()%1000000*(rand()%2==0?-1:1);;
			d = rand()%1000000*(rand()%2==0?-1:1);;
			while(a==c&&b==d) a+=1,c-=1;
			printf("%d %d %d %d\n",a,b,c,d);
		}
	}
	return 0;
}

		/*n = rand()%1000;
		n++;
		printf("%d\n",n);
		for(int j = 0; j < n; j++)
		{
			int a = rand()%1000000*(rand()%2==0?-1:1);
			int b = rand()%1000000*(rand()%2==0?-1:1);
			int c = rand()%1000000*(rand()%2==0?-1:1);
			int d = rand()%1000000*(rand()%2==0?-1:1);
			while(a==c&&b==d) a+=1,c-=1;
			printf("%d %d %d %d\n",a,b,c,d);
		}*/
