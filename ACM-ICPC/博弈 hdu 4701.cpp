/*题意:ALICE和BOB轮流买东西，ALICE的钱总数为a，BOB的钱为b，物品必须从左到右买，一次至少买一个，最先不能买的人输ALICE为先手，问谁能赢。
解法：t=a+b。只有前缀和<=t，的物品可能被买，所以之后的物品不用考虑。用ans[i]表示当前可以选择的第一个物品为i的人至少要有多少钱才可以获胜。所以面对对于最后一个可能被买的物品i，至少要有c[i]的钱才能赢。对于其他位置的物品，有两种必胜策略
1.ans[i]>=c[i]+ans[i+1]，即当前选手买下第i个物品后对于第i+1个物品还处于必胜态
2.ans[i]>=t-sum[i-1]-(ans[i+1]-1)，即当前选手买下第i个物品后另一个人会处于必败态
所以最后只要判断ans[1]和a的大小关系即可
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1000005;
typedef long long LL;
LL a,b,ans[MAXN],c[MAXN],sum[MAXN],t;
int n;
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	while(cin>>n>>a>>b)
	{
		LL tmp = 0;
		int pos=1;
		for(int i = 1; i <= n; i++)
			scanf("%d",&c[i]);
		sum[0] = 0;
		t = a+b;
		for(int i = 1; i <= n; i++)
		{
			sum[i]=sum[i-1]+c[i];
			if(sum[i]<=t) pos = i;
			else break;
		}
		//cout<<pos<<endl;
		ans[pos] = c[pos];

		for(int i = pos-1; i>0; i--)
		{
			ans[i] = min(ans[i+1]+c[i],t-sum[i-1]-(ans[i+1]-1));
		}
		if(ans[1]>a) printf("BOB\n");
		else printf("ALICE\n");
	}
	return 0;
}
