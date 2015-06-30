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
const int MAXN = 1000005;
const int INF = 1111111111;
char a[MAXN],b[MAXN],ans[MAXN],ta[MAXN];
int ca[15],cb[15];
void solve(int len)
{
	int pos = 1;
	for(int i = 9; i >=0; i--)
		for(int j = 9; j>=0; j--)
		{
			int x = (i-j+10)%10;
			while(ca[j]&&cb[x])
			{
				--ca[j],--cb[x];
				ta[pos++] = i+'0';
			}
		}
	ta[pos] = '\0';
}
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	int cas,x;
	scanf("%d",&cas);
	memset(ca,0,sizeof(ca));
	memset(cb,0,sizeof(cb));
	for(int hh = 1; hh<=cas; hh++)
	{
		scanf("%s%s",a,b);
		printf("Case #%d: ",hh);
		if(strlen(a)==1)
		{
			printf("%d\n",(a[0]-'0'+b[0]-'0')%10);
			continue;
		}
		for(int i = 0; a[i]; i++)
			ca[a[i]-'0']++,cb[b[i]-'0']++;
		for(int i = 9; i>=0; i--)
		{
			bool flag=0;
			for(int j = 9; j>=0&&!flag; j--)
			{
				x = (i-j+10)%10;
				if(j&&x&&ca[j]&&cb[x])
					flag = 1;
				if(flag)
				{
					ans[0] = '\0';
					for(int j = 9; j>=0; j--)
					{
						x = (i-j+10)%10;
						if(j&&x&&ca[j]&&cb[x])
						{
							memcpy(ta,ans,sizeof(ans));
							--ca[j],--cb[x];
							ta[0] = i+'0';
							solve(strlen(a)-1);
							if(strcmp(ans,ta)<0) strcpy(ans,ta);
						}
					}
					break;
				}
			}
		}
		bool flag = 0;
		int pos = 0;

		while(ans[pos]=='0') pos++;
		for(; ans[pos];pos++)
		{
			printf("%c",ans[pos]);
			flag = 1;
		}
		if(!flag) printf("0");
		printf("\n");
	}
	return 0;
}
