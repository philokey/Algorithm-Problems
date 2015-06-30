#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const int MAXN = 1005;
const int INF = 1111111111;
char str[MAXN];
int n,num[MAXN];

int main()
{
	//freopen("/home/qitaishui/code/out.txt","r",stdin);
	//freopen("/home/qitaishui/code/out2.txt","w",stdout);
	while(scanf("%s%d",str,&n)!=EOF)
	{
		int nn = n;
		for(int i = 0; str[i]; i++)
			num[i] = str[i]-'0';
		int m = strlen(str),pos=0,mi=INF,flag,is=0;
		for(int i = 0; i < m&&n>1;)
		{
			mi = INF;
			while(num[i]==0&&i<m) num[i++]=-1,nn++;
			for(int j = 0; j <= n&&i+j<m; j++)
				if(num[i+j]<mi) mi = num[i+j],pos = i+j;
			n = n-(pos-i);
			flag=0;
			for(int j = i; j<pos; j++) num[j]=-1,flag=1;
			if(!flag&&pos==m-1&&n) {num[m-1]=-1,flag=1;break;}
			if(flag) i = pos;
			else i++;
		}
		for(int i = 0; i < pos; i++)
			if(num[i]>0) {is=1;break;}
		if(n==1)
		{
			flag=0;
			for(int i = pos+1; i < m; i++)
				if(num[i-1]>num[i])
				{
					num[i-1]=-1;
					if(i-1==pos&&!is)
						while(num[i]==0&&i<m) num[i++]=-1;
					flag=1;
					break;
				}
			if(!flag) num[m-1]=-1;
		}

		int left = m-nn;
		flag=0;
		for(int i = 0,j=0; i < m&&j<left;i++)
			if((num[i]!=-1&&num[i]!=0)||(num[i]==0&&flag)) printf("%d",num[i]),j++,flag=1;
		if(!flag) printf("0");
		printf("\n");

	}
	return 0;
}
