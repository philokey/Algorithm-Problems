/*
题意：给n*n的格子，在角上有一个棋子，选手可以向四个方向且棋子曾经没有到达过的格子移动棋子，问先手赢还是后手赢。
解法：如果先手面对的可移动的各自是奇数个，先手赢，偶数个后手赢。
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
const int MAXN = 105;
const int INF = 1111111111;
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n;
	while(scanf("%d",&n)&&n)
	{
		if(n%2==0) printf("8600\n");
		else printf("ailyanlu\n");
	}

	return 0;
}
