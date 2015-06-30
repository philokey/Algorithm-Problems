#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#define FI first
#define SE second
using namespace std;
const double EPS = 1e-8;
const int MAXN = 105;
const int INF = 1111111111;
const double PI = acos(-1.0);
char save[][11]={"auto","double","int","struct","break","else","long","switch","case","extern","register","typedef","char","float",
"return","union","continue","for","short","unsigned","const","default","goto","sizeof","while","sogned","bpod","volatile","do","if","static","while"};
set<string> dic,now;
struct Property{
    string str;
    int id;
    Property(){}
    Property(string a,int d):str(a),id(d){}
    void output(){cout<<str<<" "<<id<<"\n";}
}p;
int line,state,word,cha;
void init()
{
    string tmp;
    dic.clear();
    for(int i = 0; i < 32; i++)
        dic.insert(save[i]);
    line = state = word = cha = 0;
}
void judge()
{
    switch(state)
    {
        case 1://数字
        p = (tmp,-1);
        p.output();
        state = 0;
        tmp.clear();
        break;
    case 2://变量名
        if(dic.find(tmp)!=dic.end())//判断关键字
            printf("save -1");
        else
        {
            p = (tmp,-1);
            p.output();
        }

        state = 0;
        tmp.clear();
        break;
    }
}
void solve(char str[])
{
    string tmp;
    for(int i = 0; str[i]; i++)
    {
        if(str[i]==' '||str[i]=='\n')
        {
            switch(state)
            {
            case 0:break;//初始值

            default:
                judge();
                break;
            }
        }
        else if(isdidgit(str[i]))//数字
        {
            switch(state)
            {
            case 0:case 1:
                tmp+=str[i];
                state = 1;
                break;
            case 2:
                tmp+=str[i];
                break;
            default:
                printf("There is a error in row %d, column %d\n",line,i);
                return;
            }
        }
        else if(isalpha(str[i]))
        {
            switch(state)
            {
            case 0:case 2:
                tmp+=str[i];
                state = 2;
                break;
            case 1:
                printf("There is a error in row %d, column %d\n",line,i);
                return;
            }
        }
        if(str[i]=='/')
        {
            judge();
            if(str[i+1]!='/')
            {
                printf("/ -1\n");
            }
            else if(str[i+1]=='/')
            {
                string ts;
                i++;
                while(str[i]!='\n')
                {
                    ts+=str[i];
                    i++
                }
                cout<<"注释为："<<ts<<"\n";
            }
        }
        else if(str[i]=='('||str[i]=='{'||str[i]==')'||str[i]==')')
        {
            switch(state)
            {
            case 0:
                printf("%c -1\n",str[i]);
                break;
            default:
                printf("%c -1\n",str[i]);
                judge();
            }
        }
        else if(str[i]=='>'||str[i]=='<')
        {
            if(str[i+1]=='=')
            {
                printf("relop %d",str[i]=='>');
                i++;
            }
            else printf("relop %d",str[i]=='>'+2);
            printf("%c -1\n",str[i]);
        }
    }
}
int main()
{
    freopen("/home/qitaishui/code/in.txt","r",stdin);
    char str[MAXN];
    init();
    while(gets(str)!=NULL)
    {
        line++;
        cha+=strlen(str);
        solve(str);
    }
    return 0;
}
