#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
const double eps = 1e-8;
const int maxn = 505;
int sa[maxn],height[maxn],rank[maxn],wa[maxn],wb[maxn],wv[maxn],sum[maxn];
bool cmp(int *r,int a,int b,int len)
{
	return r[a]==r[b]&&r[a+len]==r[b+len];
}
void da(int *r,int n, int m)
{
	int i,j,p,*x=wa,*y=wb;
	memset(sum,0,sizeof(sum));
	for(i = 0; i < n; i++) sum[x[i]=r[i]]++;
	for(i = 1; i < m; i++) sum[i]+=sum[i-1];
	for(i = n-1; i >=0; i--) sa[--sum[x[i]]] = i;
	for(i = 0, j = 1, p = 1; p < n; j*=2,m=p)
	{
		for(i = n-j,p=0; i < n; i++) y[p++]=i;
		for(i = 0; i < n; i++)
			if(sa[i]>=j) y[p++]=sa[i]-j;
		memset(sum,0,sizeof(sum));
		for(i = 0; i < n; i++) wv[i] = x[y[i]];
		for(i = 0; i < n; i++) sum[wv[i]]++;
		for(i = 1; i < n; i++) sum[i]+=sum[i-1];
		for(i = n-1; i >=0;i--) sa[--sum[wv[i]]] = y[i];
		swap(x,y);
		for(i = 1,x[sa[0]]=0,p=1; i < n; i++)
			x[sa[i]] = cmp(y,sa[i],sa[i-1],j)?p-1:p++;
	}
}
void calheight(int *r,int n)
{
	int j,k=0;
	for(int i = 1; i <= n; i++)
		rank[sa[i]] = i;
	for(int i = 0; i < n; height[rank[i++]] = k)
		for(k?k--:0,j = sa[rank[i]-1];r[i+k]==r[j+k];k++);
}
int main()
{
	freopen("in.txt","r",stdin);
	return 0;
}
