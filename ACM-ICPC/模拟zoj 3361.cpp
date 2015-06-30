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
const int MAXN = 105;
const int INF = 1111111111;
const double PI = acos(-1.0);
struct Person{
    int y,r,ny;
    bool is;
}p[MAXN];
struct Input{
    int col[MAXN],id[MAXN];
    int num;
}match[15];
char str[MAXN];
int change(char str[])
{
    int ret = 0;
    //cout<<str<<"***\n";
    for(int i = 0; str[i]; i++)
        ret = ret*10+str[i]-'0';
    return ret;
}
int main()
{
    //freopen("/home/qitaishui/code/in.txt","r",stdin);
    int t,id;
    while(scanf("%s%d",str,&t)!=EOF)
    {
        memset(match,0,sizeof(match));
        memset(p,0,sizeof(p));
        while(scanf("%s",str)&&str[0]!='E')
        {
            if(str[0]=='M'){scanf("%d",&t);continue;}
            //cout<<str<<endl;
            id = change(str);
            scanf("%s",str);
            int &tmp = match[t].num;
            match[t].col[tmp] = (str[0]=='r');
            match[t].id[tmp] = id;
            tmp++;
        }
        for(int i = 1; i <= 7; i++)
        {
            for(int j = 0; j < MAXN; j++)
            {
                p[j].ny = 0;
                if(p[j].y>=2)
                {
                    p[j].y-=2;
                    p[j].is = 0;
                    printf("%d %d\n",i,j);
                }
                else if(p[j].r)
                {
                    p[j].r--;
                    p[j].is = 0;
                    printf("%d %d\n",i,j);
                }
                else p[j].is = 1;
            }
            for(int j = 0; j < match[i].num; j++)
            {
                int tmp = match[i].id[j];
                if(!p[tmp].is) continue;
                if(match[i].col[j]==1)
                {
                    p[tmp].r++;
                    p[tmp].is = 0;
                }
                else
                {
                    p[tmp].ny++;
                    p[tmp].y++;
                    if(p[tmp].ny==2)
                    {
                        p[tmp].ny=0;p[tmp].y-=2;
                        p[tmp].r++;p[tmp].is = 0;
                    }
                }
            }
            if(i==5)
            {
                for(int j = 0; j < MAXN; j++)
                    if(p[j].y==1)
                        p[j].y = 0;
            }
        }
        printf("#\n");
    }
    return 0;
}
