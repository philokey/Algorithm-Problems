#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;

vector<long long> pr;
int find(long long n)
{
    pr.clear();
    for(long long i = 2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            pr.push_back(i);
            while(n%i==0) n/=i;
        }
    }
    if(n>1) pr.push_back(n);
}
long long solve(long long x){

    int num = pr.size(),cnt;
    long long tmp,ret;
    ret = x;
    for(int i = 1; i <(1<<num);i++)
    {
        cnt = 0;
        tmp = 1;
        for(int j = 0; j < num; j++)
        {
            if(i&(1<<j))
            {
                cnt++;
                tmp *= pr[j];
            }
        }
        if(cnt&1) ret-=x/tmp;
        else ret+=x/tmp;
    }
    return ret;

}

int main(){

    freopen("in.txt","r",stdin);

    long long a,b,n;
    int cas;
    cin>>cas;
    for(int ca = 1; ca <= cas; ca++)
    {
        cin>>a>>b>>n;
        find(n);
        cout<<"Case #"<<ca<<": "<<solve(b)-solve(a-1)<<"\n";
    }
    return 0;
}
