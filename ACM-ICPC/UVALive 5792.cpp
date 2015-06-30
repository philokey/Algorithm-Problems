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
const int MAXN = 300005;
const int INF = 1111111111;
char str[MAXN];
struct Trie{
	int cnt,sum[MAXN],tree[MAXN][26];
	void init()
	{
		memset(sum,0,sizeof(sum));
		cnt = 0;
		memset(tree[0],0,sizeof(tree[0]));
	}
	void insert(char s[])
	{
		int p = 0,x;
		for(int i = 0; str[i]; i++)
		{
			x = str[i]-'a';
			if(!tree[p][x])
			{
				tree[p][x] = cnt;
				memset(tree[cnt],0,sizeof(tree[cnt]));
				if(i) sum[x]++;
			}
			p = tree[p][x];
		}
	}

}t1,t2;
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int n,m;

	while(scanf("%d%d",&n,&m)&&(n+m))
	{
		t1.init();
		t2.init();
		for(int i = 0; i < n ;i++)
		{
			scanf("%s",str);
			t1.insert(str);
		}
		for(int i = 0; i < m ;i++)
		{
			scanf("%s",str);
			reverse(str,str+strlen(str));
			t2.insert(str);
		}
		long long ans = (long long)t1.cnt*t2.cnt;
		for(int i = 0; i < 26;i++)
			ans-=t1.sum[i]*t2.sum[i];
		cout<<ans<<endl;
	}
	return 0;
}
