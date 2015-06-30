/*
这道题目可以对应一个Staircase NIM问题，只需要把两个棋子之间的间隔以及第一个棋子与左边界的间隔看作一堆石子，
则一次操作一定是从一对石子中取出若干移到右边相邻的一堆中。这就是标准的Staircase-NIM问题。
具体的做法是：将所有奇数位置上的石子个数做XOR，结果为0说明BOB胜，否则说明GEORGIA胜
*/
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
int a[MAXN],b[MAXN];
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int cas,n;
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%d",&n);
		for(int i = 0; i < n; i++)
			scanf("%d",&a[i]);
		a[n] = 0;
		sort(a,a+n,greater<int>());
		int ans = 0;
		for(int i=0;i<n;i+=2)
			ans^=a[i]-a[i+1]-1;
		if(ans) puts("Georgia will win");
		else puts("Bob will win");
	}
	return 0;
}

