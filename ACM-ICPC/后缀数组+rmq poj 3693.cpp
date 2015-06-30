#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 100005;
int sa[maxn],ranks[maxn],wa[maxn],wb[maxn],wv[maxn],sum[maxn],height[maxn];
int Log[maxn],lc[20][maxn];
bool cmp(int r[],int a,int b,int len)
{
    return r[a]==r[b]&&r[a+len]==r[b+len];
}
void da(int r[],int n,int m)
{
    int *x = wa,*y = wb,i,j,k,p;
    memset(sum,0,sizeof(sum));
    for(i = 0; i < n; i++) sum[x[i]=r[i]]++;
    for(i = 1; i < m; i++) sum[i]+=sum[i-1];
    for(i = n-1; i >=0; i--) sa[--sum[x[i]]] = i;
    for(i = 0,j = 1,p=1; p < n; j*=2,m=p)
    {
        for(i = n-j,p=0; i < n; i++) y[p++]=i;
        for(i = 0; i < n; i++)
            if(sa[i]>=j) y[p++] = sa[i] - j;
        memset(sum,0,sizeof(sum));
        for(i = 0; i < n; i++) wv[i] = x[y[i]];
        for(i = 0; i < n; i++) sum[wv[i]]++;
        for(i = 1; i < m; i++) sum[i]+=sum[i-1];
        for(i = n-1; i >=0; i--) sa[--sum[wv[i]]] = y[i];
        swap(x,y);
        for(i=1,x[sa[0]]=0,p=1; i < n; i++)
            x[sa[i]] = cmp(y,sa[i-1],sa[i],j)? p-1:p++;
    }
}
void calheight(int r[], int n)
{
    int j,k=0;
    for(int i = 1; i <= n; i++)
        ranks[sa[i]] = i;
    for(int i = 0; i < n; height[ranks[i++]]=k)
        for(k?k--:0,j=sa[ranks[i]-1];r[i+k]==r[j+k];k++);
}
void init_rmq(int n)
{
	for(int i = 1; i <= n ; i ++) lc[0][i] = height[i];
	for(int i = 1; i <= Log[n] ; i ++)
		for(int j = 1; j <= n - (1<<i) + 1 ; j ++)
			lc[i][j] = min(lc[i-1][j] , lc[i-1][j+(1<<(i-1))]);

}
int rmq(int a,int b) {
	a = ranks[a],b = ranks[b];
	if(a > b) swap(a,b);
	int t = Log[b-a];
	return min(lc[t][a+1] , lc[t][b - (1<<t) + 1]);
}
vector<int> ans;
int main()
{
	//freopen("in.txt","r",stdin);
	char str[maxn];
	int num[maxn],n,ca = 1,maxr ;
	Log[0] = -1;
	for(int i = 1; i < maxn; i++)
		Log[i] =(i&(i-1))? Log[i-1]: Log[i-1]+1;
	while(scanf("%s",str)&&str[0]!='#')
	{
		n = strlen(str);
		ans.clear();
		for(int i = 0; str[i];i++)
			num[i]=str[i]-'a'+1;
		num[n] = 0;
		da(num,n+1,35);
		calheight(num,n);
		init_rmq(n);
		maxr = -1;
		for(int l = 1; l < n; l++)
		{
			for(int i = 0; i+l<n; i+=l)
			{
				int k=rmq(i,i+l);
                int r = k/l+1;
                int t = i-(l-k%l);
                if(t>=0&&k%l!=0&&rmq(t,t+l)>k) r++;
				if(r > maxr)
				{
					maxr = r;
					ans.clear();
					ans.push_back(l);
				}
				else if(r == maxr)
					ans.push_back(l);
			}
		}
		bool flag = 0;
		int s,t;
		for(int i = 1; i <= n&&!flag; i++)
			for(int j = 0; j < ans.size(); j++)
			{
				int tmp = ans[j];
				if(rmq(sa[i],sa[i]+tmp)>=(maxr-1)*tmp)
				{
					s=sa[i];
                    t=tmp*maxr;
                    flag = 1;
                    break;
				}
			}
		printf("Case %d: ",ca++);
		for(int i = 0; i < t; i++) putchar(str[s+i]);
		printf("\n");
	}
	return 0;
}
