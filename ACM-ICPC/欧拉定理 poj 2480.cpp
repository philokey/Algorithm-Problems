#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#define FI first
#define SE second
using namespace std;
typedef long long LL;
const double EPS = 1e-8;
const int MAXN = 50000;
int p[MAXN],pn;
bool is[MAXN];
void get_p()
{
	pn = 0;
	for(int i = 2; i < MAXN; i++)
		if(!is[i])
		{
			p[pn++] = i;
			for(int j = i*2; j < MAXN; j+=i)
				is[j] = 1;
		}
}
LL eular(LL p,int k)
{
	if(k==0) return 1;
	LL ret = p-1;
	while(--k) ret*=p;
	return ret;
}
LL fpk(LL p,int k)
{
	LL ret = 0,x=1;
	for(int i = 0; i <=k; i++)
	{
		ret+=x*eular(p,k-i);
		x*=p;
	}

	return ret;
}
LL solve(LL u)
{
	int k;
	LL ret=1;
	for(int i = 0; p[i]*p[i]<=u; i++)
	{
		k = 0;
		//cout<<u<<" "<<p[i] <<endl;
		if(u%p[i]==0)
		{
			while(u%p[i]==0) k++,u/=p[i];
			ret*=fpk(p[i],k);
		}
	}
	if(u>1) ret*=fpk(u,1);
	return ret;
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n;
	get_p();

	while(scanf("%d",&n)!=EOF)
	{
		cout<<solve(n)<<"\n";
	}
	return 0;
}
