/*
���⣺��һ��ʮ���Ƶ�����װ����phi���Ƶ�����
�ⷨ��������ʱ��̫����û�з���ʮ���������Ե���һ��phi��������������Լ���ڡ���������֪������Ϊһ��ʮ���Ƶ����϶����Ա�ʾ��n*(phi^0),������Ȼ���Ի����һ���淶��phi��������
������Ŀ�и����Ĺ�ʽ��hint���Եõ��������õĹ�ʽ��
phi^(n) = phi^(n-1)+phi^(n-2)
2*(phi^n) = phi^(n+1)+phi^(n-2)
���Լ����phi^100Զ����10^9�������Ʋ����õ���phi���Ƶ���������С������Ӧ�ò��ᳬ��100λ����ʵ������50λ���ܹ���
�������ձ���˼򵥵�ģ�⡣
����Ϊʲô��������ʱ��ʲô���벻���أ�����
*/
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
const int MAXN = 205;

int main()
{
    //freopen("F:\\code\\in.txt","r",stdin);
    int a[MAXN],n,bas=100;
    bool flag;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        a[50] = n;
        flag = 1;
        while(flag)
        {
            flag = 0;
            for(int i = 2; i < 100; i++)
            {
                if(a[i]>1)
                {
                    a[i-2]+=a[i]/2;
                    a[i+1]+=a[i]/2;
                    a[i]%=2;
                    flag = 1;
                }
            }
            for(int i = 0; i<100;i++)
            {
                if(a[i]&&a[i+1])
                {
                    int tmp = min(a[i],a[i+1]);
                    a[i+2]+=tmp;
                    a[i]-=tmp;
                    a[i+1]-=tmp;
                    flag = 1;
                }
            }
        }
        int st,ed;
        for(int i = 100; i >= 0; i--)
            if(a[i])
            {
                st = i;
                break;
            }
        for(int i = 0; i < 100; i++)
            if(a[i])
            {
                ed = i;
                break;
            }
        for(int i = st; i >= ed; i--)
        {
            if(i==49) printf(".");
            printf("%d",a[i]);
        }
        printf("\n");
    }
    return 0;
}
