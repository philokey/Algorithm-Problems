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
const int MAXN = 15;
const int INF = 1111111111;
const double PI = acos(-1.0);
int p[2][MAXN][3];
int main()
{
    //freopen("/home/qitaishui/code/in.txt","r",stdin);
    int cas;
    char str[MAXN];
    scanf("%d",&cas);
    for(int ca = 1; ca<=cas; ca++)
    {
        for(int k = 0; k < 2; k++)
            for(int i = 0; i < 11; i++)
                for(int j = 0; j < 3; j++)
                {
                   scanf("%s",str);
                   p[k][i][j] = (str[0]=='y');
                }
        int home,away;
        int flag = -1;
        home = away = 0;
        for(int i = 0; i < 5; i++)
        {
            home+=p[0][i][0];
            if(home>away+5-i)
            {
                flag = 0;
                break;
            }
            else if(home+4-i<away)
            {
                flag = 1;
                break;
            }
            away+=p[1][i][0];
            if(home>away+4-i)
            {
                flag = 0;
                break;
            }
            else if(home+4-i<away)
            {
                flag = 1;
                break;
            }
        }
        int t = 0;
        for(int i = 5; flag<0;i++)
        {
            if(i==11){i = 0;t++;}
            home+=p[0][i][t];
            away+=p[1][i][t];
            if(home>away)
                flag = 0;
            if(home<away)
                flag = 1;
        }
        printf("Match %d:\nWinner: %s\n",ca,flag?"away":"home");
        printf("Score: %d:%d\n",home,away);
    }
    return 0;
}
