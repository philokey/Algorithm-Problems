#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
long long n,ans;
void bfs(long long x)
{
	queue<long long> lz;
	lz.push(x);
	while(!lz.empty())
	{
		ans = lz.front();
		lz.pop();
		if(ans % n == 0){return;}
		else
		{
			lz.push(ans*10);
			lz.push(ans*10+1);
		}
	}

}

int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	while((scanf("%lld",&n))!=EOF)
	{
		if(n == 0){return 0 ;}
		bfs(1);
		printf("%lld\n",ans);
	}
}





