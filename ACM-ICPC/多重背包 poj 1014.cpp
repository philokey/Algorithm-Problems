#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=300005;
int sum,dp[maxn],w[maxn],n;
void split(int val,int num)
{
	int x=1,tmp=0;
	while(tmp+x<=num)
	{
		tmp+=x;
		w[n++]=x*val;
		x*=2;
	}
	x=num-tmp;
	if(x)	w[n++]=x*val;

}
bool solve()
{
	for(int i=0;i<n;i++)
		for(int j=sum;j>=w[i];j--)
			dp[j]=max(dp[j],dp[j-w[i]]+w[i]);
	//cout<<dp[sum];
	return dp[sum]==sum;
}
int main()
{
	int ca=1;
	int num[10];
	while(1)
	{
		sum=n=0;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=6;i++)
		{
			scanf("%d",&num[i]);
			sum+=num[i]*i;
		}
		if(sum==0)	break;
		printf("Collection #%d:\n",ca++);
		if(sum%2)
		{
			printf("Can't be divided.\n\n");
			continue;
		}
		sum/=2;
		//cout<<sum<<" "<<n;
		//for(int i=0;i<=n;i++)
			//cout<<i<<" "<<v[i]<<endl;
		for(int i=1;i<=6;i++)
			split(i,num[i]);
		//cout<<n<<endl;
		if(solve())
			printf("Can be divided.\n\n");
		else
			printf("Can't be divided.\n\n");
	}
	return 0;
}
