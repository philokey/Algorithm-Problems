#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
const int maxn = 7505;
set<int> st;
vector<int> ans[maxn];
int main()
{
	//freopen("in.txt","r",stdin);
	int a[maxn],n,ind[maxn]={0};
	n = 0;
	while(scanf("%d",&a[n])!=EOF)
	{
		ind[a[n]]++;
		++n;
	}

	for(int i = 1; i <= n+1; i++)
		if(ind[i]==0) st.insert(i);
	for(int i = 0; i < n; i++)
	{
		ans[a[i]].push_back(*st.begin());
		ans[*st.begin()].push_back(a[i]);
		st.erase(st.begin());
		--ind[a[i]];
		if(ind[a[i]]==0) st.insert(a[i]);
	}
	for(int i = 1; i <= n+1; i++)
	{
		sort(ans[i].begin(),ans[i].end());
		printf("%d:",i);
		for(int j = 0; j < ans[i].size(); j++)
			printf(" %d",ans[i][j]);
		printf("\n");
	}
	return 0;
}
