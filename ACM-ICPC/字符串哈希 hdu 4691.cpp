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
const int MAXN = 100005;
const int INF = 1111111111;
char str[MAXN];
LL p[MAXN],ha[MAXN];
int get(int x)
{
	if(x==0) return 1;
	int ret=0;
	while(x)
	{
		x/=10;
		ret++;
	}
	return ret;
}
LL cal(int l,int r)
{
	if (!l) return ha[r];
	return ha[r]-ha[l-1]*p[r-l+1];
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n;
	int s1,s2,t1,t2,l,r,m,len,an;
	LL ans1,ans2;
	p[0] = 1;
	for(int i = 1; i < MAXN; i++) p[i] = p[i-1]*131;
	while(scanf("%s",str)!=EOF)
	{
		ha[0] = str[0];
		len = strlen(str);
		for(int i = 1; str[i]; i++) ha[i] = ha[i-1]*131+str[i];
		scanf("%d",&n);
		ans1 = n,ans2 = n*2;
		scanf("%d%d",&s1,&t1);
		ans1+=t1-s1,ans2+=1+t1-s1;
		for(int i = 1; i < n; i++)
		{
			scanf("%d%d",&s2,&t2);
			ans1+=t2-s2;
			l = 0, r = min(t1-s1,t2-s2)-1,an=0;
			while(l <= r)
			{
				int m = (l+r)/2;
				if(cal(s1,s1+m)!=cal(s2,s2+m)) r = m-1;
				else an = m+1,l = m+1;

			}
			ans2+=get(an)+(t2-s2-an);
			s1 = s2, t1 = t2;
		}
		cout<<ans1<<" "<<ans2<<"\n";
	}
	return 0;
}
