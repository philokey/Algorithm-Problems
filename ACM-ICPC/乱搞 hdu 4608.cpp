#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
using namespace std;
const double EPS = 1e-8;
const int MAXN = 100105;
char str[MAXN];
int main()
{
    //freopen("/home/qitaishui/code/in.txt","r",stdin);
    //freopen("/home/qitaishui/下载/occupy/data/data1.out","w",stdout);
    int cas,sum,can,len;
    scanf("%d",&cas);
    while(cas--)
    {
        sum = can = 0;
        scanf("%s",str);
        len = strlen(str);
        for(int i = 0; str[i]; i++)
        {
            sum+=str[i]-'0';
            if(can<20)
				can=can*10+'9'-str[i];
        }
        int ssum = 10-sum%10;
        if(can<ssum)
        {
            ++len;
            str[0] = '1';
            for(int i = 1; i < len;i++) str[i] = '0';
            str[len]='\0';
            sum = 1;
            ssum = 10-sum%10;
        }
        if(str[len-1]-'0'+ssum<=9)
            str[len-1] =str[len-1]-'0'+ssum+'0';
        else
        {
            int pos = len-2;
            for(; pos>=0&&str[pos]=='9';pos--);
            str[pos]++,sum++;
            for(int i = pos+1; i < len; i++)
            {
                sum-=str[i]-'0';
                str[i]='0';
            }
            //printf("%s***\n",str);
            sum = 10-sum%10;
            for(int i = len-1; i>=0&&sum&&sum!=10;i--)
                while(str[i]<'9'&&sum) sum--,str[i]++;
        }

        printf("%s\n",str);
    }
    return 0;
}
