/*题意：给出若干正方形,要求必须一个顶点靠上X轴，并且该顶点锁对应的2条边必须和X轴成45度
正方形按照顺序方(可以理解为塞……)，必须保证B(i+1) > B(i)，问最终从上方向下看，可以看到几个正方形
解法：使用的技巧是*根号2扩大数据，避免无理数，变成整数计算。
找正方形位置的方法是：枚举正方形和前面的每个正方形贴着，x的最大值即为最终位置（应为不能重叠）
然后找出没有被完全覆盖的线段有几条
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 105;
const int inf = 1111111111;
struct Line{
    int l,r,len;
    int lx,rx;
}line[maxn];
vector<int> ans;
int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    while(scanf("%d",&n)&&n)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&line[i].len);
            line[i].l = 0;
            for(int j = 0; j < i; j++)
                line[i].l = max(line[i].l,line[j].r-abs(line[i].len-line[j].len));
            line[i].r = line[i].l+2*line[i].len;
        }
        for(int i = 0; i < n ; i++)
        {
            line[i].lx=line[i].l;
            line[i].rx = line[i].r;
            for(int j = 0; j < n; j++)
            {
                if(j>i) line[i].rx = min(line[i].rx,line[j].l);
                if(j<i) line[i].lx = max(line[i].lx,line[j].r);
            }
        }
        ans.clear();
        for(int i = 0; i < n ; i++)
            if(line[i].lx<line[i].rx) ans.push_back(i+1);
        for(int i = 0; i < ans.size() ; i++)
            if(i==0) printf("%d",ans[i]);
            else printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}


