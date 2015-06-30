#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
const double EPS = 1e-8;
const int MAXN = 10005;
typedef long long LL;
LL lca(LL a,LL b)
{
	LL c = a*b;
	while(a%b)
	{
		a%=b;
		swap(a,b);
	}
	return c/b;
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int cas;
	int n,a,b;
	LL c,la,lb,tmp,len,ans,x;
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%d%d%d",&n,&a,&b);
		c = lca(a,b);
		ans = 0;
		la=a,lb=b;
		for(LL i = 0; i < n;)
		{
			x = min(min(la,lb),(LL)n);
			tmp = abs(i%a-i%b);
			len = (n-i+c-1)/c;
			LL cc = (n-i)%c;
			if(cc<x-i&&cc)
				ans+=cc*len*tmp+(x-i-cc)*(len-1)*tmp;
			else ans+=tmp*(x-i)*len;
			i = x;
			if(la==lb) break;
			if(i==la) la+=a;
			else lb+=b;
		}
		cout<<ans<<endl;
	}
	return 0;
}
