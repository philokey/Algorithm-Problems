#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#define FI first
#define SE second
#define MP make_pair
using namespace std;
const double EPS = 1e-8;
const int MAXN = 1000055;
const int MOD = 1000000007;
const double PI = acos(-1.0);
typedef long long LL;
char str[MAXN],eq[MAXN];
int en;
void change()
{
    stack<char> sta;
    en = 0;
    for(int i = 0; str[i]; i++)
    {
        if(str[i]=='x')
        {
            i++;
            while(str[i]&&str[i]>='0'&&str[i]<='9') i++;
            eq[en++] = 'x';
            i--;
        }
        else if(str[i] == '(') sta.push(str[i]);
        else if(str[i] == ')')
        {
            while(sta.top()!='(')
            {
                eq[en++] = sta.top();
                sta.pop();
            }
            sta.pop();
        }
        else if(str[i] == '|')
        {
            while(sta.size()&&(sta.top()=='~'||sta.top()=='&'||sta.top()=='|'))
            {
                eq[en++] = sta.top();
                sta.pop();
            }
            sta.push(str[i]);
        }
        else if(str[i] == '&')
        {
            while(sta.size()&&(sta.top()=='~'||sta.top()=='&'))
            {
                eq[en++] = sta.top();
                sta.pop();
            }
            sta.push(str[i]);
        }
        else if(str[i] == '~')
            sta.push(str[i]);
    }
    while(sta.size())
    {
        eq[en++] = sta.top();
        sta.pop();
    }
    eq[en] = '\0';
}
LL solve()
{
   stack<pair<LL,LL> > sta;
   pair<LL,LL> s1,s2,ts;
   for(int i = 0; eq[i]; i++)
   {
       if(eq[i] == 'x') sta.push(MP(1,1));
       else if(eq[i]=='~')
       {
           s1 = sta.top();
           sta.pop();
           swap(s1.FI,s1.SE);
           sta.push(s1);
       }
       else if(eq[i] == '|')
       {
           s1 = sta.top(),sta.pop();
           s2 = sta.top(),sta.pop();
           ts.FI = (s1.FI*s2.FI)%MOD;
           ts.SE = (s1.FI*s2.SE+s1.SE*s2.FI+s1.SE*s2.SE)%MOD;
           sta.push(ts);
       }
       else if(eq[i] == '&')
       {
           s1 = sta.top(),sta.pop();
           s2 = sta.top(),sta.pop();
           ts.FI = (s1.FI*s2.SE+s1.SE*s2.FI+s1.FI*s2.FI)%MOD;
           ts.SE = (s1.SE*s2.SE)%MOD;
           sta.push(ts);
       }
   }
   ts = sta.top();
   return sta.top().SE;
}
int main()
{
    //freopen("/home/qitaishui/code/in.txt","r",stdin);
    while(scanf("%s",str)!=EOF)
    {
        change();
        cout<<solve()<<"\n";
    }
    return 0;
}
