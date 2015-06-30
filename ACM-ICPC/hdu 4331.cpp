#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <map>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const int MAXN = 10005;
const int INF = 1111111111;
char mp[200];
int pai[55];
bool jf;
inline int chg(char str[])
{
	return (str[0]-'0'-1)+mp[str[1]]*9;
}
bool dfs(int dep,int sum)
{
    if(jf) return 1;
	if(sum==12) {jf=1;return 1;}
	bool flag = 0;
	if(!pai[dep]) return dfs(dep+1,sum);
    int i = dep;
    if(pai[i]>=3)
    {
        pai[i]-=3;
        flag|=dfs(i,sum+3);
        pai[i]+=3;
        if(flag) return 1;
    }
    if(i<27&&i%9<=6&&pai[i+1]&&pai[i+2])
    {

        pai[i]--,pai[i+1]--,pai[i+2]--;
        flag|=dfs(i,sum+3);

        pai[i]++,pai[i+1]++,pai[i+2]++;
        if(flag) return 1;
    }

	return flag;
}
bool judge1()
{
	for(int i = 0;i < 34; i++)
	{
	    jf = 0;
		if(pai[i]>=2)
		{
			pai[i]-=2;
			if (dfs(0,0)) {pai[i]+=2;return 1;}
			pai[i]+=2;
		}
	}
	return 0;
}
bool judge2()
{
	int cnt = 0;
	for(int i = 0; i < 34; i++)
		if(pai[i]==2) cnt++;
	return cnt==7;
}
bool judge3()
{
	int s = 27,t = 33;
	bool flag = 1;
	int cnt = 0;
	for(int i = s; i<=t; i++)
	{
		if(!pai[i]) return 0;
		cnt+=pai[i];
	}
	for(int i = 0; i < 3; i++)
	{
		if(!pai[i*9]) return 0;
		cnt+=pai[i*9];
		if(!pai[i*9+8]) return 0;
		cnt+=pai[i*9+8];
	}
	return cnt==14&&flag;

}
int main()
{
	//freopen("F:\\code\\in.txt","r",stdin);
	int ca;
	char str[5];
	mp['m']=0,mp['s']=1,mp['p']=2,mp['c']=3;
	scanf("%d",&ca);
	while(ca--)
	{
		memset(pai,0,sizeof(pai));
		for(int i = 0; i < 13; i++)
		{
			scanf("%s",str);
			pai[chg(str)]++;
		}
		bool flag;
		vector<int>ans;
		ans.clear();
		for(int i = 0; i < 34; i++)
		{
		    if(pai[i]==4) continue;
			flag = 0;
			pai[i]++;
			if(judge2()||judge3()||judge1()) flag=1;
			if(flag) ans.push_back(i);
			pai[i]--;
		}
		if(ans.size()==0)
		{
			printf("Nooten\n");
		}
		else
		{
			printf("%d",ans.size());
			for(int i = 0; i < ans.size(); i++)
			{
				if(ans[i]<9) printf(" %dm",ans[i]%9+1);
				else if(ans[i]<18) printf(" %ds",ans[i]%9+1);
				else if(ans[i]<27) printf(" %dp",ans[i]%9+1);
				else printf(" %dc",ans[i]%9+1);
			}
			printf("\n");
		}
	}
	return 0;
}
