#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=100005;//靠,数组又开小!
int main()
{
	pair<int,int> w[maxn],b[maxn];
	int n,wn,bn,tp,u;
	wn=bn=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&tp,&u);
		if(tp==1) w[wn++]=make_pair(u,i);
		else b[bn++]=make_pair(u,i);
	}
	for(int i=0,j=0;i<wn&&j<bn;)
	{
		int tmp=min(w[i].first,b[j].first);
		w[i].first-=tmp;
		b[j].first-=tmp;
		printf("%d %d %d\n",w[i].second,b[j].second,tmp);
		if(i==wn-1) j++;
		else if(j==bn-1)	i++;
		else if(w[i].first==0)	i++;
		else j++;
	}
	return 0;
}