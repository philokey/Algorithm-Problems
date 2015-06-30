//题意：给出每个年级的人数，并规定每个年级班级的人数上限，且班级可以由相邻的两个年级的人组成，人数上限去最小值，问最少要分几个班级
/*
贪心: 先将每个年级可以分的满的班算出，记录余数。
剩余的人从高年级向低年级转（不能从低年级向高年级，因为人数上限是取最低的）。但要防止一个班级有两个以上年级的人，
所以将转下来的人放到同一个班级里面，并减去这个班级的人
*/
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
int lim[]={20,20,20,25,25,30,30};
int num[10];
int main()
{
    //freopen("in.txt","r",stdin);
    int sum,ans;
    while(1)
    {
        sum = ans = 0;
        for(int i = 0; i <= 6; i++)
        {
            scanf("%d",&num[i]);
            sum+=num[i];
        }
        if(sum==0) break;
        for(int i = 6; i >=0; i--)
        {
            ans+=num[i]/lim[i];
            num[i]%=lim[i];
            if(i&&num[i]&&num[i]<lim[i-1])
            {
                num[i-1]+=num[i];
                ans++;
                num[i-1]-=min(num[i-1],lim[i-1]);
            }
            else if(num[i]) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}


