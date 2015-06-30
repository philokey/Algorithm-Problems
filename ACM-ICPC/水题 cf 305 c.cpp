#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 100005;
const int inf = 1111111111;
map<long long,int> mymap;
int main()
{
    //freopen("in.txt","r",stdin);
    int n,a,bn=0,cnt=0;
    long long ans = 0;
    scanf("%d",&n);
    mymap.clear();
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a);
        for(;mymap.find(a)!=mymap.end();mymap.erase(mymap.find((long long)a)),a++);
        mymap[a]++;
    }
    long long pos = 0;
    for(map<long long,int>::iterator it=mymap.begin(); it!=mymap.end(); it++)
    {
        it->second = it->second%2;
        if(it->second/2)
            mymap[it->first+1]+=it->second/2;
        ans+=it->first-pos;
        if(it->second==0) ans++;
        pos = it->first+1;
    }
    cout<<ans<<endl;
    return 0;
}
