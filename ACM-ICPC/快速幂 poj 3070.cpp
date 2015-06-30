#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int m[2][2];
const int mod = 10000;
void mult(int a[2][2],int b[2][2])
{
	int tmp[2][2] = {{0}};
	for(int i = 0; i < 2; i++)
		for(int j = 0;j < 2; j++)
			for(int k = 0; k < 2; k++)
				tmp[i][j]=(tmp[i][j]+a[i][k]*b[k][j])%mod;
	for(int i = 0; i < 2; i++)
		for(int j = 0;j < 2; j++)
			a[i][j] = tmp[i][j];
}
int pow_mod(int n)
{
	if(n==-2) return 0;
	if(n==0||n==-1) return 1;
	int ans[2][2];
	ans[0][0] = 1,ans[0][1] = 1,ans[1][0] = 0, ans[1][1] = 0;
	while(n)
	{
		if(n&1) mult(ans,m);
		mult(m,m);
		n>>=1;
	}
	return ans[0][0];
}
int main()
{
	//freopen("in.txt","r",stdin);
	int n;

	while(scanf("%d",&n)&&n!=-1)
	{
		m[0][0] = 1,m[0][1] = 1,m[1][0] = 1, m[1][1] = 0;
		printf("%d\n",pow_mod(n-2));
	}
	return 0;
}
